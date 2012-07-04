#include "YAPOG/System/IO/Xml/XmlReader.hpp"

#include "Configuration/ConfigurationReader.hpp"
#include "Configuration/GameData.hpp"

namespace ycl
{
  ConfigurationReader::ConfigurationReader (
    GameData& gameData,
    const yap::String& xmlRootNodeName)
    : yap::ConfigurationReader (xmlRootNodeName)
    , gameData_ (gameData)
  {
  }

  ConfigurationReader::~ConfigurationReader ()
  {
  }

  void ConfigurationReader::HandleVisitXmlReader (yap::XmlReader& visitable)
  {
    yap::ConfigurationReader::HandleVisitXmlReader (visitable);

    gameData_.remoteIPAddress_ = visitable.ReadString ("IP");

    gameData_.windowSize_ = visitable.ReadVector2 ("WindowSize");
    gameData_.resolution_ = visitable.ReadVector2 ("Resolution");

    gameData_.contentPath_ = visitable.ReadString ("ContentPath");
    gameData_.texturePath_ = visitable.ReadString ("TexturePath");
    gameData_.fontPath_ = visitable.ReadString ("FontPath");
    gameData_.musicPath_ = visitable.ReadString ("MusicPath");
    gameData_.soundPath_ = visitable.ReadString ("SoundPath");
  }
} // namespace ycl
