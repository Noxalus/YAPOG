#ifndef YAPOG_SPRITE_HPP
# define YAPOG_SPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/SpriteBase.hpp"
# include "YAPOG/Graphics/Texture.hpp"

namespace yap
{
  /// @brief A simple static ISprite that holds a Texture.
  class Sprite : public SpriteBase
  {
      DISALLOW_COPY(Sprite);

    public:

      Sprite ();
      explicit Sprite (const String& textureName);
      Sprite (const String& textureName, const sf::IntRect& textureRect);
      virtual ~Sprite ();

    private:

      virtual void HandleMove (const Vector2& offset);
      virtual void HandleScale (const Vector2& factor);

      virtual void HandleDraw (IDrawingContext& context);

      virtual void HandleShow (bool isVisible);
      virtual void HandleChangeColor (const sf::Color& color);

      virtual void HandleUpdate (const Time& dt);

      Texture texture_;
  };
} // namespace yap

#endif // YAPOG_SPRITE_HPP
