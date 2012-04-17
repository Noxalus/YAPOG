#include "YAPOG/Graphics/Game/Sprite/AnyFrameSwitcher.hpp"

namespace yap
{
  const int AnyFrameSwitcher::DEFAULT_SWITCH_COUNT = 1;

  AnyFrameSwitcher::AnyFrameSwitcher ()
    : FrameSwitcher ()
    , switchCount_ (DEFAULT_SWITCH_COUNT)
  {
  }

  AnyFrameSwitcher::AnyFrameSwitcher (int switchCount)
    : FrameSwitcher ()
    , switchCount_ (switchCount)
  {
  }

  AnyFrameSwitcher::~AnyFrameSwitcher ()
  {
  }

  int AnyFrameSwitcher::FrameIsOver (const Time& dt)
  {
    return switchCount_;
  }
} // namespace yap
