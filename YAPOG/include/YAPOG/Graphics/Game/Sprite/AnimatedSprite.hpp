#ifndef YAPOG_ANIMATEDSPRITE_HPP
# define YAPOG_ANIMATEDSPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
# include "YAPOG/Collection/List.hpp"

namespace yap
{
  /// @brief An ISprite that automatically evolves over time,
  /// playing predetertmined ISprite.
  class AnimatedSprite : public ISprite
  {
      DISALLOW_COPY(AnimatedSprite);

    public:

      virtual ~AnimatedSprite ();

    private:

      collection::List<ISprite*> sprites_;
  };
} // namespace yap

#endif // YAPOG_ANIMATEDSPRITE_HPP
