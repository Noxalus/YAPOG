#include "YAPOG/Game/World/Map/Character.hpp"
#include "YAPOG/Game/World/Map/CharacterPhysicsInfo.hpp"

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

  void Character::InitPhysicsInfo ()
  {
    SetPhysicsInfo (new CharacterPhysicsInfo ());
  }
} // namespace yap
