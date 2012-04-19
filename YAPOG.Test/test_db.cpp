#include <iostream>
#include <string>
#include <libpq-fe.h>
#include <sstream>

/* Close connection to database */
void CloseConn(PGconn* conn)
{
	PQfinish(conn);
	printf("Connection closed !\n");
	getchar();
	exit(1);
}

/* Establish connection to database */
PGconn* ConnectDB()
{
	PGconn* conn = NULL;

	// Make a connection to the database
	conn = PQconnectdb("dbname = 'yapog' user = 'postgres' password = 'COUCOU'");

	// Check to see that the backend connection was successfully made 
	if (PQstatus(conn) != CONNECTION_OK)
	{
		printf("Connection to database failed...\n");
		if (PQstatus(conn) == CONNECTION_BAD)
			std::cout << "Bad password !!" << std::endl;
		CloseConn(conn);
	}
	else
		printf("Connection to database - OK\n");

	return conn;
}

/* Create test table */
void CreateTestTable(PGconn* conn)
{
	// Execute with sql statement
	PGresult* res = PQexec(conn, "CREATE TABLE IF NOT EXISTS test (test_id serial, test_name char(30))");

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Create test table failed... :(\n");
		PQclear(res);
		CloseConn(conn);
	}

	printf("Create test table - OK !\n");

	// Clear result
	PQclear(res);
}

/* Append SQL statement and insert record into test table */
void InsertTestRec(PGconn* conn, char* name)
{
	// Append the SQL statment
	std::string sSQL;
	sSQL.append("INSERT INTO test(test_name) VALUES ('");
	sSQL.append(name);
	sSQL.append("')");

	// Execute with sql statement
	PGresult *res = PQexec(conn, sSQL.c_str());

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Insert test record failed...\n");
		if (PQresultStatus(res) == PGRES_FATAL_ERROR)
			std::cout << "FATAL ERROR !" << std::endl;
		PQclear(res);
		CloseConn(conn);
	}

	printf("Insert test record [%s] - OK !\n", name);

	// Clear result
	PQclear(res);
}

/* Fetch test record and display it on screen */
void FetchTestRec(PGconn* conn)
{
	// Will hold the number of field in test table
	int nFields;

	// Start a transaction block
	PGresult* res  = PQexec(conn, "BEGIN");

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("BEGIN command failed...\n");
		PQclear(res);
		CloseConn(conn);
	}

	// Clear result
	PQclear(res);

	// Fetch rows from test table
	res = PQexec(conn, "DECLARE emprec CURSOR FOR select * from test");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("DECLARE CURSOR failed...\n");
		PQclear(res);
		CloseConn(conn);
	}

	// Clear result
	PQclear(res);

	res = PQexec(conn, "FETCH ALL in emprec");

	if (PQresultStatus(res) != PGRES_TUPLES_OK)
	{
		printf("FETCH ALL failed...\n");
		PQclear(res);
		CloseConn(conn);
	}

	// Get the field name
	nFields = PQnfields(res);

	// Prepare the header with test table field name
	printf("\nFetch test record:");
	printf("\n********************************************************************\n");
	for (int i = 0; i < nFields; i++)
		printf("%-30s", PQfname(res, i));
	printf("\n********************************************************************\n");

	// Next, print out the test record for each row
	for (int i = 0; i < PQntuples(res); i++)
	{
		for (int j = 0; j < nFields; j++)
			printf("%-30s", PQgetvalue(res, i, j));
		printf("\n");
	}

	PQclear(res);

	// Close the emprec
	res = PQexec(conn, "CLOSE emprec");
	PQclear(res);

	// End the transaction
	res = PQexec(conn, "END");

	// Clear result
	PQclear(res);
}

/* Erase all record in test table */
void RemoveAllTestRec(PGconn* conn)
{
	// Execute with sql statement
	PGresult* res = PQexec(conn, "DELETE FROM test");

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Delete test record failed...\n");
		PQclear(res);
		CloseConn(conn);
	}

	printf("\nDelete test record - OK !\n");

	// Clear result
	PQclear(res);
}

/* Drop test table from the database*/
void DropTestTable(PGconn* conn)
{
  // Execute with sql statement
    PGresult* res = PQexec(conn, "DROP TABLE test");

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        printf("Drop test table failed...\n");
        PQclear(res);
        CloseConn(conn);
    }

  printf("Drop test table - OK !\n");

  // Clear result
  PQclear(res);
}

int main ()
{	
	PGconn* conn = NULL;

  conn = ConnectDB();
  CreateTestTable(conn);
  InsertTestRec(conn, "COUCOU_BEGIN");
	
	for(int i = 0; i < 10000; i++)
	{
		std::ostringstream oss;
		std::string test_string ("TEST #");
    oss << i;
		test_string += oss.str();
		InsertTestRec(conn, const_cast<char*>(test_string.c_str()));
	}

  InsertTestRec(conn, "COUCOU_END");
  FetchTestRec(conn);

  printf("\nPress ENTER to remove all records & table.....\n");
  getchar();

  RemoveAllTestRec(conn);
  DropTestTable(conn);

  CloseConn(conn);

  return 0;
}
