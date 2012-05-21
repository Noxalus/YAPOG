#ifndef YAPOG_CLIENTSOCKET_HPP
# define YAPOG_CLIENTSOCKET_HPP

# include <SFML/Network/TcpSocket.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/Socket.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/Time/Time.hpp"

namespace yap
{
  struct IPacket;

  class YAPOG_LIB ClientSocket : public Socket
  {
      DISALLOW_COPY(ClientSocket);

    public:

      ClientSocket ();
      virtual ~ClientSocket ();

      bool Connect (const String& ipAddress, UInt16 port);
      void Disconnect ();

      bool Send (IPacket& packet);
      bool Receive (IPacket& packet);

      String GetRemoteAddress () const;
      UInt16 GetRemotePort () const;

      sf::TcpSocket& GetInnerSocket ();

    private:

      static const bool DEFAULT_BLOCKING_STATE;
      static const Time DEFAULT_CONNECTION_TIMEOUT;

      sf::TcpSocket socket_;
  };
} // namespace yap

#endif // YAPOG_CLIENTSOCKET_HPP
