#include "YAPOG/Game/World/Map/WorldObjectState.hpp"

namespace yap
{
  WorldObjectState::WorldObjectState ()
  {
  }

  WorldObjectState::WorldObjectState (const WorldObjectState& copy)
  {
  }

  WorldObjectState& WorldObjectState::operator= (const WorldObjectState& copy)
  {
    if (this == &copy)
      return *this;

    return *this;
  }

  bool WorldObjectState::operator< (const WorldObjectState& right) const
  {
    return true;
  }
} // namespace yap
