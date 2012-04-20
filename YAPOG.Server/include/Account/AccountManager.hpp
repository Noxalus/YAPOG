#ifndef YAPOG_ACCOUNTMANAGER_HPP
# define YAPOG_ACCOUNTMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"
# include "Database/Tables/InsertAccount.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"

class AccountManager
{
	DISALLOW_COPY(AccountManager);
public:
	AccountManager (yap::DatabaseManager& dm);
	~AccountManager ();

	void CreateNewAccount (
		const yap::String& name,
		const yap::String& password,
		const yap::String& email,
		const yap::String& creationIp);
	yap::ID GetAccountId (const yap::String& name, const yap::String& password);
private:
	yap::DatabaseManager& databaseManager_;
};

#endif // YAPOG_ACCOUNTMANAGER_HPP