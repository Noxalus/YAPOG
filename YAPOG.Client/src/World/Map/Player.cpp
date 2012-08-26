#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"

#include "World/Map/Player.hpp"

namespace ycl
{
  const yap::String Player::OBJECT_FACTORY_TYPE_NAME = "Player";

  const yap::String Player::DEFAULT_NAME = "<UNKOWN_PLAYER>";

  Player::Player (const yap::ID& id)
    : Character (id)
    , name_ (DEFAULT_NAME)
  {
  }

  Player::~Player ()
  {
  }

  Player::Player (const Player& copy)
    : Character (copy)
    , name_ (copy.name_)
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

  void Player::Accept (yap::IDynamicWorldObjectVisitor& visitor)
  {
    visitor.VisitCharacter (*this);
    visitor.VisitPlayer (*this);
  }

  void Player::Accept (
    yap::IDynamicWorldObjectConstVisitor& visitor) const
  {
    visitor.VisitCharacter (*this);
    visitor.VisitPlayer (*this);
  }

  const yap::String& Player::GetName () const
  {
    return name_;
  }

  bool Player::HasInput (yap::GameInputType gameInputType) const
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
