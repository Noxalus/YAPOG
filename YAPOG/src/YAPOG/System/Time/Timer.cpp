#include "YAPOG/System/Time/Timer.hpp"

namespace yap
{
  Timer::Timer ()
    : clock_ ()
    , init_ ()
  {
  }

  Timer::Timer (const Time& init)
    : clock_ ()
    , init_ (init)
  {
  }

  void Timer::Reset ()
  {
    Reset (Time ());
  }

  void Timer::Reset (const Time& init)
  {
    init_ = init;

    clock_.Restart ();
  }

  Time Timer::GetCurrentTime () const
  {
    return Time (clock_.GetElapsedTime ()) + init_;
  }

  int Timer::DelayIsComplete (const Time& delay, bool reset)
  {
    float currentTime = GetCurrentTime ().GetValue ();

    int factor = static_cast<int> (
      currentTime / delay.GetValue ());

    if (reset && factor > 0)
      Reset (Time (currentTime - factor * delay.GetValue ()));

    return factor;
  }
} // namespace yap
