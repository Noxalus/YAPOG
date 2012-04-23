#ifndef YAPOG_INSERTACCOUNT_HPP
# define YAPOG_INSERTACCOUNT_HPP

# include "YAPOG/Macros.hpp"
# include "Database/IInsertTable.hpp"
# include "YAPOG/System/Time/DateTime.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"
# include "Account/AccountPermission.hpp"

class InsertAccount : public IInsertTable
{
	DISALLOW_COPY(InsertAccount);

public:
	InsertAccount (const yap::String& name,
		const yap::String& email,
		const yap::String& password,
		const yap::String& creationIp);
	virtual ~InsertAccount();

	void SetName(yap::String name) { name_ = name; }

	/// @name ISpatial members.
	/// @{
	virtual bool Add (yap::DatabaseManager& dM) const;
	/// @}
private:
	yap::ID id_;
	yap::String name_;
	yap::String email_;
	yap::String password_;
	yap::Int16 permissions_;
	yap::DateTime creationDate_;
	yap::DateTime lastLoginDate_;
	yap::String creationIp_;
	yap::String currentIp_;
};

#endif // YAPOG_INSERTACCOUNT_HPP