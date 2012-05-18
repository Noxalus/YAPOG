#include "YAPOG/Game/World/World.hpp"

namespace yap
{
  World::World ()
  {
  }

  World::~World ()
  {
  }

  void World::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }

  void World::HandleUpdate (const Time& dt)
  {
  }
} // namespace yap
