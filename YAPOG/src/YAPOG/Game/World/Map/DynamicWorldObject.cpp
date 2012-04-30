#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"

namespace yap
{
  DynamicWorldObject::DynamicWorldObject (const ID& id)
    : WorldObject (id)
    , worldID_ ()
    , state_ ()
  {
  }

  DynamicWorldObject::~DynamicWorldObject ()
  {
  }

  DynamicWorldObject::DynamicWorldObject (const DynamicWorldObject& copy)
    : WorldObject (copy)
    , worldID_ (copy.worldID_)
    , state_ (copy.state_)
  {
  }

  const ID& DynamicWorldObject::GetWorldID () const
  {
    return worldID_;
  }

  void DynamicWorldObject::SetWorldID (const ID& id)
  {
    worldID_ = id;
  }

  void DynamicWorldObject::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }

  void DynamicWorldObject::HandleUpdate (const Time& dt)
  {
  }
} // namespace yap
