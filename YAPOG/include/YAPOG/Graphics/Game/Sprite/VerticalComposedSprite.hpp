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

      VerticalComposedSprite (ISprite* top, ISprite* bottom);
      virtual ~VerticalComposedSprite ();

    private:

      virtual Vector2 HandleGetSize () const;

      virtual void UpdatePosition ();
  };
} // namespace yap

#endif // YAPOG_VERTICALCOMPOSEDSPRITE_HPP
