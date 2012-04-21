#ifndef YAPOG_CLIENT_MAP_READER_HPP
# define YAPOG_CLIENT_MAP_READER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/MapReader.hpp"

class Map;

class MapReader : public yap::MapReader
{
    DISALLOW_COPY(MapReader);

  public:

    MapReader (Map& map);
    virtual ~MapReader ();

    virtual void Visit (yap::XmlReader& visitable);

  private:

    Map& map_;
};

#endif // YAPOG_CLIENT_MAP_READER_HPP
