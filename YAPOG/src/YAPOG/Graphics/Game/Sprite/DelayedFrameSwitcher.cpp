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

  int DelayedFrameSwitcher::HandleFrameIsOver (const Time& dt)
  {
    timer_.Update (dt);

    return timer_.DelayIsComplete (delay_, true);
  }
} // namespace yap
