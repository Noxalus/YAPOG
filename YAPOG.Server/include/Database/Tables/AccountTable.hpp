#ifndef YAPOG_ACCOUNTTABLE_HPP
# define YAPOG_ACCOUNTTABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "Database/Tables/ITable.hpp"
# include "Account/AccountPermission.hpp"

namespace yse
{
  class AccountTable : public ITable
  {
    DISALLOW_COPY(AccountTable);
  public:
    AccountTable ();

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
} // namespace yse

#endif // YAPOG_ACCOUNTTABLE_HPP