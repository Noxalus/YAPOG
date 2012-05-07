#include "YAPOG/Graphics/Game/Sprite/AnimatedSprite.hpp"
#include "YAPOG/Graphics/Game/Sprite/FrameSwitcher.hpp"

namespace yap
{
  const AnimatedSprite::PlayState AnimatedSprite::DEFAULT_PLAY_STATE =
    PlayState::Loop;
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

    for (const ISprite* it : sprites_)
      delete it;
  }

  AnimatedSprite::AnimatedSprite (const AnimatedSprite& copy)
    : BaseSprite (copy)
    , sprites_ ()
    , frameSwitcher_ (copy.frameSwitcher_->Clone ())
    , currentState_ (copy.currentState_)
    , currentIndex_ (DEFAULT_DEFAULT_INDEX)
    , currentFrame_ (nullptr)
    , defaultIndex_ (DEFAULT_DEFAULT_INDEX)
  {
    for (ISprite* sprite : copy.sprites_)
      AddFrame (sprite->Clone ());

    SetDefaultFrame (copy.defaultIndex_);
    SetCurrentFrame (copy.currentIndex_);
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
    for (ISprite* it : sprites_)
      it->Move (offset);
  }

  void AnimatedSprite::HandleScale (const Vector2& factor)
  {
    for (ISprite* it : sprites_)
      it->Scale (factor);
  }

  void AnimatedSprite::HandleDraw (IDrawingContext& context)
  {
    if (currentFrame_ == nullptr)
      return;

    currentFrame_->Draw (context);
  }

  void AnimatedSprite::HandleShow (bool isVisible)
  {
  }

  void AnimatedSprite::HandleChangeColor (const sf::Color& color)
  {
    for (ISprite* it : sprites_)
      it->ChangeColor (color);
  }

  void AnimatedSprite::HandleUpdate (const Time& dt)
  {
    if (sprites_.IsEmpty ())
      return;

    if (currentFrame_ != nullptr)
      currentFrame_->Update (dt);

    int switchedFrameCount = frameSwitcher_->FrameIsOver (dt);

    if (currentState_ == PlayState::None)
      return;

    IndexType frameCount = sprites_.Count ();

    if (currentIndex_ + switchedFrameCount < frameCount)
    {
      SetCurrentFrame (currentIndex_ + switchedFrameCount);
      return;
    }

    SetCurrentFrame ((currentIndex_ + switchedFrameCount) % frameCount);

    if (currentState_ == PlayState::Once)
      ChangeState (PlayState::None);
  }
} // namespace yap
