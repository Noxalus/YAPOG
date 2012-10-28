#ifndef YAPOG_CLIENT_MAPCLONER_HPP
# define YAPOG_CLIENT_MAPCLONER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/ICloner.hpp"

namespace ycl
{
  class Map;

  class MapCloner : public yap::ICloner<Map>
  {
      DISALLOW_COPY(MapCloner);

    public:

      MapCloner ();

      virtual ~MapCloner ();

      virtual Map* Clone (const Map& map) const;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_MAPCLONER_HPP
