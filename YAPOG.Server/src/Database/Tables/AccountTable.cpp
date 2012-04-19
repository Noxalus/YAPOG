#include "Database/Tables/AccountTable.hpp"

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

yap::ID AccountTable::Add () const
{
	return yap::ID ();
}

bool AccountTable::Remove () const
{
	return false;
}

int AccountTable::GetInt (const yap::String& columnName) const
{
	return -1;
}

yap::DateTime AccountTable::GetDate (const yap::String& columnName) const
{
	return yap::DateTime (yap::DateTime::InnerTimeType ());
}