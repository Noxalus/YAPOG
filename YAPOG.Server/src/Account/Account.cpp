#include "YAPOG/Database/DatabaseManager.hpp"

#include "Account/Account.hpp"
#include "Account/PlayerData.hpp"
#include "Database/Tables/AccountTable.hpp"
#include "Database/Tables/PlayerDataTable.hpp"
#include "Database/Requests/Updates/AccountUpdateRequest.hpp"
#include "Database/Requests/Updates/PlayerDataUpdateRequest.hpp"
#include "Pokemon/PokemonTeam.hpp"

namespace yse
{
  const yap::ID& Account::DEFAULT_ACCOUNT_ID = yap::ID (1);
  const yap::String Account::DEFAULT_ACCOUNT_NAME ("");
  const yap::String Account::DEFAULT_ACCOUNT_PASSWORD ("");
  const yap::String Account::DEFAULT_ACCOUNT_EMAIL ("");
  const yap::String Account::DEFAULT_ACCOUNT_CREATION_DATE ("");
  const AccountPermission Account::
    DEFAULT_ACCOUNT_PERMISSION = AccountPermission::Normal;
  const yap::String Account::DEFAULT_ACCOUNT_LAST_LOGIN_DATE ("");
  const yap::String Account::DEFAULT_ACCOUNT_CREATION_IP ("");
  const yap::String Account::DEFAULT_ACCOUNT_CURRENT_IP ("");

  Account::Account ()
    : id_ (DEFAULT_ACCOUNT_ID)
    , name_ (DEFAULT_ACCOUNT_NAME)
    , password_ (DEFAULT_ACCOUNT_PASSWORD)
    , email_ (DEFAULT_ACCOUNT_EMAIL)
    , creationDate_ (DEFAULT_ACCOUNT_CREATION_DATE)
    , permissions_ (DEFAULT_ACCOUNT_PERMISSION)
    , lastLoginDate_ (DEFAULT_ACCOUNT_LAST_LOGIN_DATE)
    , creationIP_ (DEFAULT_ACCOUNT_CREATION_IP)
    , currentIP_ (DEFAULT_ACCOUNT_CURRENT_IP)
    , playerData_ (nullptr)
    , team_ (nullptr)
  {
  }

  void Account::LoadFromTable (
    const AccountTable& at, 
    const PlayerDataTable& pdt)
  {
    SetID (at.GetID ());
    SetName (at.GetName ());
    SetPassword (at.GetPassword ());
    SetEmail (at.GetEmail ());
    SetPermissions (at.GetPermissions ());
    SetCreationDate (at.GetCreationDate ());
    SetLastLoginDate (at.GetLastLoginDate ());
    SetCreationIP (at.GetCreationIP ());
    SetCurrentIP (at.GetCurrentIP ());

    playerData_ = new PlayerData ();
    playerData_->LoadFromTable (pdt);
  }

  void Account::SaveAccountData (yap::DatabaseManager& dm)
  {
    /*
    AccountTable accountTable;
    accountTable.LoadFromAccount (*this);

    AccountUpdateRequest aUpdateRequest (accountTable);
    aUpdateRequest.Update (dm);
    */

    PlayerDataTable playerDataTable (id_);
    playerDataTable.LoadFromPlayerData (*playerData_);

    PlayerDataUpdateRequest pdUpdateRequest (playerDataTable);
    pdUpdateRequest.Update (dm);
  }

  /// Getters
  const yap::ID& Account::GetID () const
  { return id_; }
  const yap::String& Account::GetName () const
  { return name_; }
  const yap::String& Account::GetPassword () const
  { return password_; }
  const yap::String& Account::GetEmail () const
  { return email_; }
  const AccountPermission& Account::GetPermissions () const 
  { return permissions_; }
  const yap::String& Account::GetCreationDate () const
  { return creationDate_; }
  const yap::String& Account::GetLastLoginDate () const
  { return lastLoginDate_; }
  const yap::String& Account::GetCreationIP () const
  { return creationIP_; }
  const yap::String& Account::GetCurrentIP () const
  { return currentIP_; }

  PlayerData& Account::GetPlayerData () const
  { return *playerData_; }
  PokemonTeam& Account::GetTeam () const
  { return *team_; }

  /// Setters
  void Account::SetID (const yap::ID& value) 
  { id_ = value; }
  void Account::SetName (const yap::String& value) 
  { name_ = value; }
  void Account::SetPassword (const yap::String& value) 
  { password_ = value; }
  void Account::SetEmail (const yap::String& value) 
  { email_ = value; }
  void Account::SetPermissions (const AccountPermission& value)  
  { permissions_ = value; }
  void Account::SetCreationDate (const yap::String& value)
  { creationDate_ = value; }
  void Account::SetLastLoginDate (const yap::String& value)
  { lastLoginDate_ = value; }
  void Account::SetCreationIP (const yap::String& value)
  { creationIP_ = value; }
  void Account::SetCurrentIP (const yap::String& value) 
  { currentIP_ = value; }

  void Account::SetTeam (PokemonTeam* value)
  { team_ = value; }

} // namespace yse