#ifndef YAPOG_SERVER_MAP_HPP
# define YAPOG_SERVER_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Map.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"

namespace yse
{
  class Player;

  /// @brief Server side Map.
  /// Enabled to send packets to all player inside it.
  class Map : public yap::Map
            , public yap::IPacketHandler
  {
      DISALLOW_COPY(Map);

    public:

      Map (const yap::ID& id);
      virtual ~Map ();

      /// @brief Adds Player @a player to this Map.
      /// @param player Player to add to this Map.
      void AddPlayer (Player* player);
      /// @brief Removes Player @a player from this Map.
      /// @param player Player to remove from this Map.
      void RemovePlayer (Player* player);

      void SendLoadObjects (yap::IPacket& packet);

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
      virtual void HandleRemoveDynamicObject (yap::DynamicWorldObject* object);

    private:

      void HandleOnObjectVelocityChanged (
        yap::DynamicWorldObject& sender,
        const yap::Vector2& oldVelocity,
        const yap::Vector2& currentVelocity);

      /// @todo Visitors for all Send methods...
      void SendObjectMoveInfo (
        const yap::DynamicWorldObject& object,
        const yap::Vector2& velocity);

      void SendAddObject (
        const yap::DynamicWorldObject& object,
        yap::IPacket& packet);
      void SendRemoveObject (
        const yap::DynamicWorldObject& object,
        yap::IPacket& packet);

      void SendAddPlayer (const Player& player);
      void SendRemovePlayer (const Player& player);

      static const yap::String VELOCITY_CHANGED_SYNCHRONIZATION_HANDLER_NAME;

      yap::collection::List<Player*> players_;

      yap::PacketHandler packetHandler_;
  };
} // namespace yse

#endif // YAPOG_MAP_HPP
