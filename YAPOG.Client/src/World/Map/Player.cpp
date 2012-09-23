#include "World/Map/Player.hpp"

#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"

namespace ycl
{
  const yap::String Player::OBJECT_FACTORY_TYPE_NAME = "Player";

  const yap::String Player::DEFAULT_NAME = "<UNKOWN_PLAYER>";

  Player::Player (const yap::ID& id)
    : Character (id)
    , name_ (DEFAULT_NAME)
    , dialogManager_ (nullptr)
  {
  }

  Player::~Player ()
  {
  }

  Player::Player (const Player& copy)
    : Character (copy)
    , name_ (copy.name_)
    , dialogManager_ (nullptr)
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

  void Player::SetDialogManager (yap::IDialogManager& dialogManager)
  {
    dialogManager_ = &dialogManager;
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
    return true;
  }

  void Player::Talk (yap::IDialogActor& dialogActor)
  {
    // Does nothing, server side only.
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

  const yap::String& Player::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }
} // namespace ycl
