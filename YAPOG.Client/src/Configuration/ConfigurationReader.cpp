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
  }
} // namespace ycl
