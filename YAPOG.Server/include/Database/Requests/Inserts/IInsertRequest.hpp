#ifndef YAPOG_IINSERTABLE_HPP
# define YAPOG_IINSERTABLE_HPP

# include "YAPOG/Database/DatabaseManager.hpp"
# include "Database/Requests/IRequest.hpp"

namespace yse
{
  struct IInsertRequest : public IRequest
  {
    virtual ~IInsertRequest () {};

    virtual bool Insert (yap::DatabaseManager& databaseManager) = 0;
  };
} /// namespace yse

#endif // YAPOG_ITABLE_HPP