#include "YAPOG/Game/World/Map/WorldObjectAction.hpp"

namespace yap
{
  WorldObjectAction::WorldObjectAction (DynamicWorldObject& parent)
    : parent_ (parent)
  {
  }

  WorldObjectAction::~WorldObjectAction ()
  {
  }

  void WorldObjectAction::Perform ()
  {
    HandlePerform ();
  }

  void WorldObjectAction::HandlePerform ()
  {
  }
} // namespace yap
