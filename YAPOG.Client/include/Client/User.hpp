#ifndef YAPOG_CLIENT_USER_HPP
# define YAPOG_CLIENT_USER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  class GameMessage;
} // namespace yap

namespace ycl
{
  class World;
  class Map;
  class Player;
  class PlayerTrainer;

  class User : public yap::IPacketHandler
  {
      DISALLOW_COPY(User);

    public:

      User ();
      virtual ~User ();


      PlayerTrainer& GetTrainer ();
      void SetTrainer (PlayerTrainer* trainer);

      const yap::String& GetLogin () const;
      void SetLogin (const yap::String& login);

      void SetWorld (World* world);

      void SendGameMessage (const yap::GameMessage& message);

      /// @name IPacketHandler members.
      /// @{
      virtual bool HandlePacket (yap::IPacket& packet);
      virtual bool SendPacket (yap::IPacket& packet);

      virtual void AddRelay (yap::IPacketHandler* relay);
      virtual void RemoveRelay (yap::IPacketHandler* relay);
      virtual void SetParent (yap::IPacketHandler* parent);
      /// @}

      yap::Event<const User&, Player*> OnPlayerCreated;
      yap::Event<const User&, Player&> OnPlayerWarped;
      yap::Event<const User&, const yap::GameMessage&> OnMessageReceived;

      yap::Event<const User&> OnBattleTriggered;

    private:
      /// @name Getters.
      /// @{
      World& GetWorld ();
      Map& GetMap ();

      Player& GetPlayer ();
      /// @}

      /// @name Setters.
      /// @{
      void SetPlayer (Player* player);
      /// @}

      void HandleServerInfoSetUserPlayer (yap::IPacket& packet);
      void HandleServerInfoChangeMap (yap::IPacket& packet);

      void HandleServerInfoAddObject (yap::IPacket& packet);
      void HandleServerInfoRemoveObject (yap::IPacket& packet);

      void HandleServerInfoGameMessage (yap::IPacket& packet);

      void HandleServerInfoTriggerBattle (yap::IPacket& packet);

      yap::PacketHandler packetHandler_;

      yap::String login_;

      World* world_;

      Player* player_;

      PlayerTrainer* trainer_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_USER_HPP
