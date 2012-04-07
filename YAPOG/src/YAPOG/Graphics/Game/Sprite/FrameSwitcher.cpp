#include "YAPOG/Graphics/Game/Sprite/FrameSwitcher.hpp"

namespace yap
{
  FrameSwitcher::FrameSwitcher ()
  {
  }

  FrameSwitcher::~FrameSwitcher ()
  {
  }

  int FrameSwitcher::FrameIsOver (const Time& dt)
  {
    return HandleFrameIsOver (dt);
  }
} // namespace yap
