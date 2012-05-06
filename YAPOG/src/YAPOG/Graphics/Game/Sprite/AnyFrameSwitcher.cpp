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

  AnyFrameSwitcher::AnyFrameSwitcher (const AnyFrameSwitcher& copy)
    : FrameSwitcher (copy)
    , switchCount_ (copy.switchCount_)
  {
  }

  AnyFrameSwitcher* AnyFrameSwitcher::Clone () const
  {
    return new AnyFrameSwitcher (*this);
  }

  int AnyFrameSwitcher::HandleFrameIsOver (const Time& dt)
  {
    return switchCount_;
  }
} // namespace yap
