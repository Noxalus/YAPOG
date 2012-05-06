#ifndef YAPOG_REGULARANIMATEDSPRITE_HPP
# define YAPOG_REGULARANIMATEDSPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/AnimatedSprite.hpp"

namespace yap
{
  class YAPOG_LIB RegularAnimatedSprite : public AnimatedSprite
  {
      DISALLOW_ASSIGN(RegularAnimatedSprite);

    public:

      RegularAnimatedSprite ();
      explicit RegularAnimatedSprite (const Time& delay);
      explicit RegularAnimatedSprite (int frameRate);
      virtual ~RegularAnimatedSprite ();

      /// @name ICloneable members.
      /// @{
      virtual RegularAnimatedSprite* Clone () const;
      /// @}

    protected:

      RegularAnimatedSprite (const RegularAnimatedSprite& copy);

    private:

      static const int DEFAULT_FRAME_RATE;
  };
} // namespace yap

#endif // YAPOG_REGULARANIMATEDSPRITE_HPP
