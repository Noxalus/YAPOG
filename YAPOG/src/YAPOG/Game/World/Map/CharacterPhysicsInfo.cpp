#include "YAPOG/Game/World/Map/CharacterPhysicsInfo.hpp"

namespace yap
{
  CharacterPhysicsInfo::CharacterPhysicsInfo ()
    : WorldObjectPhysicsInfo ()
  {
  }

  CharacterPhysicsInfo::~CharacterPhysicsInfo ()
  {
  }

  CharacterPhysicsInfo::CharacterPhysicsInfo (const CharacterPhysicsInfo& copy)
    : WorldObjectPhysicsInfo (copy)
  {
  }

  CharacterPhysicsInfo* CharacterPhysicsInfo::Clone () const
  {
    return new CharacterPhysicsInfo (*this);
  }
} // namespace yap
