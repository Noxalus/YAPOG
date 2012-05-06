#include "YAPOG/Game/World/Map/WorldObjectStateFactory.hpp"

namespace yap
{
  WorldObjectStateFactory::WorldObjectStateFactory ()
    : states_ ()
  {
  }

  WorldObjectStateFactory::~WorldObjectStateFactory ()
  {
    for (const auto& it : states_)
      delete it.second;
  }

  WorldObjectStateFactory& WorldObjectStateFactory::Instance ()
  {
    static WorldObjectStateFactory instance;

    return instance;
  }

  void WorldObjectStateFactory::AddState (
    const String& state,
    const String& logicalState)
  {
    states_.Add (state, new WorldObjectStateInfo (state, logicalState));
  }

  void WorldObjectStateFactory::AddJoin (
    const String& state,
    const String& join)
  {
    states_[state]->AddJoin (join);
  }

  WorldObjectStateFactory::WorldObjectStateInfo&
  WorldObjectStateFactory::GetState (const String& state)
  {
    return *states_[state];
  }

  WorldObjectStateFactory::WorldObjectStateInfo::WorldObjectStateInfo (
    const String& name,
    const String& logicalName)
    : name_ (name)
    , logicalName_ (logicalName)
    , joins_ ()
  {
  }

  const String& WorldObjectStateFactory::WorldObjectStateInfo::GetName () const
  {
    return name_;
  }

  const String&
  WorldObjectStateFactory::WorldObjectStateInfo::GetLogicalName () const
  {
    return logicalName_;
  }

  bool WorldObjectStateFactory::WorldObjectStateInfo::IsJoinedTo (
    const String& state) const
  {
    return joins_.Contains (state);
  }

  void WorldObjectStateFactory::WorldObjectStateInfo::AddJoin (
    const String& join)
  {
    joins_.Add (join);
  }
} // namespace yap
