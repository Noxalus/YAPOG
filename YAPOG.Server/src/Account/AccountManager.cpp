#include "YAPOG/Database/DatabaseStream.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Account/AccountManager.hpp"
#include "Database/Tables/AccountTable.hpp"
#include "Database/Tables/PlayerDataTable.hpp"
#include "Database/Tables/PlayerDataTable.hpp"
#include "Database/Requests/Inserts/AccountInsertRequest.hpp"
#include "Database/Requests/Selects/AccountSelectRequest.hpp"
#include "Database/Requests/Inserts/PlayerDataInsertRequest.hpp"
#include "Database/Requests/Selects/PlayerDataSelectRequest.hpp"

namespace yse
{
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
    accountTable.SetName (name);
    accountTable.SetPassword (password);
    accountTable.SetEmail (email);
    accountTable.SetCreationIP (creationIP);
    AccountInsertRequest ia (accountTable);

    if (ia.Insert (databaseManager_))
    {
      std::cout << "A new accout has been created ! (" 
        << name << ")" << std::endl;

      PlayerDataTable playerDataTable (ia.GetID ());
      PlayerDataInsertRequest ipd (playerDataTable);

      if (ipd.Insert (databaseManager_))
      {
        std::cout << "Player data have been created !" << std::endl;
        return true;
      }
    }

    return false;
  }

  void AccountManager::Login (
    const yap::String& name, 
    const yap::String& password, 
    const yap::String& current_ip)
  {
    std::cout << "Login of \"" << name 
      << "\" (pass: \"" << password << "\") !" << std::endl;

    AccountTable accountTable;
    AccountSelectRequest asr (databaseManager_, name, accountTable);

    accountTable.DisplayData ();

    yap::String encodedPassword = EncodePassword (password);

    // Check if this is the corresponding password
    if (accountTable.GetPassword () != encodedPassword)
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
    yap::String encodedPassword = password;
    int counter = password.length ();

    while (counter < 32)
    {
      encodedPassword += ' ';
      counter++;
    }

    return encodedPassword;
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
