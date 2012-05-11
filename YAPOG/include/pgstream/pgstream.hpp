/*
pgstream.h: include file for the pgstream library.
Copyright (c) 2004-2012, Daniel Verite.
See COPYING file for license terms.
http://www.manitou-mail.org/pgstream
*/

#ifndef INC_PGSTREAM_H
#define INC_PGSTREAM_H

#include <libpq-fe.h>
#include <string>
#include <vector>

#include "YAPOG/Macros.hpp"

namespace pgs
{
  class sql_null
  {
  public:
    sql_null() {}
    ~sql_null() {}
  private:
    int m_placeholder;		/* avoid a MSVC++ bug with empty classes */
  };

  /// sql exception class
  class YAPOG_LIB pg_excpt
  {
  public:
    pg_excpt() {}
    pg_excpt(const char* e_query, const char *msg, std::string code="") {
      if (e_query)
        m_query=e_query;
      else
        m_query="";
      m_err_msg=msg;
      m_err_code=code;
    }
    virtual ~pg_excpt() {}
    std::string query() const { return m_query; }
    std::string errmsg() const { return m_err_msg; }
    std::string errcode() const { return m_err_code; }
    std::string full_error_txt() const;

    static pg_excpt mk_excpt(PGresult *r, const char* query=NULL);
  private:
    std::string m_query;
    std::string m_err_msg;
    std::string m_err_code;
  };


  class YAPOG_LIB pg_cnx
  {
    friend class pg_stream;
    friend class pg_trans;
  public:
    pg_cnx(PGconn* conn=NULL);
    virtual ~pg_cnx();
    PGconn* conn() {
      return m_conn;
    }
    void connect(const char* cnx_string);
    void set_option(const char* param, bool bvalue);
    bool get_option(const char* param) const;
  private:
    bool opt_true_false(const char* value, bool* b);
    PGconn* m_conn;
    std::string m_connect_string;

    // true if we should close the connection when the object is destroyed
    bool m_destructor_close;

  protected:
    // m_default_prepare
    // true: use PQexecPrepared
    // false: don't prepare statements
    bool m_default_prepare;

    // m_inline_params
    // true: replace the bind variables by their values inside the sql statement
    // false: pass the values outside the sql sentence (use PQexecParams
    // or PQexecPrepared)
    bool m_inline_params;

    // true if we're allowed to use nested transactions
    bool m_nested_trans;
  };

  class YAPOG_LIB pg_stmt
  {
  public:
    pg_stmt(const char* stmt, pg_cnx& db);
    pg_stmt(const std::string stmt, pg_cnx& db);
    virtual ~pg_stmt();
  private:
    PGresult* m_res;
    void execute(const char* stmt, pg_cnx& db);
  };

  class YAPOG_LIB pg_trans
  {
  public:
    pg_trans(pg_cnx& cnx);
    virtual ~pg_trans();
    void commit();
    void rollback();
  private:
    pg_cnx& m_cnx;

    bool m_begin; // if we have issued a BEGIN
    bool m_trans_done; // if we have issued a COMMIT or ROLLBACK
    bool m_savepoint; // if we have issued a SAVEPOINT
  };

  /// sql_bind_param class. To be used for pg_stream internal purposes
  class YAPOG_LIB sql_bind_param
  {
  public:
    sql_bind_param() {}
    sql_bind_param(const std::string s, int param_pos) {
      m_name=s;
      m_initial_offset=m_offset=param_pos;
      m_null=false;
    }
    virtual ~sql_bind_param() {}
    void offset(int off) {
      m_offset += off;
    }
    void reset_offset() {
      m_offset=m_initial_offset;
    }
    const std::string name() const { return m_name; }
    const std::string type_name() const { return m_type_name; }
    const std::string value() const { return m_value; }
    bool null() const { return m_null; }
    int pg_type() const { return m_type_oid; }
    int pos() const { return m_offset; }
    void set_null() { m_null=true; }
    /* SELECT oid FROM pg_type -- for the supported values of "typname" */
    enum type_oid {
      oid_bool=16,
      oid_bytea=17,
      oid_int8=20,
      oid_int2=21,
      oid_int4=23,
      oid_text=25,
      oid_varchar=1043,
      oid_numeric=1700
    };
    void set_type(enum type_oid o);
    void set_type(const char*);
    void set_value(const char* buf) { m_value=buf; }
    void set_binary_data(const void* buf, unsigned int sz) { 
      m_data_ptr=buf;
      m_data_size=sz;
    }
    const void* data_ptr() const { return m_data_ptr; }
    unsigned int data_size() const { return m_data_size; }
  private:
    std::string m_name;
    std::string m_value;
    std::string m_type_name;
    const void* m_data_ptr;	/* pointer to external binary data (bytea parameters) */
    unsigned int m_data_size;	/* size of binary data (bytea) */
    int m_offset;		/* position of the ':' character in query */
    int m_initial_offset;
    int m_type_oid;
    bool m_null;
    static const char* m_type_names[];
    static int m_oids[];
  };

  class YAPOG_LIB pg_bytea
  {
    friend class pg_stream;
  public:
    pg_bytea();
    pg_bytea(void* ptr, unsigned int len);
    virtual ~pg_bytea();
    void set_src_data(void* ptr, unsigned int len) {
      m_data_ptr=ptr;
      m_data_len=len;
    }
    void* get_data_ptr() const {
      return m_data_ptr;
    }
    unsigned int get_data_size() const {
      return m_data_len;
    }
    bool is_null() const {
      return m_data_ptr==NULL;
    }
  protected:
    void* m_data_ptr;
    unsigned int m_data_len;
    bool m_allocated;		// if m_data_ptr was allocated by the class
  };

  /**
  pg_stream class. Allows the parametrized execution of a query
  and retrieval of results in a stream
  */
  class YAPOG_LIB pg_stream
  {
  public:
    /// constructor
    // prepare_mode=0: don't prepare the statement; 1: prepare, 2:use
    // the current default for the db connection
    pg_stream(const char* query, pg_cnx& db,int prepare_mode=2);
    pg_stream(const std::string query, pg_cnx& db,int prepare_mode=2);
    virtual ~pg_stream();

    /// assign a char* parameter
    pg_stream& operator<<(const char*);
    pg_stream& operator<<(const std::string&);
    /// assign an int parameter
    pg_stream& operator<<(int);
    pg_stream& operator<<(unsigned int);
    pg_stream& operator<<(long);
    pg_stream& operator<<(unsigned long);
    pg_stream& operator<<(long long);
    pg_stream& operator<<(unsigned long long);
    pg_stream& operator<<(short);
    pg_stream& operator<<(unsigned short);
    pg_stream& operator<<(double);
    pg_stream& operator<<(bool);
    pg_stream& operator<<(sql_null);
    pg_stream& operator<<(pg_bytea&);

    pg_stream& operator>>(short&);
    pg_stream& operator>>(unsigned short&);
    pg_stream& operator>>(int&);
    pg_stream& operator>>(unsigned int&);
    pg_stream& operator>>(char*);
    pg_stream& operator>>(std::string&);
    pg_stream& operator>>(pg_bytea&);
    pg_stream& operator>>(double&);
    pg_stream& operator>>(bool&);

    void prepare(bool prep=true) {
      m_prepare_wanted=prep;
    }
    void set_cursor(unsigned int step) {
      m_cursor_step = step;
    }
    void use_bind_variables(bool u=true) {
      m_inline_params = !u;
    }
#if 0
    void print();
#endif

    /** returns true if there are no more results to read from the stream,
    or false otherwise */
    int eof();
    int eos() { return eof(); }
    bool val_is_null() const {
      return m_val_null;
    }
    int affected_rows() const {
      return m_affected_rows;
    }
  protected:
    void init(const char* query,int prepare_mode,unsigned int cursor_step);
    pg_stream(pg_cnx& db) : m_db(db) {}
    pg_cnx& m_db;

  private:
    /** send the query to the server */
    void execute();

    void do_prepare();
    void create_cursor();
    void cursor_fetch();
    void check_binds();
    void reset_results();
    void next_result();
    void check_eof();
    void query_make_space(int len);
    void replace_placeholder(unsigned int argpos, const char* buf, int size, bool binary=false);
    void next_bind();
    bool check_null();

    unsigned int m_argpos;
    char* m_query_buf;
    int m_query_bufsize;
    int m_query_len;
    int m_initial_query_len;
    char m_localQueryBuf[1024+1];
    std::string m_query_fmt;	/* initial query text */
    int m_chunk_size;
    std::vector<sql_bind_param> m_vars;
    unsigned int m_query_hash;
    // results
    int m_executed;
    PGresult* m_pg_res;
    int m_row_number;		/* last row read from the stream */
    int m_col_number;		/* last column read from the stream */
    bool m_val_null;		/* last value read from the stream is null */
    int m_affected_rows;
    int m_cursor_step;
    bool m_prepare_wanted;	/* use PQexecPrepared if possible */
    std::string m_prepare_name;
    std::string m_cursor_name;

    // m_inline_params
    // true: replace the bind variables by their values inside the sql statement
    // false: pass the values outside the sql sentence (use PQexecParams
    // or PQexecPrepared)
    bool m_inline_params;

    // global counter to uniquely identify prepared statements and cursors
    static int m_uniq_cnt;
  };

  class YAPOG_LIB pg_cursor : public pg_stream
  {
  public:
    pg_cursor(unsigned int step, const char* query, pg_cnx& cnx);
    pg_cursor(unsigned int step, std::string query, pg_cnx& cnx);
  };
} // namespace pgs
#endif // INC_PGSTREAM_H
