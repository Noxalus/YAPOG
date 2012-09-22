#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"
#include "YAPOG/System/Network/IPacket.hpp"
#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/Game/World/Map/WorldObject.hpp"

#include "World/Map/Player.hpp"
#include "Server/User.hpp"
#include "World/World.hpp"
#include "World/Map/Map.hpp"
#include "Pokemon/Pokemon.hpp"

namespace yse
{
  const yap::String Player::OBJECT_FACTORY_TYPE_NAME = "Player";

  const yap::String Player::DEFAULT_NAME = "<UNKNOWN_PLAYER>";

  Player::Player (const yap::ID& id)
    : Character (id)
    , parentUser_ (nullptr)
    , name_ (DEFAULT_NAME)
    , packetHandler_ ()
    , inputManager_ ()
  {
    InitHandlers ();
  }

  Player::~Player ()
  {
  }

  Player::Player (const Player& copy)
    : Character (copy)
    , parentUser_ (nullptr)
    , name_ (copy.name_)
    , packetHandler_ ()
    , inputManager_ ()
  {
    InitHandlers ();
  }

  Player* Player::Clone () const
  {
    return new Player (*this);
  }

  void Player::SetParentUser (User* parentUser)
  {
    parentUser_ = parentUser;
  }

  void Player::SetName (const yap::String& name)
  {
    name_ = name;
  }

  bool Player::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool Player::SendPacket (yap::IPacket& packet)
  {
    return packetHandler_.SendPacket (packet);
  }

  void Player::AddRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.AddRelay (relay);
  }

  void Player::RemoveRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.RemoveRelay (relay);
  }

  void Player::SetParent (yap::IPacketHandler* parent)
  {
    packetHandler_.SetParent (parent);
  }

  void Player::Accept (yap::IDynamicWorldObjectVisitor& visitor)
  {
    Character::Accept (visitor);

    visitor.VisitPlayer (*this);
  }

  void Player::Accept (
    yap::IDynamicWorldObjectConstVisitor& visitor) const
  {
    Character::Accept (visitor);

    visitor.VisitPlayer (*this);
  }

  const yap::String& Player::GetName () const
  {
    return name_;
  }

  bool Player::HasInput (yap::GameInputType gameInputType) const
  {
    return inputManager_.InputIsActive (gameInputType);
  }

  void Player::Warp (const yap::ID& mapWorldID, const yap::Vector2& point)
  {
    GetParent ().ChangeMap (mapWorldID, point);
  }

  void Player::DestroyObject (const yap::ID& objectWorldID)
  {
    GetParent ().GetMap ().RemoveObject (objectWorldID);
  }

  void Player::TriggerBattle ()
  {
    SetInactive ();

    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ServerInfoTriggerBattle);

    // Create a random wild Pokemon
    Pokemon* pokemon = GenerateRandomPokemon ();

    // Write the Pokemon's basic information in the packet
    WriteOpponentPokemon (packet, pokemon);

    SendPacket (packet);
  }

  yap::Event<
    yap::DynamicWorldObject&,
    const yap::Vector2&>& Player::OnMovedEvent ()
  {
    return OnMoved;
  }

  const yap::String& Player::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }

  void Player::InitHandlers ()
  {
    ADD_HANDLER(ClientInfoGameInput, Player::HandleClientInfoGameInput);
  }

  User& Player::GetParent ()
  {
    return *parentUser_;
  }

  void Player::HandleClientInfoGameInput (yap::IPacket& packet)
  {
    yap::GameInputType gameInputType = static_cast<yap::GameInputType> (
      packet.ReadInt16 ());

    bool state = packet.ReadBool ();

    inputManager_.SetInputState (gameInputType, state);
  }

  Pokemon* Player::GenerateRandomPokemon ()
  {
    yap::ID staticID = yap::ID (yap::RandomHelper::GetNext (1, 10));

    if (staticID == yap::ID (10))
      staticID = yap::ID (16);

    int level = yap::RandomHelper::GetNext (1, 100);
    Pokemon* p = new Pokemon (staticID, level, false);

    return p;
  }

  void Player::WriteOpponentPokemon (yap::Packet& packet, Pokemon* pokemon)
  {
    // Write the Pokemon's basic information in the packet
    packet.Write (pokemon->GetStaticID ());
    packet.Write (static_cast<yap::UInt8>(pokemon->GetGender ()));
    packet.Write (pokemon->GetShiny ());
    packet.Write (pokemon->GetNatureID ());
    packet.Write (pokemon->GetTotalExperience ());

    // Write the current Pokemon's stats
    const yap::PokemonStat& stats = pokemon->GetStats ();

    // Send IV
    packet.Write (stats.GetHitPoint ().GetIndividualValue ());
    packet.Write (stats.GetAttack ().GetIndividualValue ());
    packet.Write (stats.GetDefense ().GetIndividualValue ());
    packet.Write (stats.GetSpecialAttack ().GetIndividualValue ());
    packet.Write (stats.GetSpecialDefense ().GetIndividualValue ());
    packet.Write (stats.GetSpeed ().GetIndividualValue ());

    // Send Pokemon's moves
    const yap::PokemonMoveSet& moveSet =
      pokemon->GetMoveSet ();
    yap::UInt8 moveNumber = pokemon->GetMoveSet ().GetMoveNumber ();

    // Send the move number of the Pokemon
    packet.Write (moveNumber);

    for (yap::UInt8 index = 0; index < 4; index++)
    {
      if (moveSet.GetMove (index) != nullptr)
      {
        packet.Write (moveSet.GetMove (index)->GetStaticID ());
        packet.Write (index);
        packet.Write (moveSet.GetMove (index)->GetCurrentPP ());
        packet.Write (moveSet.GetMove (index)->GetMaxPP ());
      }
    }
  }

} // namespace yse
