#ifndef YAPOG_HORIZONTALCOMPOSEDSPRITE_HPP
# define YAPOG_HORIZONTALCOMPOSEDSPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/ComposedSprite.hpp"

namespace yap
{
  class HorizontalComposedSprite : public ComposedSprite
  {
      DISALLOW_COPY(HorizontalComposedSprite);

    public:

      virtual ~HorizontalComposedSprite ();
  };
} // namespace yap

#endif // YAPOG_HORIZONTALCOMPOSEDSPRITE_HPP
