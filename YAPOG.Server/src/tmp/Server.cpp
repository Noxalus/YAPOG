#include <iostream>
#include <ctime>
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
#include "YAPOG/Game/Pokemon/Pokemon.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/Game/Pokemon/NatureInfoReader.hpp"
#include "YAPOG/Game/Pokemon/NatureInfo.hpp"
#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/Game/Pokemon/TypeInfoReader.hpp"
#include "YAPOG/Game/Pokemon/TypeInfo.hpp"
#include "YAPOG/System/IO/IWriter.hpp"

int main ()
{
  std::cout << "Server is starting..."
    << std::endl;

  try
  {
    yap::Path ContentDirectory ("../../Content");
    yap::ContentManager::Instance ().Init (ContentDirectory);
    yap::ObjectFactory::Instance ().RegisterLoader 
      ("PokemonInfo",
      new yap::XmlObjectIDLoader<yap::PokemonInfo, yap::PokemonInfoReader>
      (yap::Path ("Pokemon/Pokemon"), "PokemonInfo"));

    yap::ObjectFactory::Instance ().RegisterLoader 
      ("NatureInfo",
      new yap::XmlObjectIDLoader<yap::NatureInfo, yap::NatureInfoReader>
      (yap::Path ("Pokemon/Nature"), "Nature"));

    yap::ObjectFactory::Instance ().RegisterLoader 
      ("TypeInfo",
      new yap::XmlObjectIDLoader<yap::TypeInfo, yap::TypeInfoReader>
      (yap::Path ("Pokemon/Types"), "Type"));

    yap::Pokemon p1 (yap::ID (1));
    p1.PrintStats ();

    yap::Pokemon p2 (yap::ID (1), 16, true);
    p2.PrintStats ();

    yap::Pokemon p3 (yap::ID (1), 75, false);
    p3.PrintStats ();

    yap::Pokemon p4 (yap::ID (1), 55, false);
    p4.PrintStats ();

    yap::Pokemon p5 (yap::ID (1), 99, false);
    p5.PrintStats ();

    yap::TypeInfo types[17];

    for (int i = 0; i < 17; i++)
    {
      types[i] = *yap::ObjectFactory::Instance ().
        Create<yap::TypeInfo> ("TypeInfo",  yap::ID (i + 1));
    }

    std::cout << yap::MathHelper::Pow (75, 3) << std::endl;

    /*
    p2.AddExperience (600);
    p2.PrintStats ();
    
    /*
    yap::OFStream file ("type.html");

    std::cout << "Type table !" << std::endl;

    file << "<table style=\"text-align: center;\"><tr><th>Types</th>";
    for (int i = 0; i < 17; i++)
      file << "<th>" << types[i].GetName () << "</th>";
    file << "</tr><tr>";

    for (int i = 0; i < 17; i++)
    {
      file << "<tr><td>" << types[i].GetName () << "</td>";
      for (int j = 0; j < 17; j++)
      {
        if (types[i].GetTypeEffect (types[j].GetID ()) == 0)
          file << "<td style=\"background-color: Red; color: White;\">";
        else if (types[i].GetTypeEffect (types[j].GetID ()) == 0.5)
          file << "<td style=\"background-color: Grey; color: White;\">";
        else if (types[i].GetTypeEffect (types[j].GetID ()) == 2)
          file << "<td style=\"background-color: Green; color: White;\">";
        else
          file << "<td>";

        file << types[i].GetTypeEffect (types[j].GetID ()) << "</td>";
      }
      file << "</tr>";
    }

    file << "</table>";

    yap::TypeInfo& grassType = types[4];
    std::cout << p1.GetName () << " against a move of type " << grassType.GetName () 
      << ": " << p1.GetTypeEffectFactor (grassType) << std::endl;
    */

    /*
    yap::RandomHelper::Init (std::time (nullptr));

    float rand = 0.f;
    for (int i = 0; i < 100000000; i++)
    {
    rand = yap::RandomHelper::GetNext (0.f, 1.f) * 100;
    if (rand == 100.f)
    {
    std::cout << "Random #" << i << ": " <<  rand << std::endl;
    break;
    }
    }

    std::cout << "Finish !" << std::endl;
    */

    getchar ();
  }
  catch (yap::Exception e)
  {
    e.GetMessage (std::cerr) << std::endl;
    getchar ();
  }
  catch (std::exception e)
  {
    std::cerr << e.what () << std::endl;
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
