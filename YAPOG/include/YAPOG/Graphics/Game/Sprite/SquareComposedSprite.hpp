#ifndef YAPOG_SQUARECOMPOSEDSPRITE_HPP
# define YAPOG_SQUARECOMPOSEDSPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/ComposedSprite.hpp"

namespace yap
{
  class SquareComposedSprite : public ComposedSprite
  {
      DISALLOW_COPY(SquareComposedSprite);

    public:

      virtual ~SquareComposedSprite ();
  };
} // namespace yap

#endif // YAPOG_SQUARECOMPOSEDSPRITE_HPP
