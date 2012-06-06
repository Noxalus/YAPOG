#ifndef YAPOG_IPLAYER_HPP
# define YAPOG_IPLAYER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  /// @brief Interface providing main actions to an object.
  struct IPlayer
  {
      virtual ~IPlayer () { }

      virtual void ChangeMap (const ID& mapWorldID) = 0;
  };
} // namespace yap

#endif // YAPOG_IPLAYER_HPP
