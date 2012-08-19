#ifndef YAPOG_ACCOUNTMANAGER_HPP
# define YAPOG_ACCOUNTMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "Account/Account.hpp"

namespace yse
{
  class PlayerData;

  class AccountManager
  {
    DISALLOW_COPY(AccountManager);
  public:
    AccountManager (yap::DatabaseManager& dm);
    ~AccountManager ();

    bool CreateNewAccount (
      const yap::String& name, 
      const yap::String& password, 
      const yap::String& email, 
      const yap::String& creationIp);

    void Login (
      const yap::String& name, 
      const yap::String& password, 
      const yap::String& current_ip);

    void Disconnect (const yap::String& name);
    void DisplayAllAccounts ();
    void DisplayLoggedAccounts ();
    Account& GetAccount (const yap::String& name);
    yap::String EncodePassword (const yap::String& password);
  private:
    yap::DatabaseManager& databaseManager_;
    yap::collection::Map<yap::String, Account*> accounts_;
  };
} // namespace yse

#endif // YAPOG_ACCOUNTMANAGER_HPP