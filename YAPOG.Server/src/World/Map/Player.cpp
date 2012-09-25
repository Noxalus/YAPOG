#include "World/Map/Player.hpp"

#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"
#include "YAPOG/System/Network/IPacket.hpp"
#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/Game/World/Map/WorldObject.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogManager.hpp"
#include "YAPOG/Game/World/Map/Dialog/WriterDialogDisplay.hpp"
#include "YAPOG/System/IO/Log/DebugLogger.hpp"

#include "Server/User.hpp"
#include "World/World.hpp"
#include "World/Map/Map.hpp"

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
    , dialogManager_ ()
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
    , dialogManager_ ()
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

  void Player::InitDialogManager ()
  {
    AddRelay (&dialogManager_);
    dialogManager_.SetParent (this);

    dialogManager_.SetDisplay (
      *new yap::WriterDialogDisplay (
        yap::DebugLogger::Instance ()));
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

  const yap::String& Player::GetName () const
  {
    return name_;
  }

  const yap::ID& Player::GetWorldID () const
  {
    return Character::GetWorldID ();
  }

  bool Player::CanTalk (yap::IDialogActor& dialogActor) const
  {
    return false;
  }

  void Player::Talk (yap::IDialogActor& dialogActor)
  {
  }

  void Player::StopTalking ()
  {
  }

  bool Player::CanListen (yap::IDialogActor& dialogActor) const
  {
    return true;
  }

  void Player::Listen (yap::IDialogActor& dialogActor)
  {
    if (!TryChangeState ("Listening"))
      return;

    if (dialogActor.CanTalk (*this))
      dialogActor.Talk (*this);

    dialogManager_.AddListener (*this);

    dialogActor.TryStartDialog (dialogManager_);
  }

  void Player::StopListening ()
  {
    TrySetInactiveFrom ("Listening");
  }

  bool Player::TryStartDialog (yap::IDialogManager& dialogManager)
  {
    return false;
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

  bool Player::HasInputActivated (yap::GameInputType gameInputType) const
  {
    return inputManager_.InputIsActivated (gameInputType);
  }

  bool Player::HasInputDeactivated (yap::GameInputType gameInputType) const
  {
    return inputManager_.InputIsDeactivated (gameInputType);
  }

  bool Player::HasInputActive (yap::GameInputType gameInputType) const
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

  void Player::HandleUpdate (const yap::Time& dt)
  {
    Character::HandleUpdate (dt);

    inputManager_.Refresh ();
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
} // namespace yse
