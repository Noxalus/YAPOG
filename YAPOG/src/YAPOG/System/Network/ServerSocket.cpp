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
    return listener_.listen (port) == sf::Socket::Done;
  }

  bool ServerSocket::Accept (ClientSocket& client)
  {
    return listener_.accept (client.GetInnerSocket ()) == sf::Socket::Done;
  }
} // namespace yap
