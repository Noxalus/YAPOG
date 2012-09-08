#include "YAPOG/Game/Player/PlayerTime.hpp"

namespace yap
{
  PlayerTime::PlayerTime ()
    : playTime_ ()
    , currentSessionTime_ ()
  {
  }

  void PlayerTime::UpdateTime (const Time& dt)
  {   
    playTime_ += dt;
    currentSessionTime_ += dt;
  }

  // Getters
  const Time& PlayerTime::GetPlayTime () const
  { return playTime_; }
  const Time& PlayerTime::GetCurrentSessionTime () const
  { return currentSessionTime_; }

  // Setters
  void PlayerTime::RawSetPlayTime (const Time& value)
  {
    playTime_ = value; 
  }

} // namespace yap
