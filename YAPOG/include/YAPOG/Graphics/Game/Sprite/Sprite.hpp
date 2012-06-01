#ifndef YAPOG_SPRITE_HPP
# define YAPOG_SPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/BaseSprite.hpp"
# include "YAPOG/Graphics/Texture.hpp"

namespace yap
{
  /// @brief A simple static ISprite that holds a Texture.
  class YAPOG_LIB Sprite : public BaseSprite
  {
      DISALLOW_ASSIGN(Sprite);

    public:

      Sprite ();
      explicit Sprite (Texture* texture);
      explicit Sprite (const String& textureName);
      Sprite (
        const String& textureName, 
        const sf::IntRect& textureRect);
      virtual ~Sprite ();

      void SetTexture (Texture* texture);

      /// @name ICloneable members.
      /// @{
      virtual Sprite* Clone () const;
      /// @}

    protected:

      Sprite (const Sprite& copy);

    private:

      virtual void HandleMove (const Vector2& offset);
      virtual void HandleScale (const Vector2& factor);

      virtual void HandleDraw (IDrawingContext& context);

      virtual void HandleShow (bool isVisible);
      virtual void HandleChangeColor (const sf::Color& color);

      virtual void HandleUpdate (const Time& dt);

      Vector2 HandleGetSize () const;

      Texture* texture_;
  };
} // namespace yap

#endif // YAPOG_SPRITE_HPP
