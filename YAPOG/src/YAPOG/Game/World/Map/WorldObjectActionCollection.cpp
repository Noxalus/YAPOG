#include "YAPOG/Game/World/Map/WorldObjectActionCollection.hpp"
#include "YAPOG/Game/World/Map/IWorldObjectAction.hpp"

namespace yap
{
  WorldObjectActionCollection::WorldObjectActionCollection ()
    : actions_ ()
  {
  }

  WorldObjectActionCollection::~WorldObjectActionCollection ()
  {
    for (auto& nameActionPair : actions_)
      delete nameActionPair.second;
  }

  void WorldObjectActionCollection::AddAction (
    const String& name,
    IWorldObjectAction* action)
  {
    actions_.Add (name, action);
  }

  void WorldObjectActionCollection::RemoveAction (const String& name)
  {
    IWorldObjectAction* action = actions_[name];

    actions_.Remove (name);

    delete action;
    action = nullptr;
  }

  void WorldObjectActionCollection::PerformAction (const String& name)
  {
    actions_[name]->Perform ();
  }
} // namespace yap
