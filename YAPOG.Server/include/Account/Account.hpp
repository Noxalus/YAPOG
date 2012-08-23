#ifndef YAPOG_ACCOUNT_HPP
# define YAPOG_ACCOUNT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"

# include "Account/AccountPermission.hpp"

namespace yap
{
  class DatabaseManager;
}

namespace yse
{
  class AccountTable;
  class PlayerDataTable;
  class PlayerData;
  class PokemonTeam;

  class Account
  {
    DISALLOW_COPY(Account);
  public:
    Account ();

    void LoadFromTable (const AccountTable& at, const PlayerDataTable& pdt);
    void SaveAccountData (yap::DatabaseManager& dm);

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

    PlayerData& GetPlayerData () const;
    PokemonTeam& GetTeam () const;

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

    void SetTeam (PokemonTeam* value);

    static const yap::ID& DEFAULT_ACCOUNT_ID;
    static const yap::String DEFAULT_ACCOUNT_NAME;
    static const yap::String DEFAULT_ACCOUNT_PASSWORD;
    static const yap::String DEFAULT_ACCOUNT_EMAIL;
    static const yap::String DEFAULT_ACCOUNT_CREATION_DATE;
    static const AccountPermission DEFAULT_ACCOUNT_PERMISSION;
    static const yap::String DEFAULT_ACCOUNT_LAST_LOGIN_DATE;
    static const yap::String DEFAULT_ACCOUNT_CREATION_IP;
    static const yap::String DEFAULT_ACCOUNT_CURRENT_IP;
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

    PlayerData* playerData_;
    PokemonTeam* team_;
  };
} // namespace yse

#endif // YAPOG_ACCOUNT_HPP