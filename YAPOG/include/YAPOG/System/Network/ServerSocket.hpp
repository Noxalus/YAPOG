#ifndef YAPOG_SERVERSOCKET_HPP
# define YAPOG_SERVERSOCKET_HPP

# include <SFML/Network/TcpListener.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/Socket.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class ClientSocket;

  class ServerSocket : public Socket
  {
      DISALLOW_COPY(ServerSocket);

    public:

      ServerSocket ();
      virtual ~ServerSocket ();

      bool Listen (Int16 port);

      bool Accept (ClientSocket& client);

    private:

      sf::TcpListener listener_;
  };
} // namespace yap

#endif // YAPOG_SERVERSOCKET_HPP
