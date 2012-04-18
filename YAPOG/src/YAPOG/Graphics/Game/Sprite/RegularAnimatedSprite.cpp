#include "YAPOG/Graphics/Game/Sprite/RegularAnimatedSprite.hpp"
#include "YAPOG/Graphics/Game/Sprite/DelayedFrameSwitcher.hpp"

namespace yap
{
  RegularAnimatedSprite::RegularAnimatedSprite (const Time& delay)
    : AnimatedSprite ()
  {
    SetFrameSwitcher (new DelayedFrameSwitcher (delay));
  }

  RegularAnimatedSprite::RegularAnimatedSprite (int frameRate)
    : AnimatedSprite ()
  {
    SetFrameSwitcher (
      new DelayedFrameSwitcher (
        Time (1.0f / static_cast<float> (frameRate))));
  }

  RegularAnimatedSprite::~RegularAnimatedSprite ()
  {
  }
} // namespace yap
