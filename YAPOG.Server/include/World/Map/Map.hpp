#ifndef YAPOG_SERVER_MAP_HPP
# define YAPOG_SERVER_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Map.hpp"

namespace yse
{
  class Map : public yap::Map
  {
      DISALLOW_COPY(Map);

    public:

      Map (const yap::ID& id);
      virtual ~Map ();
  };
} // namespace yse

#endif // YAPOG_MAP_HPP
