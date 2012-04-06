#ifndef YAPOG_VERTICALCOMPOSEDSPRITE_HPP
# define YAPOG_VERTICALCOMPOSEDSPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/ComposedSprite.hpp"

namespace yap
{
  class VerticalComposedSprite : public ComposedSprite
  {
      DISALLOW_COPY(VerticalComposedSprite);

    public:

      virtual ~VerticalComposedSprite ();
  };
} // namespace yap

#endif // YAPOG_VERTICALCOMPOSEDSPRITE_HPP
