#include "Account/AccountManager.hpp"
#include "Account/PlayerData.hpp"

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

void AccountManager::CreateNewAccount (
  const yap::String& name,
  const yap::String& password,
  const yap::String& email,
  const yap::String& creationIP)
{
  Account account;
  account.SetName (name);
  account.SetPassword (password);
  account.SetEmail (email);
  account.SetCreationIP (creationIP);
  InsertAccount ia (account);

  if (ia.Add (databaseManager_))
  {
    std::cout << "A new accout has been created ! (" 
      << name << ")" << std::endl;
  }

  PlayerData playerData (ia.GetID ());
  InsertPlayerData ipd (playerData);

  if (ipd.Add (databaseManager_))
    std::cout << "Player data have been created !" << std::endl;
}

void AccountManager::Login (
  const yap::String& name, 
  const yap::String& password, 
  const yap::String& current_ip)
{
  std::cout << "Login of \"" << name 
    << "\" (pass: \"" << password << "\") !" << std::endl;

  Account* account = new Account ();
  SelectAccount sa (databaseManager_, name, *account);

  yap::String encodedPassword = EncodePassword (password);

  // Check if this is the corresponding password
  if (account->GetPassword () != encodedPassword)
    throw yap::Exception ("Wrong password !");

  // Check if the account is already logged in
  if (account->IsLogged ())
    throw yap::Exception ("A person is already using this account !");

  // Get player data
  PlayerData* playerData = new PlayerData (account->GetID ());
  SelectPlayerData spd (databaseManager_, *playerData);

  playerData->DisplayData ();

  // Record the login IP
  account->SetCurrentIP (current_ip);

  yap::String queryString = 
    "UPDATE account SET "
    "account_current_ip = :currentIp, account_last_login_date = NOW () "
    " WHERE account_name = :name";

  pg_stream queryUpdateCurrentIp (
    queryString, databaseManager_.GetConnection ());

  queryUpdateCurrentIp << current_ip << name;
  std::cout 
    << "This account is now in use for the "
    << "server and the database !" << std::endl;

  if (account->IsLogged ())
    std::cout << "This account is logged !" << std::endl;

  accounts_.Add (name, account);
}

void AccountManager::DisplayAllAccounts ()
{
  yap::String current_account;

  try
  {
    pg_stream accounts ("SELECT account_name FROM account", databaseManager_.GetConnection ());

    while (!accounts.eof ())
    {
      accounts >> current_account;
      std::cout << current_account << std::endl;
    }

    std::cout << accounts.affected_rows () << " account(s) found !" << std::endl;
  }
  catch (pg_excpt e)
  {
    std::cerr << e.errmsg () << std::endl;
  }
}

void AccountManager::DisplayLoggedAccounts ()
{
  for (const auto& sa : accounts_)
    std::cout << sa.second->GetName () << std::endl;
}

Account& AccountManager::GetAccount (const yap::String& name)
{
  if (accounts_.Contains (name))
    return *accounts_[name];
  else
    throw yap::Exception ("This account doesn't exist !");
}

yap::String AccountManager::EncodePassword (const yap::String& password)
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

  yap::String queryString = "UPDATE account SET account_current_ip = NULL WHERE account_name = :name";
  pg_stream update (queryString, databaseManager_.GetConnection ());
  update << name;

  accounts_.Remove (name);
  std::cout << name << " is now disconnected !" << std::endl;
}
