#ifndef YAPOG_SQUARECOMPOSEDSPRITE_HPP
# define YAPOG_SQUARECOMPOSEDSPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/ComposedSprite.hpp"

namespace yap
{
  class YAPOG_LIB SquareComposedSprite : public ComposedSprite
  {
      DISALLOW_COPY(SquareComposedSprite);

    public:

      SquareComposedSprite (
        ISprite* topLeft,
        ISprite* topRight,
        ISprite* bottomLeft,
        ISprite* bottomRight);
      virtual ~SquareComposedSprite ();

    protected:

      virtual Vector2 HandleGetSize () const;

      virtual void UpdatePosition ();
  };
} // namespace yap

#endif // YAPOG_SQUARECOMPOSEDSPRITE_HPP
