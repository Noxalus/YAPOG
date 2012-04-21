#include "World/Map/MapReader.hpp"
#include "World/Map/Map.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"

MapReader::MapReader (Map& map)
  : yap::MapReader (map)
  , map_ (map)
{
}

MapReader::~MapReader ()
{
}

void MapReader::Visit (yap::XmlReader& visitable)
{
  yap::MapReader::Visit (visitable);
}
