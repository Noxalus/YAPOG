#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"

#include "World/Map/Player.hpp"

namespace ycl
{
  const yap::String Player::OBJECT_FACTORY_TYPE_NAME = "Player";

  Player::Player (const yap::ID& id)
    : Character (id)
  {
  }

  Player::~Player ()
  {
  }

  Player::Player (const Player& copy)
    : Character (copy)
  {
  }

  Player* Player::Clone () const
  {
    return new Player (*this);
  }

  void Player::Accept (yap::IDynamicWorldObjectVisitor& visitor)
  {
    visitor.VisitPlayer (*this);
  }

  void Player::Accept (
    yap::IDynamicWorldObjectConstVisitor& visitor) const
  {
    visitor.VisitPlayer (*this);
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

  const yap::String& Player::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }
} // namespace ycl
