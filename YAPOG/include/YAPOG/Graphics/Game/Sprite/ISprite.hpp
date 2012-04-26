#ifndef YAPOG_ISPRITE_HPP
# define YAPOG_ISPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/ISpatial.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/Factory/ILoadable.hpp"

namespace yap
{
  /// @brief Interface for a static or dynamic graphical element of the game.
  struct YAPOG_LIB ISprite : public ISpatial
                           , public IDrawable
                           , public IUpdateable
                           , public ILoadable
  {
      virtual ~ISprite () {}

      /// @name ICloneable members.
      /// @{
      virtual ISprite* Clone () const { return nullptr; } 
      /// @}
  };
} // namespace yap

#endif // YAPOG_ISPRITE_HPP
