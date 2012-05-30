#include "YAPOG/Game/World/Map/Character.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"

#include "YAPOG/System/IO/Log/DebugLogger.hpp"
#include "YAPOG/System/StringHelper.hpp"
namespace yap
{
  const Direction Character::DEFAULT_DIRECTION = Direction::South;

  Character::Character (const ID& id)
    : DynamicWorldObject (id)
    , direction_ (DEFAULT_DIRECTION)
  {
  }

  Character::~Character ()
  {
  }

  Character::Character (const Character& copy)
    : DynamicWorldObject (copy)
    , direction_ (copy.direction_)
  {
  }

  void Character::Accept (IDynamicWorldObjectVisitor& visitor)
  {
    visitor.Visit (*this);
  }

  void Character::Accept (IDynamicWorldObjectConstVisitor& visitor) const
  {
    visitor.Visit (*this);
  }

  const Direction& Character::GetDirection () const
  {
    return direction_;
  }

  void Character::SetDirection (Direction direction)
  {
    direction_ = direction;

    HandleSetDirection (direction);
  }

  void Character::HandleSetDirection (Direction direction)
  {
  }

  void Character::HandleOnVelocityChanged (
    const Vector2& oldVelocity,
    const Vector2& currentVelocity)
  {
    DynamicWorldObject::HandleOnVelocityChanged (oldVelocity, currentVelocity);

    UpdateDirection (currentVelocity);
    yap::DebugLogger::Instance ().LogLine ("[velocity changed][" + StringHelper::ToString (oldVelocity.y) + "][" + StringHelper::ToString (currentVelocity.y) + "]");
  }

  void Character::UpdateDirection (const Vector2& velocity)
  {
    if (velocity.x < 0.0f)
      SetDirection (Direction::West);
    else if (velocity.y < 0.0f)
      SetDirection (Direction::North);
    else if (velocity.x > 0.0f)
      SetDirection (Direction::East);
    else if (velocity.y > 0.0f)
      SetDirection (Direction::South);
  }
} // namespace yap
