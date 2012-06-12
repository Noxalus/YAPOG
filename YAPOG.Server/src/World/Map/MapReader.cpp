#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/World/Map/MapElement.hpp"

#include "World/Map/MapReader.hpp"
#include "World/Map/Map.hpp"
#include "World/Map/NPC.hpp"
#include "World/Map/DynamicObjectFactory.hpp"
#include "World/Map/Teleporter.hpp"

namespace yse
{
  MapReader::MapReader (Map& map, const yap::String& xmlRootNodeName)
    : yap::MapReader (map, xmlRootNodeName)
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

  void MapReader::ReadDynamicObjects (yap::XmlReader& reader)
  {
    yap::MapReader::ReadDynamicObjects (reader);

    yap::XmlReaderCollection npcReaders;
    reader.ReadNodes ("NPC", npcReaders);
    for (auto& npcReader : npcReaders)
    {
      yap::ID npcID = npcReader->ReadID (
        yap::XmlHelper::GetAttrNodeName ("id"));

      NPC* npc = DynamicObjectFactory::Instance ().Create<NPC> (
        "NPC",
        npcID);

      yap::Vector2 npcPosition = npcReader->ReadVector2 (
        "position");

      npc->SetPosition (npcPosition);

      map_.AddObject (npc);
    }

    yap::XmlReaderCollection teleporterReaders;
    reader.ReadNodes ("Teleporter", teleporterReaders);
    for (auto& teleporterReader : teleporterReaders)
    {
      yap::ID teleporterID = teleporterReader->ReadID (
        yap::XmlHelper::GetAttrNodeName ("id"));

      Teleporter* teleporter =
        DynamicObjectFactory::Instance ().Create<Teleporter> (
          "Teleporter",
          teleporterID);

      yap::Vector2 teleporterPosition = teleporterReader->ReadVector2 (
        "position");

      teleporter->SetPosition (teleporterPosition);

      map_.AddObject (teleporter);
    }
  }

  void MapReader::ReadStaticObjects (yap::XmlReader& reader)
  {
    yap::MapReader::ReadStaticObjects (reader);

    yap::XmlReaderCollection mapElementReaders;
    reader.ReadNodes ("MapElement", mapElementReaders);
    for (auto& mapElementReader : mapElementReaders)
    {
      yap::ID mapElementID = mapElementReader->ReadID (
        yap::XmlHelper::GetAttrNodeName ("id"));

      yap::MapElement* mapElement =
        yap::ObjectFactory::Instance ().Create<yap::MapElement> (
          "MapElement",
          mapElementID);

      yap::Vector2 mapElementPosition = mapElementReader->ReadVector2 (
        "position");

      mapElement->SetPosition (mapElementPosition);

      map_.AddObject (mapElement);
    }
  }
} // namespace yse
