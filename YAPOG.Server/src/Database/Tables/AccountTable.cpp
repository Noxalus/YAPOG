#include "Database/Tables/AccountTable.hpp"
#include "Account/Account.hpp"

namespace yse
{
  AccountTable::AccountTable ()
    : id_ (Account::DEFAULT_ACCOUNT_ID)
    , name_ (Account::DEFAULT_ACCOUNT_NAME)
    , password_ (Account::DEFAULT_ACCOUNT_PASSWORD)
    , email_ (Account::DEFAULT_ACCOUNT_EMAIL)
    , permissions_ (Account::DEFAULT_ACCOUNT_PERMISSION)
    , creationDate_ (Account::DEFAULT_ACCOUNT_CREATION_DATE)
    , lastLoginDate_ (Account::DEFAULT_ACCOUNT_LAST_LOGIN_DATE)
    , creationIP_ (Account::DEFAULT_ACCOUNT_CREATION_IP)
    , currentIP_ (Account::DEFAULT_ACCOUNT_CURRENT_IP)
  {
  }

  void AccountTable::LoadFromAccount (const Account& account)
  {
    SetID (account.GetID ());
    SetName (account.GetName ());
    SetPassword (account.GetPassword ());
    SetEmail (account.GetEmail ());
    SetPermissions (account.GetPermissions ());
    SetCreationDate (account.GetCreationDate ());
    SetLastLoginDate (account.GetLastLoginDate ());
    SetCreationIP (account.GetCreationIP ());
    SetCurrentIP (account.GetCurrentIP ());
  }

  /// Getters
  const yap::ID& AccountTable::GetID () const
  { return id_; }
  const yap::String& AccountTable::GetName () const
  { return name_; }
  const yap::String& AccountTable::GetPassword () const
  { return password_; }
  const yap::String& AccountTable::GetEmail () const
  { return email_; }
  const AccountPermission& AccountTable::GetPermissions () const 
  { return permissions_; }
  const yap::String& AccountTable::GetCreationDate () const
  { return creationDate_; }
  const yap::String& AccountTable::GetLastLoginDate () const
  { return lastLoginDate_; }
  const yap::String& AccountTable::GetCreationIP () const
  { return creationIP_; }
  const yap::String& AccountTable::GetCurrentIP () const
  { return currentIP_; }

  /// Setters
  void AccountTable::SetID (const yap::ID& value) 
  { id_ = value; }
  void AccountTable::SetName (const yap::String& value) 
  { name_ = value; }
  void AccountTable::SetPassword (const yap::String& value) 
  { password_ = value; }
  void AccountTable::SetEmail (const yap::String& value) 
  { email_ = value; }
  void AccountTable::SetPermissions (const AccountPermission& value)  
  { permissions_ = value; }
  void AccountTable::SetCreationDate (const yap::String& value)
  { creationDate_ = value; }
  void AccountTable::SetLastLoginDate (const yap::String& value)
  { lastLoginDate_ = value; }
  void AccountTable::SetCreationIP (const yap::String& value)
  { creationIP_ = value; }
  void AccountTable::SetCurrentIP (const yap::String& value) 
  { currentIP_ = value; }

  void AccountTable::DisplayData ()
  {
    std::cout << "ID: " << id_.GetValue () << std::endl
      << "Username: " << name_ << std::endl
      << "Password: " << password_ << std::endl
      << "Email: " << email_ << std::endl
      << "Permission: " 
      << static_cast<yap::UInt16> (permissions_) << std::endl
      << "Creation Date: " << creationDate_ << std::endl
      << "Last Login Date: " << lastLoginDate_ << std::endl
      << "Creation IP: " << creationIP_ << std::endl
      << "Current IP: " << currentIP_ << std::endl;
  }

} // namespace yse