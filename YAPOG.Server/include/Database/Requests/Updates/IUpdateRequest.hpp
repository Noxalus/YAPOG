#ifndef YAPOG_IUPDATEREQUEST_HPP
# define YAPOG_IUPDATEREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "Database/Requests/IRequest.hpp"

namespace yse
{
  struct IUpdateRequest : public IRequest
  {
      virtual ~IUpdateRequest () {}
      virtual bool Update (yap::DatabaseManager& databaseManager) = 0;
  };
} // namespace yse

#endif // YAPOG_IUPDATEREQUEST_HPP