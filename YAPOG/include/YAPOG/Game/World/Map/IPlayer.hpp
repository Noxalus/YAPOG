#ifndef YAPOG_IPLAYER_HPP
# define YAPOG_IPLAYER_HPP

# include "YAPOG/Game/World/Map/IMapEventTrigger.hpp"
# include "YAPOG/Game/World/Map/IMapEventProvider.hpp"

namespace yap
{
  /// @brief Interface providing main actions to an object.
  struct IPlayer : public IMapEventTrigger
                 , public IMapEventProvider
  {
      virtual ~IPlayer () { }

      virtual void ChangeMap (const ID& mapWorldID) = 0;
  };
} // namespace yap

#endif // YAPOG_IPLAYER_HPP
