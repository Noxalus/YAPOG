#include "YAPOG/Game/World/Map/Character.hpp"

namespace yap
{
  Character::Character (const ID& id)
    : DynamicWorldObject (id)
  {
  }

  Character::~Character ()
  {
  }

  Character::Character (const Character& copy)
    : DynamicWorldObject (copy)
  {
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
      direction_ = Direction::West;
    else if (offset.y < 0.0f)
      direction_ = Direction::North;
    else if (offset.x > 0.0f)
      direction_ = Direction::East;
    else if (offset.y > 0.0f)
      direction_ = Direction::South;
  }
} // namespace yap
