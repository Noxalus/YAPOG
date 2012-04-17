#ifndef YAPOG_IUPDATEABLE_HPP
# define YAPOG_IUPDATEABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Time/Time.hpp"

namespace yap
{
  /// @brief Represents an object that evolves at each frame of the game.
  struct YAPOG_LIB IUpdateable
  {
      virtual ~IUpdateable () {}

      /// @brief Makes the object evolve for one frame of the game.
      /// @param dt Delta time since the last frame.
      virtual void Update (const Time& dt) = 0;
  };
} // namespace yap

#endif // YAPOG_IUPDATEABLE_HPP
