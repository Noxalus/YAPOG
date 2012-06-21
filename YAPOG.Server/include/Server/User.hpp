#ifndef YAPOG_SERVER_USER_HPP
# define YAPOG_SERVER_USER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"

namespace yap
{
  class GameMessage;
} // namespace yap

namespace yse
{
  class World;
  class Map;
  class Player;

  class User : public yap::IPacketHandler
  {
      DISALLOW_COPY(User);

    public:

      User ();
      virtual ~User ();

      void ChangeMap (
        const yap::ID& mapWorldID,
        const yap::Vector2& mapPoint);

      World& GetWorld ();
      Map& GetMap ();

      void SetWorld (World* world);
      void RemoveFromWorld ();

      const yap::String& GetLogin () const;
      bool Login (
        const yap::String& login, 
        const yap::String& password, 
        const yap::String& ip);

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      virtual bool SendPacket (yap::IPacket& packet);

      virtual void AddRelay (yap::IPacketHandler* relay);
      virtual void RemoveRelay (yap::IPacketHandler* relay);
      virtual void SetParent (yap::IPacketHandler* parent);
      /// @}

    private:

      void SetMap (Map* map);

      void SetPlayer (Player* player);

      void HandleClientRequestStartInfo (yap::IPacket& packet);
      void HandleClientInfoApplyForce (yap::IPacket& packet);

      void HandleClientInfoGameMessage (yap::IPacket& packet);

      void SendChangeMap (Map& map);

      void SendGameMessage (const yap::GameMessage& message);

      yap::PacketHandler packetHandler_;

      yap::String login_;

      World* world_;
      Map* map_;
      Player* player_;
  };
} // namespace yse

#endif // YAPOG_SERVER_USER_HPP
