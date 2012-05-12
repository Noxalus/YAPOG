#ifndef YAPOG_SERVER_MAP_HPP
# define YAPOG_SERVER_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Map.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/System/Network/IPacketSender.hpp"
# include "YAPOG/System/Network/PacketSender.hpp"

namespace yse
{
  class Map : public yap::Map
            , public yap::IPacketHandler
            , public yap::IPacketSender
  {
      DISALLOW_COPY(Map);

    public:

      Map (const yap::ID& id);
      virtual ~Map ();

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      /// @}

      /// @name IPacketSender members.
      /// @{
      virtual bool SendPacket (yap::IPacket& packet);
      /// @}

    private:

      yap::PacketHandler packetHandler_;
      yap::PacketSender packetSender_;
  };
} // namespace yse

#endif // YAPOG_MAP_HPP
