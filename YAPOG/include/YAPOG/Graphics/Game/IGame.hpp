#ifndef YAPOG_IGAME_HPP
# define YAPOG_IGAME_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  /// @brief Interface for game main structure.
  struct YAPOG_LIB IGame
  {
      virtual ~IGame () {}

      virtual void Init () = 0;
      virtual void Launch () = 0;
  };
} // namespace yap

#endif // YAPOG_IGAME_HPP
