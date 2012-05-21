#ifndef YAPOG_SERVER_WORLD_HPP
# define YAPOG_SERVER_WORLD_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/World.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yse
{
  class Map;

  class World : public yap::World
              , public yap::IPacketHandler
  {
      DISALLOW_COPY(World);

    public:

      World ();
      virtual ~World ();

      void LoadMaps ();

      Map& GetMap (const yap::ID& worldID);

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      virtual bool SendPacket (yap::IPacket& packet);

      virtual void AddRelay (yap::IPacketHandler* relay);
      virtual void RemoveRelay (yap::IPacketHandler* relay);
      virtual void SetParent (yap::IPacketHandler* parent);
      /// @}

    private:

      void AddMap (Map* map);
      void RemoveMap (const yap::ID& worldID);

      virtual void HandleUpdate (const yap::Time& dt);

      yap::collection::Map<yap::ID, Map*> maps_;

      yap::PacketHandler packetHandler_;
  };
} // namespace yap

#endif // YAPOG_SERVER_WORLD_HPP
