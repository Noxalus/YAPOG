#ifndef YAPOG_SERVER_CLIENTSESSION_HPP
# define YAPOG_SERVER_CLIENTSESSION_HPP

# include <SFML/Network/SocketSelector.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/System/Network/ClientSocket.hpp"
# include "YAPOG/System/Network/NetworkHandler.hpp"

# include "Server/User.hpp"

namespace yse
{
  class ClientSession : public yap::IPacketHandler
  {
      DISALLOW_COPY(ClientSession);

    public:

      ClientSession ();
      virtual ~ClientSession ();

      void Init ();

      void Refresh ();

      void HandleReception ();

      yap::ClientSocket& GetSocket ();

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      virtual bool SendPacket (yap::IPacket& packet);

      virtual void AddRelay (yap::IPacketHandler* relay);
      virtual void SetParent (yap::IPacketHandler* parent);
      /// @}

    private:

      void HandleClientInfoDeconnection (yap::IPacket& packet);

      yap::PacketHandler packetHandler_;

      yap::ClientSocket socket_;
      yap::NetworkHandler networkHandler_;

      User user_;
  };
} // namespace yap

#endif // YAPOG_SERVER_CLIENTSESSION_HPP
