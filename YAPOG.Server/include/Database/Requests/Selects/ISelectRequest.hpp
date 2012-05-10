#ifndef YAPOG_ISELECTREQUEST_HPP
# define YAPOG_ISELECTREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "Database/Requests/IRequest.hpp"

namespace yse
{
  struct ISelectRequest : public IRequest
  {
      virtual ~ISelectRequest () {}
  };
} // namespace yse

#endif // YAPOG_ISELECTREQUEST_HPP