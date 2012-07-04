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
  const yap::String GameData::DEFAULT_REMOTE_IP_ADDRESS = "localhost";

  const yap::Vector2 GameData::DEFAULT_WINDOW_SIZE = yap::Vector2 (800, 600);
  const yap::Vector2 GameData::DEFAULT_RESOLUTION = yap::Vector2 (800, 600);

  const yap::String GameData::DEFAULT_CONTENT_PATH = "Content";
  const yap::String GameData::DEFAULT_TEXTURE_PATH = "Texture";
  const yap::String GameData::DEFAULT_FONT_PATH = "Font";
  const yap::String GameData::DEFAULT_MUSIC_PATH = "Music";
  const yap::String GameData::DEFAULT_SOUND_PATH = "Sound";

  GameData::GameData ()
    : remoteIPAddress_ (DEFAULT_REMOTE_IP_ADDRESS)
    , windowSize_ (DEFAULT_WINDOW_SIZE)
    , resolution_ (DEFAULT_RESOLUTION)
    , contentPath_ (DEFAULT_CONTENT_PATH)
    , texturePath_ (DEFAULT_TEXTURE_PATH)
    , fontPath_ (DEFAULT_FONT_PATH)
    , musicPath_ (DEFAULT_MUSIC_PATH)
    , soundPath_ (DEFAULT_SOUND_PATH)
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

  const yap::Vector2& GameData::WindowSize ()
  {
    return Instance ().windowSize_;
  }

  const yap::Vector2& GameData::Resolution ()
  {
    return Instance ().resolution_;
  }

  const yap::String& GameData::ContentPath ()
  {
    return Instance ().contentPath_;
  }

  const yap::String& GameData::TexturePath ()
  {
    return Instance ().texturePath_;
  }

  const yap::String& GameData::FontPath ()
  {
    return Instance ().fontPath_;
  }

  const yap::String& GameData::MusicPath ()
  {
    return Instance ().musicPath_;
  }

  const yap::String& GameData::SoundPath ()
  {
    return Instance ().soundPath_;
  }
} // namespace ycl
