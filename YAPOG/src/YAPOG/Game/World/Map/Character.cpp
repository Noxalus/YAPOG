#include "YAPOG/Game/World/Map/Character.hpp"
#include "YAPOG/Game/World/Map/CharacterPhysicsInfo.hpp"

namespace yap
{
  Character::Character (const ID& id)
    : DynamicWorldObject (id)
    , physicsInfo_ ()
  {
  }

  Character::~Character ()
  {
  }

  Character::Character (const Character& copy)
    : DynamicWorldObject (copy)
    , physicsInfo_ ()
  {
  }

  CharacterPhysicsInfo& Character::GetPhysicsInfo ()
  {
    return physicsInfo_;
  }
} // namespace yap
