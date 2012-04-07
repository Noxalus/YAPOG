#ifndef YAPOG_COMPOSEDSPRITE_HPP
# define YAPOG_COMPOSEDSPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/BaseSprite.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  class ComposedSprite : public BaseSprite
  {
      DISALLOW_COPY(ComposedSprite);

    public:

      ComposedSprite ();
      virtual ~ComposedSprite ();

      /// @brief Initializes this ComposedSprite adding each ISprite that
      /// composes it.
      void Init ();

    protected:

      void AddSprite (ISprite* sprite);
      ISprite& GetSprite (
        const collection::Array<ISprite*>::SizeType& index) const;

    private:

      virtual void HandleMove (const Vector2& offset);
      virtual void HandleScale (const Vector2& factor);

      virtual void HandleDraw (IDrawingContext& context);

      virtual void HandleShow (bool isVisible);
      virtual void HandleChangeColor (const sf::Color& color);

      virtual void HandleUpdate (const Time& dt);

      virtual void UpdatePosition () = 0;

      collection::Array<ISprite*> sprites_;
  };
} // namespace yap

#endif // YAPOG_COMPOSEDSPRITE_HPP
