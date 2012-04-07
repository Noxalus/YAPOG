#include "YAPOG/Graphics/Game/Sprite/AnimatedSprite.hpp"
#include "YAPOG/Graphics/Game/Sprite/FrameSwitcher.hpp"

namespace yap
{
  const AnimatedSprite::PlayState AnimatedSprite::DEFAULT_PLAY_STATE =
    PlayState::Once;
  const AnimatedSprite::IndexType AnimatedSprite::DEFAULT_DEFAULT_INDEX = 0;

  AnimatedSprite::AnimatedSprite ()
    : BaseSprite ()
    , sprites_ ()
    , frameSwitcher_ (nullptr)
    , currentState_ (DEFAULT_PLAY_STATE)
    , currentIndex_ (DEFAULT_DEFAULT_INDEX)
    , currentFrame_ (nullptr)
    , defaultIndex_ (DEFAULT_DEFAULT_INDEX)
  {
  }

  AnimatedSprite::~AnimatedSprite ()
  {
    delete frameSwitcher_;

    for (const auto& it : sprites_)
      delete it;
  }

  void AnimatedSprite::AddFrame (ISprite* sprite)
  {
    sprites_.Add (sprite);
  }

  void AnimatedSprite::RemoveFrame (ISprite* sprite)
  {
    sprites_.Remove (sprite);
  }

  void AnimatedSprite::ChangeState (PlayState playState)
  {
    currentState_ = playState;

    if (currentState_ == PlayState::None)
      SetDefaultFrame ();
  }

  void AnimatedSprite::SetDefaultFrame (IndexType index)
  {
    defaultIndex_ = index;
  }

  void AnimatedSprite::SetFrameSwitcher (FrameSwitcher* frameSwitcher)
  {
    frameSwitcher_ = frameSwitcher;
  }

  void AnimatedSprite::SetCurrentFrame (IndexType index)
  {
    currentIndex_ = index;
    currentFrame_ = sprites_[currentIndex_];
  }

  void AnimatedSprite::SetDefaultFrame ()
  {
    SetCurrentFrame (defaultIndex_);
  }

  void AnimatedSprite::HandleMove (const Vector2& offset)
  {
    for (const auto& it : sprites_)
      it->Move (offset);
  }

  void AnimatedSprite::HandleScale (const Vector2& factor)
  {
    for (const auto& it : sprites_)
      it->Scale (factor);
  }

  void AnimatedSprite::HandleDraw (IDrawingContext& context)
  {
    currentFrame_->Draw (context);
  }

  void AnimatedSprite::HandleShow (bool isVisible)
  {
  }

  void AnimatedSprite::HandleChangeColor (const sf::Color& color)
  {
    for (const auto& it : sprites_)
      it->ChangeColor (color);
  }

  void AnimatedSprite::HandleUpdate (const Time& dt)
  {
    int switchedFrameCount = frameSwitcher_->FrameIsOver (dt);

    if (currentState_ == PlayState::None)
      return;

    IndexType frameCount = sprites_.Count ();

    /// @todo
    SetCurrentFrame (currentIndex_ + frameCount);
  }
} // namespace yap
