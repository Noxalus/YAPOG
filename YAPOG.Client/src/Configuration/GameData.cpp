#include "YAPOG/System/IOStream.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"

#include "Configuration/GameData.hpp"
#include "Configuration/ConfigurationReader.hpp"

namespace ycl
{
  const yap::String GameData::DEFAULT_CONFIGURATION_FILE_ROOT_NODE_NAME =
    "Configuration";
  const yap::String GameData::DEFAULT_REMOVE_IP_ADDRESS = "localhost";

  GameData::GameData ()
    : remoteIPAddress_ (DEFAULT_REMOVE_IP_ADDRESS)
  {
  }

  GameData::~GameData ()
  {
  }

  GameData& GameData::Instance ()
  {
    static GameData instance;

    return instance;
  }

  void GameData::Init (const yap::String& configurationFileName)
  {
    yap::IFStream configurationFile;
    configurationFile.open (configurationFileName);

    if (!configurationFile.is_open ())
      YAPOG_THROW(
        "Failed to load configuration file: `" +
        configurationFileName +
        "'.");

    ConfigurationReader configurationReader (
      Instance (),
      DEFAULT_CONFIGURATION_FILE_ROOT_NODE_NAME);

    yap::XmlReader xmlReader (
      configurationFile,
      DEFAULT_CONFIGURATION_FILE_ROOT_NODE_NAME);

    xmlReader.Accept (configurationReader);
  }

  const yap::String& GameData::RemoteIPAddress ()
  {
    return Instance ().remoteIPAddress_;
  }
} // namespace ycl
