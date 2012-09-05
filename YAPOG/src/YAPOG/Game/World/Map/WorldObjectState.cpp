#include "YAPOG/Game/World/Map/WorldObjectState.hpp"

namespace yap
{
  WorldObjectState::WorldObjectState ()
    : info_ (nullptr)
  {
  }

  WorldObjectState::WorldObjectState (const WorldObjectState& copy)
    : info_ (copy.info_)
  {
  }

  WorldObjectState::WorldObjectState (const String& state)
    : info_ (nullptr)
  {
    info_ = &WorldObjectStateFactory::Instance ().GetState (state);
  }

  WorldObjectState& WorldObjectState::operator= (const WorldObjectState& copy)
  {
    if (this == &copy)
      return *this;

    info_ = copy.info_;

    return *this;
  }

  WorldObjectState& WorldObjectState::operator= (const String& other)
  {
    if (info_->GetName () == other)
      return *this;

    info_ = &WorldObjectStateFactory::Instance ().GetState (other);

    return *this;
  }

  bool WorldObjectState::operator< (const WorldObjectState& right) const
  {
    return true;
  }

  bool WorldObjectState::operator== (const WorldObjectState& right) const
  {
    return info_ == right.info_;
  }

  bool WorldObjectState::operator!= (const WorldObjectState& right) const
  {
    return !operator== (right);
  }

  bool WorldObjectState::operator== (const String& right) const
  {
    return GetName () == right;
  }

  bool WorldObjectState::operator!= (const String& right) const
  {
    return !operator== (right);
  }

  const String& WorldObjectState::GetName () const
  {
    return info_->GetName ();
  }

  const String& WorldObjectState::GetLogicalName () const
  {
    return info_->GetLogicalName ();
  }

  bool WorldObjectState::IsJoinedTo (const String& other) const
  {
    return info_->IsJoinedTo (other);
  }
} // namespace yap
