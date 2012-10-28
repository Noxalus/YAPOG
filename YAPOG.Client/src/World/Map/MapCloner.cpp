#include "World/Map/MapCloner.hpp"

#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace ycl
{
  MapCloner::MapCloner ()
  {
  }

  MapCloner::~MapCloner ()
  {
  }

  Map* MapCloner::Clone (const Map& map) const
  {
    YAPOG_THROW("Invalid method call.");
  }
} // namespace ycl
