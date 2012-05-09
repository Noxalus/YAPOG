#ifndef YAPOG_ACCOUNT_HPP
# define YAPOG_ACCOUNT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "Database/Tables/InsertAccount.hpp"
# include "Database/Tables/SelectAccount.hpp"
# include "Account/AccountPermission.hpp"

class Account
{
  DISALLOW_COPY(Account);
public:
  Account ();

  /// Getters
  const yap::ID& GetID () const;
  const yap::String& GetName () const;
  const yap::String& GetPassword () const;
  const yap::String& GetEmail () const;
  const AccountPermission& GetPermissions () const;
  const yap::String& GetCreationDate () const;
  const yap::String& GetLastLoginDate () const;
  const yap::String& GetCreationIP () const;
  const yap::String& GetCurrentIP () const;

  /// Setters
  void SetID (const yap::ID& value);
  void SetName (const yap::String& value);
  void SetPassword (const yap::String& value);
  void SetEmail (const yap::String& value);
  void SetPermissions (const AccountPermission& value);
  void SetCreationDate (const yap::String& value);
  void SetLastLoginDate (const yap::String& value);
  void SetCreationIP (const yap::String& value);
  void SetCurrentIP (const yap::String& value);

  void DisplayData ();
  bool IsLogged ();

private:
  yap::ID id_;
  yap::String name_;
  yap::String password_;
  yap::String email_;
  AccountPermission permissions_;
  yap::String creationDate_;
  yap::String lastLoginDate_;
  yap::String creationIP_;
  yap::String currentIP_;
};

#endif // YAPOG_ACCOUNT_HPP