#include "World/Map/Player.hpp"

#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"
#include "YAPOG/Game/World/Map/Dialog/WriterDialogDisplay.hpp"
#include "YAPOG/System/IO/Log/DebugLogger.hpp"

namespace ycl
{
  const yap::String Player::OBJECT_FACTORY_TYPE_NAME = "Player";

  const yap::String Player::DEFAULT_NAME = "<UNKOWN_PLAYER>";

  Player::Player (const yap::ID& id)
    : Character (id)
    , packetHandler_ ()
    , name_ (DEFAULT_NAME)
    , dialogManager_ ()
  {
  }

  Player::~Player ()
  {
  }

  Player::Player (const Player& copy)
    : Character (copy)
    , packetHandler_ ()
    , name_ (copy.name_)
    , dialogManager_ ()
  {
  }

  Player* Player::Clone () const
  {
    return new Player (*this);
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
      new yap::WriterDialogDisplay (
        yap::DebugLogger::Instance ()));
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
    dialogActor.Talk (*this);

    dialogManager_.AddListener (*this);

    dialogActor.TryStartDialog (dialogManager_);
  }

  void Player::StopListening ()
  {
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
    // Does nothing, server side only.

    return false;
  }

  bool Player::HasInputDeactivated (yap::GameInputType gameInputType) const
  {
    // Does nothing, server side only.

    return false;
  }

  bool Player::HasInputActive (yap::GameInputType gameInputType) const
  {
    // Does nothing, server side only.

    return false;
  }

  void Player::Warp (const yap::ID& mapWorldID, const yap::Vector2& point)
  {
    // Does nothing, server side only.
  }

  void Player::DestroyObject (const yap::ID& objectWorldID)
  {
    // Does nothing, server side only.
  }

  void Player::TriggerBattle ()
  {
    // Does nothing, server side only.
  }

  yap::Event<
    yap::DynamicWorldObject&,
    const yap::Vector2&>& Player::OnMovedEvent ()
  {
    return OnMoved;
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

  const yap::String& Player::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }
} // namespace ycl
