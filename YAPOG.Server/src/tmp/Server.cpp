#include <iostream>
#include "Database/Tables/InsertAccount.hpp"
#include "Account/AccountManager.hpp"
#include "tmp/Server.hpp"
#include "YAPOG/Database/DatabaseManager.hpp"
#include "YAPOG/System/String.hpp"
#include "YAPOG/System/IOStream.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfoReader.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/System/Path.hpp"
#include "YAPOG/Content/ContentManager.hpp"

int main ()
{
  std::cout << "Server is starting..."
    << std::endl;

  try
  {
    yap::ContentManager::Instance ().Init (yap::Path ("../../Content/"));
    yap::ObjectFactory& ob = yap::ObjectFactory::Instance ();

    yap::Path path = yap::Path ("Pokemon");
    yap::XmlObjectIDLoader<yap::PokemonInfo, yap::PokemonInfoReader>* xoidl = 
      new yap::XmlObjectIDLoader<yap::PokemonInfo, yap::PokemonInfoReader> 
      (path, "PokemonInfo");
    ob.RegisterLoader ("PokemonInfo", xoidl);

    yap::PokemonInfo* pokeInfo = ob.Create<yap::PokemonInfo> ("PokemonInfo",  yap::ID (1));
    std::cout << "Get name: \"" << pokeInfo->GetName () << "\"" << std::endl;

    getchar ();
  }
  catch (std::exception e)
  {
    std::cerr << e.what () << std::endl;
    getchar ();
  }
  catch (yap::Exception e)
  {
    e.GetMessage (std::cerr) << std::endl;
    getchar ();
  }

  /*
  int selection = 0;
  yap::String username;
  yap::String password;
  yap::String email;
  yap::DatabaseManager dm;
  dm.SetLogStream (std::cerr);

  AccountManager am (dm);
  yap::String account;
  bool isRunning = true;

  try
  {
  //pg_stmt ("TRUNCATE account", dm.GetConnexion ());

  // Reset the currentIp field
  yap::String queryString = "UPDATE account SET account_current_ip = NULL";
  pg_stmt (queryString, dm.GetConnection ());

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
  am.GetAccount (username).DisplayData ();

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
  catch (const pg_excpt& e)
  {
  std::cerr << e.errmsg () << std::endl;
  getchar ();
  getchar ();
  }
  */

  return 0;
}
