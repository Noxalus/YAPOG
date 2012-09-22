#ifndef YAPOG_CLIENT_USER_HPP
# define YAPOG_CLIENT_USER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/System/Event/Event.hpp"

#include  "Client/PlayerData.hpp"

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
  class BattleParameters;
  class Pokemon;

  class User : public yap::IPacketHandler
  {
    DISALLOW_COPY(User);

  public:

    User ();
    virtual ~User ();

    /// @name Public getters.
    /// @{
    PlayerTrainer& GetTrainer () const;
    void SetTrainer (PlayerTrainer* trainer);

    const yap::String& GetLogin () const;
    const yap::ID& GetID () const;

    const PlayerData& GetPlayerData () const;

    BattleParameters& GetBattleParameters () const;
    /// @}

    /// @name Public setters.
    /// @{
    void SetLogin (const yap::String& login);

    void SetWorld (World* world);

    void SendGameMessage (const yap::GameMessage& message);

     void SetBattleParameters (BattleParameters* value);
     /// @}

    void ChangeMoney (int value);
    void UpdatePlayTime (const yap::Time& dt);

    Pokemon* GetPlayerPokemonFromServer (yap::IPacket& packet);
    Pokemon* GetOpponentPokemonFromServer (yap::IPacket& packet);

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

    yap::Event<User&, yap::IPacket&> OnBattleTriggered;
    yap::Event<const User&> OnPokemonTeamReceived;
    yap::Event<User&> OnPlayerDataReceived;

  private:
    /// @name Private getters.
    /// @{
    World& GetWorld ();
    Map& GetMap ();

    Player& GetPlayer ();
    /// @}

    /// @name Private setters.
    /// @{
    void SetPlayer (Player* player);
    /// @}

    void HandleServerInfoSetUserPlayer (yap::IPacket& packet);
    void HandleServerInfoChangeMap (yap::IPacket& packet);

    void HandleServerInfoAddObject (yap::IPacket& packet);
    void HandleServerInfoRemoveObject (yap::IPacket& packet);

    void HandleServerInfoGameMessage (yap::IPacket& packet);

    void HandleServerInfoTriggerBattle (yap::IPacket& packet);

    void HandlerServerInfoPokemonTeam (yap::IPacket& packet);

    void HandlerServerInfoChangeMoney (yap::IPacket& packet);

    yap::PacketHandler packetHandler_;

    yap::String login_;
    yap::ID id_;

    World* world_;

    Player* player_;
    PlayerData playerData_;

    PlayerTrainer* trainer_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_USER_HPP
