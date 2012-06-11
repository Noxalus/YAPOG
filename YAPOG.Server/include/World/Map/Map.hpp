#ifndef YAPOG_SERVER_MAP_HPP
# define YAPOG_SERVER_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Map.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/Collection/Map.hpp"

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

      void AddObject (yap::DynamicWorldObject* object);
      void RemoveObject (yap::DynamicWorldObject* object);

      void AddObject (yap::StaticWorldObject* object);
      void RemoveObject (yap::StaticWorldObject* object);

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
      void HandleOnObjectStateChanged (
        yap::DynamicWorldObject& sender,
        const yap::String& oldState,
        const yap::String& currentState);

      void SendObjectMoveInfo (
        const yap::DynamicWorldObject& object,
        const yap::Vector2& velocity);
      void SendUpdateObjectState (
        const yap::DynamicWorldObject& object,
        const yap::String& state);

      void SendAddObject (const yap::DynamicWorldObject& object);
      void SendRemoveObject (const yap::DynamicWorldObject& object);

      static const yap::String VELOCITY_CHANGED_SYNCHRONIZATION_HANDLER_NAME;
      static const yap::String STATE_CHANGED_SYNCHRONIZATION_HANDLER_NAME;

      yap::collection::Map<yap::ID, Player*> players_;

      yap::PacketHandler packetHandler_;
  };
} // namespace yse

#endif // YAPOG_MAP_HPP
