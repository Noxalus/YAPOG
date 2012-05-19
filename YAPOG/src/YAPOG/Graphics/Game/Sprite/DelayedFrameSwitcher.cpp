#include "YAPOG/Graphics/Game/Sprite/DelayedFrameSwitcher.hpp"

namespace yap
{
  DelayedFrameSwitcher::DelayedFrameSwitcher (const Time& delay)
    : FrameSwitcher ()
    , delay_ (delay)
  {
  }

  DelayedFrameSwitcher::~DelayedFrameSwitcher ()
  {
  }

  DelayedFrameSwitcher::DelayedFrameSwitcher (const DelayedFrameSwitcher& copy)
    : FrameSwitcher (copy)
    , delay_ (copy.delay_)
    , timer_ ()
  {
  }

  DelayedFrameSwitcher* DelayedFrameSwitcher::Clone () const
  {
    return new DelayedFrameSwitcher (*this);
  }

  int DelayedFrameSwitcher::HandleFrameIsOver (const Time& dt)
  {
    timer_.Update (dt);

    return timer_.DelayIsComplete (delay_, true);
  }
} // namespace yap
