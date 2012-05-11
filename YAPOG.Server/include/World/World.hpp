#ifndef YAPOG_SERVER_WORLD_HPP
# define YAPOG_SERVER_WORLD_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/World.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/System/Network/IPacketSender.hpp"
# include "YAPOG/System/Network/PacketSender.hpp"
# include "YAPOG/Collection/List.hpp"

namespace yse
{
  class Map;

  class World : public yap::World
              , public yap::IPacketHandler
              , public yap::IPacketSender
  {
      DISALLOW_COPY(World);

    public:

      World ();
      virtual ~World ();

      void AddMap (Map* map);

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      /// @}

      /// @name IPacketSender members.
      /// @{
      virtual bool SendPacket (yap::IPacket& packet);
      /// @}

    private:

      yap::collection::List<Map*> maps_;

      yap::PacketHandler packetHandler_;
      yap::PacketSender packetSender_;
  };
} // namespace yap

#endif // YAPOG_SERVER_WORLD_HPP
