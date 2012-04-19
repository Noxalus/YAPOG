#ifndef YAPOG_ACCOUNTTABLE_HPP
# define YAPOG_ACCOUNTTABLE_HPP

# include "YAPOG/System/Time/DateTime.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Macros.hpp"
# include "Database/ITable.hpp"
# include "YAPOG/System/IntTypes.hpp"

class AccountTable : public ITable
{
	DISALLOW_COPY(AccountTable);

public:
	AccountTable ();
	AccountTable(const yap::ID& id,
		const yap::String& name,
		const yap::String& email,
		const yap::String& password,
		const yap::Int16& permissions,
		const yap::DateTime& creationDate,
		const yap::DateTime& lastLoginDate,
		const yap::String& creationIp,
		const yap::String& currentIp);
	virtual ~AccountTable();

	void SetName(yap::String name) { name_ = name; }

	/// @name ISpatial members.
	/// @{
	virtual yap::ID& Add (yap::DatabaseManager dM) const;
	virtual bool Remove (yap::DatabaseManager dM) const;
	virtual int GetInt (yap::DatabaseManager dM, const yap::String& columnName) const;
	virtual yap::DateTime& GetDate (yap::DatabaseManager dM, const yap::String& columnName) const;
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

#endif // YAPOG_ITABLE_HPP