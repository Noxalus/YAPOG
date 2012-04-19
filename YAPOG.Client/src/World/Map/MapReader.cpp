#include "World/Map/MapReader.hpp"
#include "World/Map/Map.hpp"

MapReader::MapReader (Map& map)
  : yap::MapReader (map)
{
}

MapReader::~MapReader ()
{
}

void MapReader::Visit (yap::XmlReader& visitable)
{
  yap::MapReader::Visit (visitable);
}
