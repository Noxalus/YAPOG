#include "Account/Account.hpp"

Account::Account ()
{
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

void Account::DisplayData ()
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

bool Account::IsLogged ()
{
  return (currentIP_ != "");
}