#include "World/Map/Character.hpp"

Character::Character (const yap::ID& id)
  : yap::Character (id)
{
}

Character::~Character ()
{
}

Character::Character (const Character& copy)
  : yap::Character (copy)
{
}
