#include "YAPOG/System/Network/ServerSocket.hpp"
#include "YAPOG/System/Network/ClientSocket.hpp"

namespace yap
{
  ServerSocket::ServerSocket ()
    : Socket ()
    , listener_ ()
  {
  }

  ServerSocket::~ServerSocket ()
  {
  }

  bool ServerSocket::Listen (Int16 port)
  {
    return listener_.listen (port) == VALID_STATUS;
  }

  bool ServerSocket::Accept (ClientSocket& client)
  {
    return listener_.accept (client.GetInnerSocket ()) == VALID_STATUS;
  }
} // namespace yap
