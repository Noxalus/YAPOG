#include "Server/Server.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "Account/AccountManager.hpp"
#include "YAPOG/Database/DatabaseManager.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "Account/AccountManager.hpp"
#include "YAPOG/Database/DatabaseManager.hpp"
#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/System/RandomHelper.hpp"

static void test_db ()
{
  int selection = 0;
  yap::String username;
  yap::String password;
  yap::String email;
  yap::DatabaseManager dm;
  dm.Connect ();
  dm.SetLogStream (std::cerr);

  yse::AccountManager am (dm);
  yap::String account;
  bool isRunning = true;

  try
  {
    //pg_stmt ("TRUNCATE account CASCADE", dm.GetConnection ());

    // Reset the currentIp field
    yap::String queryString =
      "UPDATE account SET account_current_ip = NULL";

    pgs::pg_stmt (queryString, dm.GetConnection ());

    while (isRunning)
    {
      std::cout << "Please select an action:" << std::endl
        << "1. Login" << std::endl
        << "2. Create a new account" << std::endl
        << "3. See all accounts" << std::endl
        << "4. See logged accounts" << std::endl
        << "5. Disconnect an account" << std::endl;

      std::cin >> selection;
      std::cout << std::endl;

      switch (selection)
      {
      case 1:
        std::cout << "Login !" << std::endl;
        std::cout << "Please enter a username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        am.Login (username, password, "127.0.0.1");

        std::cout << "Account information:" << std::endl;
        //am.GetAccount (username).DisplayData ();

        break;
      case 2:
        std::cout << "Create new account !" << std::endl;
        std::cout << "Please enter a username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;
        std::cout << "Email address: ";
        std::cin >> email;

        am.CreateNewAccount (username, password, email, "127.0.0.1");

        break;
      case 3:
        std::cout << "See all accounts !" << std::endl;
        am.DisplayAllAccounts ();
        break;
      case 4:
        std::cout << "See logged accounts !" << std::endl;
        am.DisplayLoggedAccounts ();
        break;
      case 5:
        std::cout << "Disconnect an account !" << std::endl;
        std::cout << "Please enter a username: ";
        std::cin >> username;
        am.Disconnect (username);
        break;
      default:
        std::cout << "Invalid selection !" << std::endl;
        isRunning = false;
        break;
      }

      std::cout << std::endl;
    }
  }
  catch (const yap::Exception& e)
  {
    e.GetMessage (std::cerr) << std::endl;
    getchar ();
    getchar ();
  }
  catch (const pgs::pg_excpt& e)
  {
    std::cerr << e.errmsg () << std::endl;
    getchar ();
    getchar ();
  }
}

void database_test_accent ()
{
  try
  {
    pgs::pg_cnx cnx;
    cnx.connect("dbname=yapog "
        "user=postgres "
        "password=COUCOU "
        "port=5432");

    yap::String query_string = 
      "INSERT INTO test(name) VALUES ('Salamèche')";

    pgs::pg_stream query 
      (query_string, cnx);

    std::cout << "Data saved !" << std::endl;
    getchar ();
  }
  catch (pgs::pg_excpt e)
  {
    std::cerr << e.errmsg () << std::endl;
    getchar ();
  }
}

int main ()
{
  try
  {
    //test_db ();
    //database_test_accent ();
    std::cout << "Server launched !" << std::endl;

    yse::Server server;

    server.Init ();

    server.Launch ();
  }
  catch (const yap::Exception& ex)
  {
    ex.GetMessage (std::cout) << std::endl;
    getchar ();
  }
}
