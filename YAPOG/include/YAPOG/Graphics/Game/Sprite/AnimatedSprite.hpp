#ifndef YAPOG_ANIMATEDSPRITE_HPP
# define YAPOG_ANIMATEDSPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/BaseSprite.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  class FrameSwitcher;

  /// @brief An ISprite that automatically evolves over time,
  /// playing predetertmined ISprite.
  class AnimatedSprite : public BaseSprite
  {
      DISALLOW_COPY(AnimatedSprite);

    public:

      enum class PlayState
      {
          None = 0,
          Once = 1,
          Loop = 2
      };

      typedef collection::Array<ISprite*>::SizeType IndexType;

      virtual ~AnimatedSprite ();

      void AddFrame (ISprite* sprite);
      void RemoveFrame (ISprite* sprite);

      void ChangeState (PlayState playState);

      void SetDefaultFrame (IndexType index);

    protected:

      AnimatedSprite ();

      void SetFrameSwitcher (FrameSwitcher* frameSwitcher);

    private:

      void SetCurrentFrame (IndexType index);
      void SetDefaultFrame ();

      virtual void HandleMove (const Vector2& offset);
      virtual void HandleScale (const Vector2& factor);

      virtual void HandleDraw (IDrawingContext& context);

      virtual void HandleShow (bool isVisible);
      virtual void HandleChangeColor (const sf::Color& color);

      virtual void HandleUpdate (const Time& dt);

      static const PlayState DEFAULT_PLAY_STATE;
      static const IndexType DEFAULT_DEFAULT_INDEX;

      collection::Array<ISprite*> sprites_;
      FrameSwitcher* frameSwitcher_;
      PlayState currentState_;
      IndexType currentIndex_;
      ISprite* currentFrame_;
      IndexType defaultIndex_;
  };
} // namespace yap

#endif // YAPOG_ANIMATEDSPRITE_HPP
