#include "YAPOG/System/Time/UpdateableTimer.hpp"

namespace yap
{
  UpdateableTimer::UpdateableTimer ()
    : currentTime_ ()
  {
  }

  UpdateableTimer::UpdateableTimer (const Time& initTime)
    : currentTime_ (initTime)
  {
  }

  void UpdateableTimer::Update (const Time& dt)
  {
    currentTime_ += dt;
  }

  void UpdateableTimer::Reset ()
  {
    Reset (Time ());
  }

  void UpdateableTimer::Reset (const Time& init)
  {
    currentTime_ = init;
  }

  const Time& UpdateableTimer::GetCurrentTime () const
  {
    return currentTime_;
  }

  int UpdateableTimer::DelayIsComplete (const Time& delay, bool reset)
  {
    float currentTime = GetCurrentTime ().GetValue ();

    int factor = static_cast<int> (
      currentTime / delay.GetValue ());

    if (reset && factor > 0)
      Reset (Time (currentTime - factor * delay.GetValue ()));

    return factor;
  }
} // namespace yap
