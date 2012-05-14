#ifndef YAPOG_CLIENT_SESSION_HPP
# define YAPOG_CLIENT_SESSION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/System/Network/ClientSocket.hpp"
# include "YAPOG/System/Network/NetworkHandler.hpp"

namespace ycl
{
  class Session : public yap::IPacketHandler
  {
      DISALLOW_COPY(Session);

    public:

      static Session& Instance ();

      void Refresh ();

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      virtual bool SendPacket (yap::IPacket& packet);

      virtual void AddRelay (yap::IPacketHandler* relay);
      virtual void SetParent (yap::IPacketHandler* parent);
      /// @}

    private:

      Session ();
      virtual ~Session ();

      yap::PacketHandler packetHandler_;

      yap::ClientSocket socket_;
      yap::NetworkHandler networkHandler_;
  };
}

#endif // YAPOG_CLIENT_SESSION_HPP
