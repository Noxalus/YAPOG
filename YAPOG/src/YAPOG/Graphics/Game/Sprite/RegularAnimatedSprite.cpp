#include "YAPOG/Graphics/Game/Sprite/RegularAnimatedSprite.hpp"
#include "YAPOG/Graphics/Game/Sprite/DelayedFrameSwitcher.hpp"

namespace yap
{
  const int RegularAnimatedSprite::DEFAULT_FRAME_RATE = 10;

  RegularAnimatedSprite::RegularAnimatedSprite ()
    : AnimatedSprite ()
  {
    SetFrameSwitcher (
      new DelayedFrameSwitcher (
        Time (1.0f / static_cast<float> (DEFAULT_FRAME_RATE))));
  }

  RegularAnimatedSprite::~RegularAnimatedSprite ()
  {
  }

  RegularAnimatedSprite::RegularAnimatedSprite (
    const RegularAnimatedSprite& copy)
    : AnimatedSprite (copy)
  {
  }

  RegularAnimatedSprite* RegularAnimatedSprite::Clone () const
  {
    return new RegularAnimatedSprite (*this);
  }

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
} // namespace yap
