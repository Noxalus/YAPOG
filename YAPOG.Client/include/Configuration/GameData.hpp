#ifndef YAPOG_CLIENT_GAMEDATA_HPP
# define YAPOG_CLIENT_GAMEDATA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace ycl
{
  class GameData
  {
      friend class ConfigurationReader;

      DISALLOW_COPY(GameData);

    public:

      static void Init (const yap::String& configurationFileName);

      static const yap::String& RemoteIPAddress ();

      static const yap::Vector2& WindowSize ();
      static const yap::Vector2& Resolution ();

      static const yap::String& ContentPath ();
      static const yap::String& TexturePath ();
      static const yap::String& FontPath ();
      static const yap::String& MusicPath ();
      static const yap::String& SoundPath ();

    private:

      static GameData& Instance ();

      GameData ();
      ~GameData ();

      static const yap::String DEFAULT_CONFIGURATION_FILE_ROOT_NODE_NAME;

      static const yap::String DEFAULT_REMOTE_IP_ADDRESS;

      static const yap::Vector2 DEFAULT_WINDOW_SIZE;
      static const yap::Vector2 DEFAULT_RESOLUTION;

      static const yap::String DEFAULT_CONTENT_PATH;
      static const yap::String DEFAULT_TEXTURE_PATH;
      static const yap::String DEFAULT_FONT_PATH;
      static const yap::String DEFAULT_MUSIC_PATH;
      static const yap::String DEFAULT_SOUND_PATH;

      yap::String remoteIPAddress_;

      yap::Vector2 windowSize_;
      yap::Vector2 resolution_;

      yap::String contentPath_;
      yap::String texturePath_;
      yap::String fontPath_;
      yap::String musicPath_;
      yap::String soundPath_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_GAMEDATA_HPP
