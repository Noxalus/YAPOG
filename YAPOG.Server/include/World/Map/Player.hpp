#ifndef YAPOG_SERVER_PLAYER_HPP
# define YAPOG_SERVER_PLAYER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/Game/World/Map/IPlayer.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"

# include "World/Map/Character.hpp"

namespace yse
{
  struct IDynamicWorldObjectVisitor;
  struct IDynamicWorldObjectConstVisitor;

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

      /// @name IPlayer members.
      /// @{
      virtual void Accept (yap::IDynamicWorldObjectVisitor& visitor);
      virtual void Accept (
        yap::IDynamicWorldObjectConstVisitor& visitor) const;

      virtual void Warp (const yap::ID& mapWorldID, const yap::Vector2& point);
      /// @}

    protected:

      Player (const Player& copy);

      const yap::String& GetObjectFactoryTypeName () const;

    private:

      User& GetParent ();

      static const yap::String OBJECT_FACTORY_TYPE_NAME;

      User* parentUser_;

      yap::PacketHandler packetHandler_;
  };
} // namespace yse

#endif // YAPOG_SERVER_PLAYER_HPP
