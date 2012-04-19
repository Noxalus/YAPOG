#include "Database/Tables/AccountTable.hpp"

AccountTable::AccountTable ()
{
}

AccountTable::AccountTable (const yap::ID& id,
														const yap::String& name,
														const yap::String& email,
														const yap::String& password,
														const yap::Int16& permissions,
														const yap::DateTime& creationDate,
														const yap::DateTime& lastLoginDate,
														const yap::String& creationIp,
														const yap::String& currentIp)
														: id_ (id),
														name_ (name),
														email_ (email),
														password_ (password),
														permissions_ (permissions),
														creationDate_ (creationDate),
														lastLoginDate_ (lastLoginDate),
														creationIp_ (creationIp),
														currentIp_ (currentIp)
{
}

AccountTable::~AccountTable ()
{
}

yap::ID& AccountTable::Add (yap::DatabaseManager dM) const
{
	try
	{
		pg_stream query ("INSERT INTO account (account_name, account_password) VALUES (:name, 'test')", dM.GetConnexion ());
		query << name_;

		
		int id = 0;
		query >> id;
		std::cout << "ID: " << id;
	}
	catch (pg_excpt e)
	{
		std::cerr << e.errmsg ();
	}

	return yap::ID ();
}

bool AccountTable::Remove (yap::DatabaseManager dM) const
{
	return false;
}

int AccountTable::GetInt (yap::DatabaseManager dM, const yap::String& columnName) const
{
	return -1;
}

yap::DateTime& AccountTable::GetDate (yap::DatabaseManager dM, const yap::String& columnName) const
{
	return yap::DateTime (yap::DateTime::InnerTimeType ());
}