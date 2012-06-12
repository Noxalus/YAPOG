#ifndef YAPOG_SERVER_MAPREADER_HPP
# define YAPOG_SERVER_MAPREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/MapReader.hpp"

namespace yse
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

      virtual void ReadStaticObjects (yap::XmlReader& visitable);
      virtual void ReadDynamicObjects (yap::XmlReader& visitable);

    private:

      Map& map_;
  };
} // namespace yse

#endif // YAPOG_SERVER_MAPREADER_HPP
