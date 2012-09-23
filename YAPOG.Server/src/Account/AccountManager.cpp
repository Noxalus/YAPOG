#include "YAPOG/Database/DatabaseStream.hpp"
#include "YAPOG/Database/DatabaseTransaction.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/Hash/Md5.hpp"
#include "YAPOG/System/RandomHelper.hpp"

#include "Account/AccountManager.hpp"
#include "Database/Tables/AccountTable.hpp"
#include "Database/Tables/PlayerDataTable.hpp"
#include "Database/Tables/PlayerDataTable.hpp"
#include "Database/Tables/PokemonTable.hpp"
#include "Database/Tables/PokemonMoveTable.hpp"
#include "Database/Tables/PokemonEVTable.hpp"
#include "Database/Tables/PokemonIVTable.hpp"

#include "Database/Requests/Inserts/AccountInsertRequest.hpp"
#include "Database/Requests/Inserts/PlayerDataInsertRequest.hpp"
#include "Database/Requests/Inserts/PokemonInsertRequest.hpp"
#include "Database/Requests/Inserts/PokemonMoveInsertRequest.hpp"
#include "Database/Requests/Inserts/PokemonEVInsertRequest.hpp"
#include "Database/Requests/Inserts/PokemonIVInsertRequest.hpp"

#include "Database/Requests/Selects/AccountSelectRequest.hpp"
#include "Database/Requests/Selects/PlayerDataSelectRequest.hpp"
#include "Database/Requests/Selects/PokemonSelectRequest.hpp"

#include "Database/Requests/Updates/PokemonUpdateRequest.hpp"

#include "Pokemon/PokemonTeam.hpp"
#include "Pokemon/Pokemon.hpp"

namespace yse
{
  Pokemon* GenerateRandomPokemon ()
  {
    yap::ID staticID = yap::ID (yap::RandomHelper::GetNext (1, 10));

    if (staticID == yap::ID (10))
      staticID = yap::ID (16);

    int level = yap::RandomHelper::GetNext (1, 100);
    level = 5;
    Pokemon* p = new Pokemon (staticID, level, false);
    p->AddExperience (5/*yap::RandomHelper::GetNext (1, 100000)*/);

    return p;
  }

  AccountManager::AccountManager (yap::DatabaseManager& dm)
    : databaseManager_ (dm)
    , accounts_ ()
  {
  }

  AccountManager::~AccountManager ()
  {
    for (const auto& it : accounts_)
      delete it.second;
  }

  bool AccountManager::CreateNewAccount (
    const yap::String& name,
    const yap::String& password,
    const yap::String& email,
    const yap::String& creationIP)
  {
    AccountTable accountTable;

    // Hash password
    yap::String hashedPassword = EncodePassword (password);

    accountTable.SetName (name);
    accountTable.SetPassword (hashedPassword);
    accountTable.SetEmail (email);
    accountTable.SetCreationIP (creationIP);
    AccountInsertRequest ia (accountTable);

    try
    {
      yap::DatabaseTransaction trans (databaseManager_.GetConnection ());

      if (ia.Insert (databaseManager_))
      {
        std::cout << "A new accout has been created ! (" 
          << name << ")" << std::endl;

        PlayerDataTable playerDataTable (ia.GetID ());
        PlayerDataInsertRequest ipd (playerDataTable);

        if (ipd.Insert (databaseManager_))
        {
          std::cout << "Player data have been created !" << std::endl;

          // Add first Pokemon
          for (int i = 1; i <= 5; i++)
          {
            Pokemon* p = GenerateRandomPokemon ();

            // Insertion of the current Pokemon's basics information
            PokemonTable pokemonTable;
            pokemonTable.accountID_ = ia.GetID ();
            pokemonTable.LoadFromPokemon (*p);
            pokemonTable.boxIndex_ = yap::ID (i);
            PokemonInsertRequest pokemonInsert (pokemonTable);

            if (pokemonInsert.Insert (databaseManager_))
            {
              // Insertion of the current Pokemon's EV
              PokemonEVTable pokemonEVTable;
              pokemonEVTable.LoadFromPokemon (*p);
              pokemonEVTable.pokemonID_ = pokemonInsert.GetID ();
              PokemonEVInsertRequest pokemonEVInsert (pokemonEVTable);

              // Insertion of the current Pokemon's IV
              PokemonIVTable pokemonIVTable;
              pokemonIVTable.LoadFromPokemon (*p);
              pokemonIVTable.pokemonID_ = pokemonInsert.GetID ();
              PokemonIVInsertRequest pokemonIVInsert (pokemonIVTable);

              if (pokemonIVInsert.Insert (databaseManager_)
                && pokemonEVInsert.Insert (databaseManager_))
              {
                for (int i = 0; i < 4; i++)
                {
                  // Insertion of the current Pokemon's moves
                  PokemonMoveTable pokemonMoveTable;
                  pokemonMoveTable.LoadFromPokemon (*p, yap::ID(i));
                  pokemonMoveTable.pokemonID_ = pokemonInsert.GetID ();
                  PokemonMoveInsertRequest pokemonStatsInsert (pokemonMoveTable);

                  pokemonStatsInsert.Insert (databaseManager_);
                }

                std::cout << "A random Pokemon have been added to the player !" 
                  << std::endl;
              }
            }
          }

          trans.Commit ();

          return true;
        }
      }
    }
    catch (yap::Exception e)
    {
      e.GetMessage (std::cout);
    }

    return false;
  }

  Account* AccountManager::Login (
    const yap::String& name, 
    const yap::String& password, 
    const yap::String& current_ip)
  {
    std::cout << "Login of \"" << name 
      << "\" (pass: \"" << password << "\") !" << std::endl;

    AccountTable accountTable;
    AccountSelectRequest asr (databaseManager_, name, accountTable);

    accountTable.DisplayData ();

    yap::String hashPassword = EncodePassword (password);

    // Check if this is the corresponding password
    if (accountTable.GetPassword () != hashPassword)
      throw yap::Exception ("Wrong password !");

    /*
    // Check if the account is already logged in
    if (accountTable.IsLogged ())
    throw yap::Exception ("A person is already using this account !");
    */

    // Get player data
    PlayerDataTable playerDataTable (accountTable.GetID ());
    PlayerDataSelectRequest pdsr (databaseManager_, playerDataTable);

    playerDataTable.DisplayData ();

    // Record the login IP
    /*
    accountTable.SetCurrentIP (current_ip);

    yap::String queryString = 
    "UPDATE account SET "
    "account_current_ip = :currentIp, "
    "account_last_login_date = NOW () "
    " WHERE account_name = :name";

    yap::DatabaseStream queryUpdateCurrentIp (
    queryString, 
    databaseManager_.GetConnection ());

    queryUpdateCurrentIp.Write (current_ip);
    queryUpdateCurrentIp.Write (name);

    std::cout 
    << "This account is now in use for the "
    << "server and the database !" << std::endl;
    */

    Account* account = new Account ();
    account->LoadFromTable (accountTable, playerDataTable);

    PokemonTeam* pokemonTeam;
    PokemonSelectRequest selectPokemon (databaseManager_);
    pokemonTeam = selectPokemon.SelectPokemonTeam (
      account->GetName (), account->GetID ());

    account->SetTeam (pokemonTeam);

    return account;
    /*
    if (account->IsLogged ())
    std::cout << "This account is logged !" << std::endl;

    accounts_.Add (name, account);
    */
  }

  void AccountManager::DisplayAllAccounts ()
  {
    yap::String current_account;

    try
    {
      yap::DatabaseStream accounts (
        "SELECT account_name "
        "FROM account", 
        databaseManager_.GetConnection ());

      while (!accounts.EndOfStream ())
      {
        current_account = accounts.ReadString ();
        std::cout << current_account << std::endl;
      }

      std::cout << accounts.AffectedRows () 
        << " account(s) found !" << std::endl;
    }
    catch (pgs::pg_excpt e)
    {
      std::cerr << e.errmsg () << std::endl;
    }
  }

  void AccountManager::DisplayLoggedAccounts ()
  {
    /*
    for (const auto& sa : accounts_)
    std::cout << sa.second->GetName () << std::endl;
    */
  }

  Account& AccountManager::GetAccount (const yap::String& name)
  {
    if (accounts_.Contains (name))
      return *accounts_[name];
    else
      YAPOG_THROW("This account doesn't exist !");
  }

  yap::String AccountManager::EncodePassword (
    const yap::String& password)
  {
    yap::Md5 md5;
    yap::String hashedPassword = md5.Calculate (password);

    return hashedPassword;
  }

  void AccountManager::Disconnect (const yap::String& name)
  {
    if (!accounts_.Contains (name))
      throw yap::Exception ("This account doesn't log in !");

    yap::String queryString = 
      "UPDATE account "
      "SET account_current_ip = NULL "
      "WHERE account_name = :name";

    yap::DatabaseStream update 
      (queryString, databaseManager_.GetConnection ());

    update.Write (name);

    accounts_.Remove (name);
    std::cout << name << " is now disconnected !" << std::endl;
  }
} // namespace yse
