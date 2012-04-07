#ifndef YAPOG_DIRECTIONALSPRITESET_HPP
# define YAPOG_DIRECTIONALSPRITESET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/SpriteSet.hpp"
# include "YAPOG/Game/World/Map/Direction.hpp"

namespace yap
{
  class DirectionalSpriteSet : public SpriteSet<Direction>
  {
      DISALLOW_COPY(DirectionalSpriteSet);

    public:

      DirectionalSpriteSet ();
      virtual ~DirectionalSpriteSet ();
  };
} // namespace yap

#endif // YAPOG_DIRECTIONALSPRITESET_HPP
