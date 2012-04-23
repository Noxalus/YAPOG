#ifndef YAPOG_SELECTACCOUNT_HPP
# define YAPOG_SELECTACCOUNT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"
# include "Account/AccountPermission.hpp"

class SelectAccount
{
	DISALLOW_COPY(SelectAccount);

public:
	SelectAccount (yap::DatabaseManager& dm, const yap::String& name);
	void DisplayData ();
	bool IsLogged ();

	/// Getters
	yap::String& GetName () { return name_; }
	yap::String& GetPassword () { return password_; }
	yap::String& GetEmail () { return email_; }
	AccountPermission& GetPermissions () { return permissions_; }
	yap::String& GetCreationDate () { return creationDate_; }
	yap::String& GetLastLoginDate () { return lastLoginDate_; }
	yap::String& GetCreationIp () { return creationIp_; }
	yap::String& GetCurrentIp () { return currentIp_; }

	/// Setters
	void SetCurrentIp (const yap::String& cip);
private:
	yap::ID id_;
	yap::String name_;
	yap::String password_;
	yap::String email_;
	AccountPermission permissions_;
	yap::String creationDate_;
	yap::String lastLoginDate_;
	yap::String creationIp_;
	yap::String currentIp_;
};

#endif // YAPOG_SELECTACCOUNT_HPP