#ifndef YAPOG_MAPELEMENTREADER_HPP
# define YAPOG_MAPELEMENTREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/StaticWorldObjectReader.hpp"

namespace yap
{
  class MapElement;

  class YAPOG_LIB MapElementReader : public StaticWorldObjectReader
  {
      DISALLOW_COPY(MapElementReader);

    public:

      MapElementReader (
        MapElement& dynamicWorldObject,
        const String& xmlRootNodeName);
      virtual ~MapElementReader ();

    private:

      MapElement& mapElement_;
  };
} // namespace yap

#endif // YAPOG_MAPELEMENTREADER_HPP
