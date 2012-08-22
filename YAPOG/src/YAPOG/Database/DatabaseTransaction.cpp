#include "YAPOG/Database/DatabaseTransaction.hpp"

namespace yap
{
  DatabaseTransaction::DatabaseTransaction (pgs::pg_cnx& databaseConnection)
    : transaction_ (databaseConnection)
  {
  }

  /// pg_trans methods
  void DatabaseTransaction::Commit()
  {
    transaction_.commit ();
  }

  void DatabaseTransaction::RollBack()
  {
    transaction_.rollback ();
  }

} // namespace yap