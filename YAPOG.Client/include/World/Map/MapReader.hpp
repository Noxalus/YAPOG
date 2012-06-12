#ifndef YAPOG_CLIENT_MAP_READER_HPP
# define YAPOG_CLIENT_MAP_READER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/MapReader.hpp"

namespace ycl
{
  class Map;

  class MapReader : public yap::MapReader
  {
      DISALLOW_COPY(MapReader);

    public:

      MapReader (Map& map, const yap::String& xmlRootNodeName);
      virtual ~MapReader ();

      virtual void Visit (yap::XmlReader& visitable);

    protected:

      virtual void ReadStaticObjects (yap::XmlReader& reader);

    private:

      Map& map_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_MAP_READER_HPP
