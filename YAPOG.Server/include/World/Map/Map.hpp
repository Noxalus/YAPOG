#ifndef YAPOG_SERVER_MAP_HPP
# define YAPOG_SERVER_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Map.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"

namespace yse
{
  class Player;

  class Map : public yap::Map
            , public yap::IPacketHandler
  {
      DISALLOW_COPY(Map);

    public:

      Map (const yap::ID& id);
      virtual ~Map ();

      void AddPlayer (Player* player);
      void RemovePlayer (Player* player);

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      virtual bool SendPacket (yap::IPacket& packet);

      virtual void AddRelay (yap::IPacketHandler* relay);
      virtual void RemoveRelay (yap::IPacketHandler* relay);
      virtual void SetParent (yap::IPacketHandler* parent);
      /// @}

    protected:

      virtual void HandleAddDynamicObject (yap::DynamicWorldObject* object);

    private:

      void SendAddPlayer (Player* player);
      void SendRemovePlayer (Player* player);

      yap::collection::List<Player*> players_;

      yap::PacketHandler packetHandler_;
  };
} // namespace yse

#endif // YAPOG_MAP_HPP
