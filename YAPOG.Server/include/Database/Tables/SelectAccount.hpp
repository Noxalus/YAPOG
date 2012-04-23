#ifndef YAPOG_SELECTACCOUNT_HPP
# define YAPOG_SELECTACCOUNT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "YAPOG/System/Time/DateTime.hpp"
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
	yap::Int16& GetPermissions () { return permissions_; }
	yap::DateTime& GetCreationDate () { return creationDate_; }
	yap::DateTime& GetLastLoginDate () { return lastLoginDate_; }
	yap::String& GetCreationIp () { return creationIp_; }
	yap::String& GetCurrentIp () { return currentIp_; }

	/// Setters
	void SetCurrentIp (const yap::String& cip) { currentIp_ = cip; }
private:
	/*yap::ID*/ int id_;
	yap::String name_;
	yap::String password_;
	yap::String email_;
	yap::Int16 permissions_;
	yap::DateTime creationDate_;
	yap::DateTime lastLoginDate_;
	yap::String creationIp_;
	yap::String currentIp_;
};

#endif // YAPOG_SELECTACCOUNT_HPP