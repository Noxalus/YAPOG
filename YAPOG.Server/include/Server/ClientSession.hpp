#ifndef YAPOG_CLIENTSESSION_HPP
# define YAPOG_CLIENTSESSION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/System/Network/IPacketSender.hpp"
# include "YAPOG/System/Network/ClientSocket.hpp"

namespace yse
{
  class ClientSession : public yap::IPacketHandler
                      , public yap::IPacketSender
  {
      DISALLOW_COPY(ClientSession);

    public:

      ClientSession ();
      virtual ~ClientSession ();

      yap::ClientSocket& GetSocket ();

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      /// @}

      /// @name IPacketSender members.
      /// @{
      virtual bool SendPacket (yap::IPacket& packet);
      /// @}

    private:

      void HandleNone (yap::IPacket& packet);

      yap::PacketHandler packetHandler_;

      yap::ClientSocket socket_;
  };
} // namespace yap

#endif // YAPOG_CLIENTSESSION_HPP
