#include "World/Map/Character.hpp"

namespace yse
{
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

  void Character::SetMap (Map* map)
  {
    map_ = map;
  }
} // namespace yse
