#ifndef YAPOG_ACCOUNTMANAGER_HPP
# define YAPOG_ACCOUNTMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "Database/Tables/InsertAccount.hpp"
# include "Database/Tables/SelectAccount.hpp"

class AccountManager
{
	DISALLOW_COPY(AccountManager);
public:
	AccountManager (yap::DatabaseManager& dm);
	~AccountManager ();

	void CreateNewAccount (const yap::String& name, const yap::String& password, 
		const yap::String& email, const yap::String& creationIp);
	void Login (const yap::String& name, const yap::String& password, const yap::String& current_ip);
	void Disconnect (const yap::String& name);
	void DisplayAllAccounts ();
	void DisplayLoggedAccounts ();
	SelectAccount& GetAccount (const yap::String& name);
	yap::String EncodePassword (const yap::String& password);
private:
	yap::DatabaseManager& databaseManager_;
	yap::collection::Map<yap::String, SelectAccount*> accounts_;
};

#endif // YAPOG_ACCOUNTMANAGER_HPP