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

  DynamicWorldObject& WorldObjectAction::GetParent ()
  {
    return parent_;
  }

  void WorldObjectAction::HandlePerform ()
  {
  }
} // namespace yap
