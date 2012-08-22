#ifndef YAPOG_DATABASETRANSACTION_HPP
# define YAPOG_DATABASETRANSACTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IWriter.hpp"
# include "YAPOG/System/IO/IReader.hpp"
# include "pgstream/pgstream.hpp"

namespace yap
{
  class YAPOG_LIB DatabaseTransaction
  {
    DISALLOW_COPY(DatabaseTransaction);
  public:
    DatabaseTransaction (pgs::pg_cnx& databaseConnection);

    /// @name pg_trans methods.
    /// @{ 
    void Commit();
    void RollBack();
    /// @}

  private:
    pgs::pg_trans transaction_;
  };
} // namespace yap

#endif // YAPOG_DATABASETRANSACTION_HPP
