#ifndef YAPOG_INSERTACCOUNT_HPP
# define YAPOG_INSERTACCOUNT_HPP

# include "YAPOG/Macros.hpp"
# include "Database/IInsertTable.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"

class Account;

class InsertAccount : public IInsertTable
{
  DISALLOW_COPY(InsertAccount);
public:
  InsertAccount (const Account& account);
  virtual ~InsertAccount();

  const yap::ID& GetID ();

  /// @name ISpatial members.
  /// @{
  virtual bool Add (yap::DatabaseManager& databaseManager);
  /// @}
private:
  yap::ID id_;
  const Account& account_;
};

#endif // YAPOG_INSERTACCOUNT_HPP