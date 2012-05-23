#ifndef YAPOG_CLIENT_MAPELEMENTREADER_HPP
# define YAPOG_CLIENT_MAPELEMENTREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/MapElementReader.hpp"

namespace ycl
{
  class MapElement;

  class YAPOG_LIB MapElementReader : public yap::MapElementReader
  {
      DISALLOW_COPY(MapElementReader);

    public:

      MapElementReader (
        MapElement& dynamicWorldObject,
        const yap::String& xmlRootNodeName);
      virtual ~MapElementReader ();

      virtual void Visit (yap::XmlReader& visitable);

    private:

      static const yap::String DEFAULT_XML_SPRITE_TYPE_NODE_NAME;

      MapElement& mapElement_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_MAPELEMENTREADER_HPP
