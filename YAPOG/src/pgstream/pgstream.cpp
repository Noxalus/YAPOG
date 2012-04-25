/*
  pgstream.cpp: main file for the pgstream library.
  Copyright (c) 2004-2012, Daniel Verite.
  See COPYING file for license terms.
  http://www.manitou-mail.org/pgstream
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#ifdef _MSC_VER
#define sprintf sprintf_s
#define snprintf _snprintf
#pragma warning( push)
#pragma warning( disable : 4996 )
#endif

#include "pgstream/pgstream.hpp"

//static
const char* sql_bind_param::m_type_names[] = {
  "bigint",
  "bool",
  "bytea",
  "int",
  "numeric",
  "smallint",
  "text",
  "varchar"  
};

//static
int sql_bind_param::m_oids[] = {
  oid_int8,
  oid_bool,
  oid_bytea,
  oid_int4,
  oid_numeric,
  oid_int2,
  oid_text,
  oid_varchar
};

void
sql_bind_param::set_type(const char* t)
{
  const int arrsz=sizeof(m_type_names)/sizeof(m_type_names[0]);
  for (int i=0; i<arrsz; i++) {
    if (!strcmp(t, m_type_names[i])) {
      m_type_oid=m_oids[i];
      m_type_name=t;
      return;
    }
  }
  throw pg_excpt("pgstream", "Unknown variable type");
}

void
sql_bind_param::set_type(enum type_oid o)
{
  // the type the user has explictly set has precedence
  // FIXME: express this differently
  if (!m_type_name.empty())
    return;

  m_type_oid=o;
  switch(o) {
  case oid_int2:
    m_type_name="smallint";
    break;
  case oid_int4:
    m_type_name="int";
    break;
  case oid_int8:
    m_type_name="bigint";
    break;
  case oid_text:
    m_type_name="text";
    break;
  case oid_varchar:
    m_type_name="varchar";
    break;
  case oid_numeric:
    m_type_name="numeric";
    break;
  case oid_bool:
    m_type_name="bool";
    break;
  case oid_bytea:
    m_type_name="bytea";
    break;
  default:
    throw pg_excpt("pgstream", "Unknown oid type");
  }
}

pg_stream::pg_stream(const std::string query, pg_cnx& db, int prepare_mode) :
  m_db(db)
{
  init(query.c_str(), prepare_mode, 0);
}

pg_stream::pg_stream(const char *query, pg_cnx& db, int prepare_mode) :
  m_db(db)
{
  init(query, prepare_mode, 0);
}

void
pg_stream::init(const char *query, int prepare_mode, unsigned int cursor_step)
{
  m_inline_params = m_db.m_inline_params;
  if (prepare_mode==2)
    m_prepare_wanted = m_db.m_default_prepare;
  else
    m_prepare_wanted = (prepare_mode==1)?true:false;

  m_argpos = 0;
  m_query_buf = m_localQueryBuf;
  m_query_bufsize = sizeof(m_localQueryBuf)-1;
  m_query_fmt = query;
  m_chunk_size = 1024;
  m_executed = false;
  m_pg_res = NULL;
  m_cursor_step = cursor_step;

  int len = strlen(query);
  if (len > m_query_bufsize)
    query_make_space(len);

  m_query_len = m_initial_query_len = len;
  strcpy(m_query_buf, query);

  const char* q=query;
  int in_quotespl=0;
  while (*q) {
    switch(*q) {
    case '\'':
      in_quotespl = !in_quotespl;
      q++;
      break;
    case '\\':
      q++;
      if (in_quotespl && *q=='\'') {
	// skip the quoted simple quote
	q++;
      }
      break;
    case ':':
      q++;
      if (!in_quotespl) {
	if (*q==':') {		// :: is reserved for casting
	  q++;
	  break;
	}
	const char* start_var=q;
	while (isalnum(*q)) q++;
	std::string vtype;
	if (*q=='<') {
	  // explicit type
	  const char* start_type=++q;
	  while (isalnum(*q)) q++;
	  if (*q=='>') {
	    vtype.assign(start_type, q-start_type);
	    q++;
	  }
	  else {
	    throw pg_excpt("pg_stream", "syntax error in bind parameter");
	  }
	}
	sql_bind_param p(std::string(start_var,q-start_var), (start_var-1)-query);
	if (!vtype.empty()) {
	  p.set_type(vtype.c_str());
	}
	m_vars.push_back(p);
      }
      break;
    default:
      q++;
      break;
    }
  }

  if (m_vars.empty())
    execute();
}

pg_stream::~pg_stream()
{
  if (!m_prepare_name.empty()) {
    std::string q = std::string("DEALLOCATE ")+m_prepare_name;
    PGresult* res = PQexec(m_db.conn(), q.c_str());
    if (res) PQclear(res);
  }
  if (!m_cursor_name.empty()) {
    std::string q = std::string("CLOSE ")+m_cursor_name;
    PGresult* res = PQexec(m_db.conn(), q.c_str());
    if (res) PQclear(res);
  }
  if (m_pg_res)
    PQclear(m_pg_res);
  if (m_query_buf!=m_localQueryBuf)
    free(m_query_buf);
}

int
pg_stream::m_uniq_cnt=0;

void
pg_stream::do_prepare()
{
  char buf[9];
  sprintf(buf, "%x", ++m_uniq_cnt);
  m_prepare_name = std::string("pgst_prep_") + buf;
  std::string args;
  std::vector<sql_bind_param>::iterator it = m_vars.begin();
  for (; it != m_vars.end(); ++it) {
    if (!args.empty())
      args.append(1,',');
#if 0
    if (it->null()) {
      args += "int4";		// hack (FIXME)
    }
    else
#endif
      args += it->type_name();
  }
  if (!args.empty())
    args = std::string("(") + args + ")";
  std::string q = std::string("PREPARE  ") + 
    m_prepare_name + args + std::string(" AS ") + m_query_buf;
  PGresult* r = PQexec(m_db.conn(), q.c_str());
  if (!r || PQresultStatus(r) != PGRES_COMMAND_OK) {
    m_prepare_name.clear();
    throw pg_excpt::mk_excpt(r, q.c_str());
  }
}

void
pg_stream::create_cursor()
{
  char buf[9];
  sprintf(buf, "%08x", m_uniq_cnt++);
  m_cursor_name = std::string("pgst_cur_") + buf;
  std::string q = std::string("DECLARE ") + 
    m_cursor_name + std::string(" CURSOR FOR ") + m_query_buf;
  PGresult* r = PQexec(m_db.conn(), q.c_str());
  if (!r || PQresultStatus(r) != PGRES_COMMAND_OK) {
    m_cursor_name.clear();
    throw pg_excpt::mk_excpt(r, q.c_str());
  }
}

void
pg_stream::reset_results()
{
  m_executed=false;
  m_argpos=0;
  if (m_pg_res) {
    PQclear(m_pg_res);
    m_pg_res=NULL;
  }
  strcpy(m_query_buf, m_query_fmt.c_str());
  unsigned int i, s=m_vars.size();
  for (i=0; i<s; i++) {
    m_vars[i].reset_offset();
  }
  m_query_len=m_initial_query_len;
}

void
pg_stream::query_make_space(int len)
{
  if (m_query_len+len < m_query_bufsize)
    return;			// m_query_buf is big enough
  if (m_query_buf==m_localQueryBuf) {
    char* p=(char*)malloc(1+m_query_bufsize+len+m_chunk_size);
    if (p) {
      strcpy (p, m_query_buf);
      m_query_buf = p;
    }
  }
  else {
    m_query_buf=(char*)realloc(m_query_buf, 1+m_query_bufsize+len+m_chunk_size);
  }
  if (!m_query_buf)
    throw pg_excpt("pg_stream", "not enough memory");
  m_query_bufsize += len+m_chunk_size;
  m_chunk_size = m_chunk_size*2;	// grow exponentially
}

/*
  Replace a placeholder inside the query buffer, either by a value if
  m_inline_params is true, or by a $N PQExecParams-compatible
  placeholder.
  - argpos is the number of the placeholder (start at 0)
  - buf points to the ascii value
  - size is the value's length or -1 to indicate the sql NULL value
  - binary is true if buf contains binary data (for a bytea column)
*/
void
pg_stream::replace_placeholder(unsigned int argpos, const char* buf, int size, bool binary)
{
  sql_bind_param& p=m_vars[argpos];
  if (size>=0) {
    if (!binary)
      p.set_value(buf);
    else
      p.set_binary_data(buf,size);
  }
  else {
    p.set_null();
  }
  char bind_num_buf[4];  // a $ followed by up to 3 digits

  if (!m_inline_params) {
    if (argpos>=999)
      throw pg_excpt("pg_stream", "too many bind variables (max:999)");
    sprintf(bind_num_buf, "$%u", argpos+1);
    buf = bind_num_buf;
    size = strlen(bind_num_buf);
  }

  if (size>0)
    query_make_space(size);

  // Replace the placeholder with the value or the $N variable
  int placeholder_len=p.name().size()+1; // +1 for the leading ':'
  // shift the substring at the right of the placeholder
  memmove(m_query_buf+p.pos()+size,
	  m_query_buf+p.pos()+placeholder_len,
	  m_query_len-(p.pos()+placeholder_len));
  // insert the value where the placeholder was
  memcpy(m_query_buf+p.pos(), buf, size);
  m_query_len+=(size-placeholder_len);
  m_query_buf[m_query_len]='\0';
  // change the offsets of the remaining placeholders
  for (unsigned int i=argpos+1; i<m_vars.size(); i++) {
    m_vars[i].offset(size-placeholder_len);
  }
}

void
pg_stream::next_bind()
{
  if (++m_argpos>=m_vars.size()) {
    execute();
  }
}

pg_stream&
pg_stream::operator<<(const char* p)
{
  check_binds();
  m_vars[m_argpos].set_type(sql_bind_param::oid_varchar);

  if (!m_inline_params) {
    if (p)
      replace_placeholder(m_argpos, p, strlen(p));
    else
      replace_placeholder(m_argpos, "null", -1);
  }
  else {
    if (p) {
      size_t len = strlen(p);
      /* We use a buffer on stack to store the quoted version of the
	 string parameter if it fits, else we'll allocate the space on the
	 heap. Hopefully it will fit most of times and we'll avoid the malloc
	 overhead  */
      char local_buf[1024+2+1];	// space for 1024 chars + 2 quotes + 1 '\0'
      char* buf;
      if (len < (sizeof(local_buf)-1)/2)
	buf=local_buf;
      else
	buf=(char*)malloc(2+2*len+1);
      int escaped_size=PQescapeString(buf+1, p, len);
      buf[0]='\'';
      buf[escaped_size+1]='\'';
      buf[escaped_size+2]='\0';

      replace_placeholder(m_argpos, buf, escaped_size+2);

      if (buf!=local_buf)
	free(buf);
    }
    else {
      // null pointer => null sql value
      replace_placeholder(m_argpos, "null", 4);
    }
  }
  next_bind();
  return *this;
}

pg_stream&
pg_stream::operator<<(const std::string& s)
{
  return operator<<(s.c_str());
}

pg_stream&
pg_stream::operator<<(int i)
{
  check_binds();
  char buf[15];
  if (i>=0) {
    sprintf(buf,"%d", i);
  }
  else {
    // parenthesis are put around the negative value to avoid a double
    // dash (a comment) in case the character just before is a dash
    sprintf(buf,"(%d)", i);
  }
  m_vars[m_argpos].set_type(sql_bind_param::oid_int4);
  replace_placeholder(m_argpos, buf, strlen(buf));
  next_bind();
  return *this;
}

pg_stream&
pg_stream::operator<<(unsigned int i)
{
  check_binds();
  char buf[15];
  sprintf(buf,"%u", i);
  m_vars[m_argpos].set_type(sql_bind_param::oid_int4);
  replace_placeholder(m_argpos, buf, strlen(buf));
  next_bind();
  return *this;
}

pg_stream&
pg_stream::operator<<(long l)
{
  check_binds();
  char buf[15];
  if (l>=0) {
    sprintf(buf,"%ld", l);
  }
  else {
    // parenthesis are put around the negative value to avoid a double
    // dash (a comment) in case the character just before is a dash
    sprintf(buf,"(%ld)", l);
  }
  m_vars[m_argpos].set_type(sql_bind_param::oid_int4);
  replace_placeholder(m_argpos, buf, strlen(buf));
  next_bind();
  return *this;
}

pg_stream&
pg_stream::operator<<(unsigned long l)
{
  check_binds();
  char buf[15];
  sprintf(buf,"%lu", l);
  m_vars[m_argpos].set_type(sql_bind_param::oid_int4);
  replace_placeholder(m_argpos, buf, strlen(buf));
  next_bind();
  return *this;
}

pg_stream&
pg_stream::operator<<(long long l)
{
  check_binds();
  char buf[30];
  if (l>=0) {
    sprintf(buf,"%lld", l);
  }
  else {
    // parenthesis are put around the negative value to avoid a double
    // dash (a comment) in case the character just before is a dash
    sprintf(buf,"(%lld)", l);
  }
  m_vars[m_argpos].set_type(sql_bind_param::oid_int8);
  replace_placeholder(m_argpos, buf, strlen(buf));
  next_bind();
  return *this;
}

pg_stream&
pg_stream::operator<<(unsigned long long l)
{
  check_binds();
  char buf[30];
  sprintf(buf,"%llu", l);
  m_vars[m_argpos].set_type(sql_bind_param::oid_int8);
  replace_placeholder(m_argpos, buf, strlen(buf));
  next_bind();
  return *this;
}

pg_stream&
pg_stream::operator<<(short s)
{
  check_binds();
  char buf[15];
  sprintf(buf,"%hd", s);
  m_vars[m_argpos].set_type(sql_bind_param::oid_int2);
  replace_placeholder(m_argpos, buf, strlen(buf));
  next_bind();
  return *this;
}

pg_stream&
pg_stream::operator<<(unsigned short s)
{
  check_binds();
  char buf[15];
  sprintf(buf,"%hu", s);
  m_vars[m_argpos].set_type(sql_bind_param::oid_int2);
  replace_placeholder(m_argpos, buf, strlen(buf));
  next_bind();
  return *this;
}

pg_stream&
pg_stream::operator<<(double d)
{
  check_binds();
  char buf[100];
  snprintf(buf, sizeof(buf), "%g", d);
  m_vars[m_argpos].set_type(sql_bind_param::oid_numeric);
  replace_placeholder(m_argpos, buf, strlen(buf));
  next_bind();
  return *this;
}

pg_stream&
pg_stream::operator<<(bool b)
{
  check_binds();
  const char* buf;
  if (b)
    buf="true";
  else
    buf="false";
  m_vars[m_argpos].set_type(sql_bind_param::oid_bool);
  replace_placeholder(m_argpos, buf, strlen(buf));
  next_bind();
  return *this;
}

pg_bytea::pg_bytea() :
 m_data_ptr(NULL), m_data_len(0), m_allocated(false)
{
}

pg_bytea::pg_bytea(void* ptr, unsigned int len) :
 m_data_ptr(NULL), m_data_len(0), m_allocated(false)
{
  set_src_data(ptr, len);
}

pg_bytea::~pg_bytea()
{
  if (m_allocated && m_data_ptr)
    PQfreemem(m_data_ptr);
}

pg_stream&
pg_stream::operator<<(pg_bytea& b)
{
  check_binds();
  m_vars[m_argpos].set_type(sql_bind_param::oid_bytea);
  if (!m_inline_params) {
    if (b.m_data_ptr)
      replace_placeholder(m_argpos, (const char*)b.m_data_ptr, b.m_data_len, 1);
    else
      replace_placeholder(m_argpos, "null", -1);
  }
  else {
    if (b.m_data_ptr) {
      size_t len = (size_t)b.m_data_len;
      size_t escaped_size;	// includes terminating zero
      unsigned char* buf = PQescapeBytea((const unsigned char*)b.m_data_ptr,
					 len, &escaped_size);

      /* TODO: find a way to avoid doubling the memory allocation
	 (either hack something in replace_placeholder for it to
	 add the single quotes itself, or do our own version
	 of PQescapeBytea) */
      unsigned char* buf1 = (unsigned char*)malloc(escaped_size+2);
      if (!buf1)
	throw pg_excpt("pg_stream", "not enough memory");

      buf1[0]='\'';
      memcpy(buf1+1, buf, escaped_size);
      buf1[escaped_size]='\'';
      buf1[escaped_size+1]='\0';
      PQfreemem(buf);
      replace_placeholder(m_argpos, (const char*)buf1, escaped_size+1);
      free(buf1);
    }
    else {
      // null pointer => null sql value
      replace_placeholder(m_argpos, "null", 4);
    }
  }

  next_bind();
  return *this;
}

pg_stream&
pg_stream::operator<<(sql_null n)
{
  check_binds();
  replace_placeholder(m_argpos, "null", -1);
  next_bind();
  return *this;
}

void
pg_stream::check_binds()
{
  if (m_executed && m_argpos==m_vars.size()) {
    // reset the query for another execution
    reset_results();
  }
  if (m_argpos >= m_vars.size())
    throw pg_excpt("pg_stream", "Mismatch between bound variables and query");
}

#if 0
void
pg_stream::print()		// DEBUG
{
  std::cout << "buf=" << m_query_buf << std::endl;
  std::cout << "len=" << m_query_len << ", bufsize=" << m_query_bufsize << std::endl;
  std::cout << "params\n";
  for (int i=0; i<(int)m_vars.size(); i++) {
    const sql_bind_param& v=m_vars[i];
    std::cout << v.name() << " => pos=" << v.pos() << " value=" << v.value() << "\n";
  }
}
#endif

void
pg_stmt::execute(const char* stmt, pg_cnx& db)
{
  m_res=PQexec(db.conn(), stmt);
  if (!m_res)
    throw pg_excpt(stmt, PQerrorMessage(db.conn()));
  if (PQresultStatus(m_res)!=PGRES_COMMAND_OK) {
    const char *errp = PQresultErrorField(m_res, PG_DIAG_SQLSTATE);
    if (errp)
      throw pg_excpt(stmt, PQresultErrorMessage(m_res), errp);
    else
      throw pg_excpt(stmt, PQresultErrorMessage(m_res));
  }
}

pg_stmt::pg_stmt(const char* stmt, pg_cnx& db)
{
  execute(stmt, db);
}

pg_stmt::pg_stmt(const std::string stmt, pg_cnx& db)
{
  execute(stmt.c_str(), db);
}

pg_stmt::~pg_stmt()
{
  if (m_res)
    PQclear(m_res);
}

void
pg_stream::execute()
{
  if (m_argpos < m_vars.size()) {
    const char fmt[] = "%u variable(s) not bound\n";
    char errbuf[4+sizeof(fmt)];
    sprintf(errbuf, fmt, m_vars.size()-m_argpos);
    throw pg_excpt(m_query_buf, errbuf);
  }

  if (m_cursor_step > 0) {
    create_cursor();
  }

  if (m_prepare_wanted && m_prepare_name.empty()) {
    do_prepare();
  }

  if (!m_inline_params) {
    unsigned int sz=m_vars.size();
    Oid* param_types = (Oid*)alloca(sz*sizeof(Oid));
    const char** param_values = (const char**)alloca(sz*sizeof(const char*));
    int* param_lengths = (int*)alloca(sz*sizeof(int));
    int* param_formats = (int*)alloca(sz*sizeof(int));
    std::vector<sql_bind_param>::iterator it = m_vars.begin();
    unsigned int i=0;
    for (;it != m_vars.end(); ++it, ++i) {
      param_types[i] = it->pg_type();
      if (param_types[i]==(int)sql_bind_param::oid_bytea) {	// binary
	param_formats[i] = 1;
	if (!it->null()) {
	  param_values[i] = (const char*)it->data_ptr();
	  param_lengths[i] = it->data_size();
	}
	else {
	  param_values[i] = NULL;
	  param_lengths[i] = 0;
	}
      }
      else { 	// text
	param_formats[i] = 0;
	if (!it->null()) {
	  param_lengths[i] = it->value().length();
	  param_values[i] = it->value().c_str();
	}
	else {
	  param_values[i] = NULL;
	  param_lengths[i] = 0;
	}
      }
    }
    if (m_prepare_name.empty()) {
      m_pg_res = PQexecParams(m_db.conn(), m_query_buf, sz, param_types,
			     param_values, param_lengths, param_formats,
			     0);	// output in text format
    }
    else {
      m_pg_res = PQexecPrepared(m_db.conn(), m_prepare_name.c_str(),
			       sz, param_values, param_lengths,
			       param_formats,
			       0);	// output in text format
    }
  }
  else {
    if (m_cursor_step > 0)
      cursor_fetch();
    else
      m_pg_res=PQexec(m_db.conn(), m_query_buf);
  }
  if (!m_pg_res)
    throw pg_excpt(m_query_buf, PQerrorMessage(m_db.conn()));
  if (PQresultStatus(m_pg_res)!=PGRES_TUPLES_OK &&
      PQresultStatus(m_pg_res)!=PGRES_COMMAND_OK) {
    const char *errp = PQresultErrorField(m_pg_res, PG_DIAG_SQLSTATE);
    if (errp)
      throw pg_excpt(m_query_buf, PQresultErrorMessage(m_pg_res), errp);
    else
      throw pg_excpt(m_query_buf, PQresultErrorMessage(m_pg_res));
  }
  const char* t=PQcmdTuples(m_pg_res);
  if (t && *t) {
    m_affected_rows=atoi(t);
  }
  else
    m_affected_rows=0;

  m_row_number=0;
  m_col_number=0;
  m_executed=true;
}

void
pg_stream::cursor_fetch()
{
  char nb[10];
  sprintf(nb, "%u", m_cursor_step);
  std::string fetch = std::string("FETCH ") + nb + " FROM " + m_cursor_name;
  if (m_pg_res){
    PQclear(m_pg_res);
    m_pg_res=NULL;
  }
  m_pg_res = PQexec(m_db.conn(), fetch.c_str());
  if (!m_pg_res || PQresultStatus(m_pg_res)!=PGRES_TUPLES_OK) {
    // mk_excpt will free the contents of m_pg_res so we need
    // to zero it at this point.
    PGresult* res = m_pg_res;
    m_pg_res=NULL;
    throw pg_excpt::mk_excpt(res, fetch.c_str());
  }
  m_row_number=0;
}

int
pg_stream::eof()
{
  if (!m_executed)
    execute();
  if (m_row_number < PQntuples(m_pg_res))
    return false;
  else {
    if (m_cursor_step > 0) {
      cursor_fetch();
      return m_row_number >= PQntuples(m_pg_res);
    }
    else {
      return true;
    }
  }
}

void
pg_stream::next_result()
{
  m_col_number=((m_col_number+1)%PQnfields(m_pg_res));
  if (m_col_number==0)
    m_row_number++;
}

bool
pg_stream::check_null()
{
  m_val_null = PQgetisnull(m_pg_res, m_row_number, m_col_number)?true:false;
  return m_val_null;
}

void
pg_stream::check_eof()
{
  if (eof())
    throw pg_excpt(m_query_buf, "End of stream reached");
}

pg_stream&
pg_stream::operator>>(pg_bytea& b)
{
  check_eof();
  if (PQftype(m_pg_res, m_col_number) != 17)
    throw pg_excpt("pgstream", "Type mismatch: bytea type expected");
  m_val_null = PQgetisnull(m_pg_res, m_row_number, m_col_number)?true:false;
  if (!m_val_null) {
    b.m_data_len=PQgetlength(m_pg_res, m_row_number, m_col_number);
    size_t to_len;
    unsigned char* buf = PQunescapeBytea((const unsigned char*)PQgetvalue(m_pg_res, m_row_number, m_col_number), &to_len);
    b.m_data_ptr = buf;
    b.m_data_len = to_len;
    b.m_allocated = true;
  }
  else {
    b.m_data_ptr=NULL;
    b.m_data_len=0;
  }
  next_result();
  return *this;
}

pg_stream&
pg_stream::operator>>(short& s)
{
  check_eof();
  m_val_null = PQgetisnull(m_pg_res, m_row_number, m_col_number)?true:false;
  if (!m_val_null)
    // check for overflow??
    s=atoi(PQgetvalue(m_pg_res, m_row_number, m_col_number));
  else
    s=0;
  next_result();
  return *this;
}

pg_stream&
pg_stream::operator>>(unsigned short& s)
{
  check_eof();
  if (!check_null())
    // check for overflow??
    s=atoi(PQgetvalue(m_pg_res, m_row_number, m_col_number));
  else
    s=0;
  next_result();
  return *this;
}

pg_stream&
pg_stream::operator>>(int& i)
{
  check_eof();
  if (!check_null())
    i=atoi(PQgetvalue(m_pg_res, m_row_number, m_col_number));
  else
    i=0;
  next_result();
  return *this;
}

pg_stream&
pg_stream::operator>>(unsigned int& i)
{
  check_eof();
  unsigned long ul=strtoul(PQgetvalue(m_pg_res, m_row_number, m_col_number),
			   NULL, 10);
  if (!check_null())
    i=(unsigned int)ul;
  else
    i=0;
  next_result();
  return *this;
}

pg_stream&
pg_stream::operator>>(double& d)
{
  check_eof();
  if (!check_null())
    d=atof(PQgetvalue(m_pg_res, m_row_number, m_col_number));
  else
    d=0.0;
  next_result();
  return *this;
}

pg_stream&
pg_stream::operator>>(bool& b)
{
  check_eof();
  if (!check_null()) {
    const char* p=PQgetvalue(m_pg_res, m_row_number, m_col_number);
    if (p && *p=='t')
      b=true;
    else
      b=false;
  }
  else
    b=false;
  next_result();
  return *this;
}

pg_stream&
pg_stream::operator>>(char* p)
{
  check_eof();
  if (check_null())
    *p='\0';
  else {
    // pretty dangerous if the buffer is not big enough, but
    // we have no way of knowing. Better use C++ strings
    strcpy(p, PQgetvalue(m_pg_res, m_row_number, m_col_number));
  }
  next_result();
  return *this;
}

pg_stream&
pg_stream::operator>>(std::string& s)
{
  check_eof();
  s=PQgetvalue(m_pg_res, m_row_number, m_col_number);
  check_null();
  next_result();
  return *this;
}


pg_cnx::pg_cnx(PGconn* cnx) : m_conn(cnx)
{
  m_inline_params=true;
  m_default_prepare=false;
  m_destructor_close = (cnx==NULL);
  m_nested_trans=false;
}


void
pg_cnx::set_option(const char* param, bool bvalue)
{
  if (!strcmp(param, "prepare_statements"))
    m_default_prepare=bvalue;
  else if (!strcmp(param, "bind_variables"))
    m_inline_params=!bvalue;
  else if (!strcmp(param, "nested_transactions"))
    m_nested_trans=bvalue;
  else {
    std::string err=std::string("Unrecognized option passed to pg_cnx::set_option: ")+param;
    throw pg_excpt("pg_cnx", err.c_str());
  }
}

bool
pg_cnx::get_option(const char* param) const
{
  if (!strcmp(param, "prepare_statements"))
    return m_default_prepare;
  else if (!strcmp(param, "bind_variables"))
    return !m_inline_params;
  else if (!strcmp(param, "nested_transactions"))
    return m_nested_trans;
  else {
    std::string err=std::string("Unrecognized option passed to pg_cnx::get_option: ")+param;
    throw pg_excpt("pg_cnx", err.c_str());
  }
}

pg_cnx::~pg_cnx()
{
  if (m_conn) {
    if (m_destructor_close)
      PQfinish(m_conn);
    m_conn=NULL;
  }
}

void
pg_cnx::connect(const char* cnx_string)
{
  if (m_conn)
    PQfinish(m_conn);
  m_conn = PQconnectdb(cnx_string);
  if (!m_conn) {
    throw pg_excpt("pg_cnx", "Unable to allocate a connection");
  }
  if (PQstatus(m_conn) == CONNECTION_BAD) {
    throw pg_excpt("connect", PQerrorMessage(m_conn));
  }
}

pg_trans::pg_trans(pg_cnx& cnx) : m_cnx(cnx), m_trans_done(false)
{
  if (PQtransactionStatus(m_cnx.conn()) != PQTRANS_INTRANS) {
    pg_stmt("BEGIN", m_cnx);
    m_begin=true;
    m_savepoint=false;
  }
  else {
    m_begin=false;
    if (m_cnx.m_nested_trans) {
      pg_stmt("SAVEPOINT pgs_s", m_cnx);
      m_savepoint=true;
    }
    else
      m_savepoint=false;
  }
}

pg_trans::~pg_trans()
{
  if (!m_trans_done)
    rollback();
}

void
pg_trans::commit()
{
  if (m_begin) {
    pg_stmt("COMMIT", m_cnx);
  }
  else if (m_savepoint) {
    pg_stmt("RELEASE SAVEPOINT pgs_s", m_cnx);
  }
  m_trans_done=true;
}

void
pg_trans::rollback()
{
  if (m_begin) {
    pg_stmt("ROLLBACK", m_cnx);
  }
  else if (m_savepoint) {
    pg_stmt("ROLLBACK TO pgs_s", m_cnx);
  }
  m_trans_done=true;
}

/*
  Build a pg_excpt instance from a PGresult; then free that result
*/
//static
pg_excpt
pg_excpt::mk_excpt(PGresult *r, const char* query/*=NULL*/)
{
  std::string errstr="";
  std::string ecode;
  if (r) {
    errstr = PQresultErrorMessage(r);
    ecode = PQresultErrorField(r, PG_DIAG_SQLSTATE);
    PQclear(r);
  }
  return pg_excpt(query?query:"pgstream", errstr.c_str(), ecode);
}

std::string
pg_excpt::full_error_txt() const
{
  std::string txt = m_query;
  if (!txt.empty())
    txt.append("\n");
  txt.append(m_err_msg);
  if (m_err_code.empty()) {
    txt.append("(ERR=");
    txt.append(m_err_code);
    txt.append(")\n");
  }
  return txt;
}

pg_cursor::pg_cursor(unsigned int step, const char* query, pg_cnx& cnx):
  pg_stream(cnx)
{
  init(query, 2, step);
}

pg_cursor::pg_cursor(unsigned int step, std::string query, pg_cnx& cnx):
  pg_stream(cnx)
{
  init(query.c_str(), 2, step);
}

#ifdef _MSC_VER
#pragma warning( pop)
#endif
