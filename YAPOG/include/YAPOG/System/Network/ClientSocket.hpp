#ifndef YAPOG_CLIENTSOCKET_HPP
# define YAPOG_CLIENTSOCKET_HPP

# include <SFML/Network/TcpSocket.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/Socket.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  struct IPacket;

  class YAPOG_LIB ClientSocket : public Socket
  {
      DISALLOW_COPY(ClientSocket);

    public:

      ClientSocket ();
      virtual ~ClientSocket ();

      bool Connect (const String& ipAddress, Int16 port);
      void Disconnect ();

      bool Send (IPacket& packet);
      bool Receive (IPacket& packet);

      sf::TcpSocket& GetInnerSocket ();

    private:

      sf::TcpSocket socket_;
  };
} // namespace yap

#endif // YAPOG_CLIENTSOCKET_HPP
