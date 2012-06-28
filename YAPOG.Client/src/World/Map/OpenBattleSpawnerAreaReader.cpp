#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"
#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"

#include "World/Map/OpenBattleSpawnerAreaReader.hpp"
#include "World/Map/OpenBattleSpawnerArea.hpp"

namespace ycl
{
  const yap::String
  OpenBattleSpawnerAreaReader::DEFAULT_XML_BASE_SPRITE_TYPE_NODE_NAME =
    "baseSpriteType";

  OpenBattleSpawnerAreaReader::OpenBattleSpawnerAreaReader (
    OpenBattleSpawnerArea& openBattleSpawnerArea,
    const yap::String& xmlRootNodeName)
    : yap::OpenBattleSpawnerAreaReader (openBattleSpawnerArea, xmlRootNodeName)
    , openBattleSpawnerArea_ (openBattleSpawnerArea)
  {
  }

  OpenBattleSpawnerAreaReader::~OpenBattleSpawnerAreaReader ()
  {
  }

  void OpenBattleSpawnerAreaReader::Visit (yap::XmlReader& visitable)
  {
    yap::OpenBattleSpawnerAreaReader::Visit (visitable);

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    auto baseSpriteReader = reader->ChangeRoot ("baseSprite");

    yap::String baseSpriteType = baseSpriteReader->ReadString ("type");

    yap::ISprite* baseSprite =
      yap::ObjectFactory::Instance ().Create<yap::ISprite> (
        baseSpriteType,
        *baseSpriteReader,
        baseSpriteType);

    openBattleSpawnerArea_.SetBaseSprite (baseSprite);
  }
} // namespace ycl
