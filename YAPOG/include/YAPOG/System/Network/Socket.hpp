#ifndef YAPOG_SOCKET_HPP
# define YAPOG_SOCKET_HPP

# include <SFML/Network/Socket.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/ISocket.hpp"

namespace yap
{
  class Socket : public ISocket
  {
      DISALLOW_COPY(Socket);

    public:

      virtual ~Socket ();

    protected:

      Socket ();
  };
} // namespace yap

#endif // YAPOG_SOCKET_HPP
