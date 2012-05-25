#include "YAPOG/Game/World/Map/Character.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"

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

  void Character::HandleMove (const Vector2& offset)
  {
    DynamicWorldObject::HandleMove (offset);

    UpdateDirection (offset);
  }

  void Character::UpdateDirection (const Vector2& offset)
  {
    if (offset.x < 0.0f)
      SetDirection (Direction::West);
    else if (offset.y < 0.0f)
      SetDirection (Direction::North);
    else if (offset.x > 0.0f)
      SetDirection (Direction::East);
    else if (offset.y > 0.0f)
      SetDirection (Direction::South);
  }
} // namespace yap
