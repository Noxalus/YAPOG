#ifndef YAPOG_SERVER_PLAYER_HPP
# define YAPOG_SERVER_PLAYER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/Game/World/Map/IPlayer.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"

# include "World/Map/Character.hpp"
# include "World/Map/PlayerInputManager.hpp"
# include "World/Map/Dialog/DialogManager.hpp"

namespace yse
{
  class User;

  class Player : public Character
               , public yap::IPacketHandler
               , public yap::IPlayer
  {
      DISALLOW_ASSIGN(Player);

    public:

      explicit Player (const yap::ID& id);
      virtual ~Player ();

      void SetParentUser (User* parent);

      void SetName (const yap::String& name);

      void InitDialogManager ();

      /// @name ICloneable members.
      /// @{
      virtual Player* Clone () const;
      /// @}

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      virtual bool SendPacket (yap::IPacket& packet);

      virtual void AddRelay (yap::IPacketHandler* relay);
      virtual void RemoveRelay (yap::IPacketHandler* relay);
      virtual void SetParent (yap::IPacketHandler* parent);
      /// @}

      /// @name IDialogActor members.
      /// @{
      virtual const yap::String& GetName () const;

      virtual const yap::ID& GetWorldID () const;

      virtual bool CanTalk (yap::IDialogActor& dialogActor) const;

      virtual void Talk (yap::IDialogActor& dialogActor);

      virtual bool TryStartDialog (yap::IDialogManager& dialogManager);
      /// @}

      /// @name IPlayer members.
      /// @{
      virtual void Accept (yap::IDynamicWorldObjectVisitor& visitor);
      virtual void Accept (
        yap::IDynamicWorldObjectConstVisitor& visitor) const;

      virtual bool HasInputActivated (yap::GameInputType gameInputType) const;
      virtual bool HasInputDeactivated (
        yap::GameInputType gameInputType) const;
      virtual bool HasInputActive (yap::GameInputType gameInputType) const;

      virtual void Warp (const yap::ID& mapWorldID, const yap::Vector2& point);

      virtual void DestroyObject (const yap::ID& objectWorldID);

      virtual void TriggerBattle ();

      virtual yap::Event<
        yap::DynamicWorldObject&,
        const yap::Vector2&>& OnMovedEvent ();
      /// @}

    protected:

      Player (const Player& copy);

      virtual const yap::String& GetObjectFactoryTypeName () const;

      virtual void HandleUpdate (const yap::Time& dt);

    private:

      void InitHandlers ();

      User& GetParent ();

      void HandleClientInfoGameInput (yap::IPacket& packet);

      static const yap::String OBJECT_FACTORY_TYPE_NAME;

      static const yap::String DEFAULT_NAME;

      User* parentUser_;

      yap::String name_;

      yap::PacketHandler packetHandler_;

      PlayerInputManager inputManager_;

      DialogManager dialogManager_;
  };
} // namespace yse

#endif // YAPOG_SERVER_PLAYER_HPP
