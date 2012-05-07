#ifndef YAPOG_HORIZONTALCOMPOSEDSPRITE_HPP
# define YAPOG_HORIZONTALCOMPOSEDSPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/ComposedSprite.hpp"

namespace yap
{
  class YAPOG_LIB HorizontalComposedSprite : public ComposedSprite
  {
      DISALLOW_COPY(HorizontalComposedSprite);

    public:

      HorizontalComposedSprite (ISprite* left, ISprite* right);
      virtual ~HorizontalComposedSprite ();

    protected:

      virtual Vector2 HandleGetSize () const;

      virtual void UpdatePosition ();
  };
} // namespace yap

#endif // YAPOG_HORIZONTALCOMPOSEDSPRITE_HPP
