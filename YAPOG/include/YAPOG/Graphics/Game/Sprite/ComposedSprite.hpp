#ifndef YAPOG_COMPOSEDSPRITE_HPP
# define YAPOG_COMPOSEDSPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"

namespace yap
{
  class ComposedSprite : public ISprite
  {
      DISALLOW_COPY(ComposedSprite);

    public:

      virtual ~ComposedSprite ();
  };
} // namespace yap

#endif // YAPOG_COMPOSEDSPRITE_HPP
