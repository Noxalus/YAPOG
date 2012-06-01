#ifndef YAPOG_CLIENT_USER_HPP
# define YAPOG_CLIENT_USER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace ycl
{
  class World;
  class Player;

  class User : public yap::IPacketHandler
  {
      DISALLOW_COPY(User);

    public:

      User ();
      virtual ~User ();

      void SetWorld (World* world);

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      virtual bool SendPacket (yap::IPacket& packet);

      virtual void AddRelay (yap::IPacketHandler* relay);
      virtual void RemoveRelay (yap::IPacketHandler* relay);
      virtual void SetParent (yap::IPacketHandler* parent);
      /// @}

      yap::Event<const User&, Player*> OnPlayerCreated;

    private:

      World& GetWorld ();

      void SetPlayer (Player* player);

      void HandleServerInfoStartInfo (yap::IPacket& packet);
      void HandleServerInfoChangeMap (yap::IPacket& packet);

      /// @todo Move into Map.
      void HandleServerInfoAddObject (yap::IPacket& packet);
      /// @todo Move into Map.
      void HandleServerInfoAddPlayer (yap::IPacket& packet);

      yap::PacketHandler packetHandler_;

      World* world_;

      yap::ID playerWorldID_;
      Player* player_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_USER_HPP
