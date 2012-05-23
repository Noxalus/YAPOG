#include "YAPOG/Game/World/Map/StaticWorldObject.hpp"

namespace yap
{
  StaticWorldObject::StaticWorldObject (const ID& id)
    : WorldObject (id)
  {
  }

  StaticWorldObject::~StaticWorldObject ()
  {
  }

  StaticWorldObject::StaticWorldObject (const StaticWorldObject& copy)
    : WorldObject (copy)
  {
  }

  void StaticWorldObject::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }

  void StaticWorldObject::HandleUpdate (const Time& dt)
  {
  }
} // namespace yap
