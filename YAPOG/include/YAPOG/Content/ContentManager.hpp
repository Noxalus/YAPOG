#ifndef YAPOG_CONTENTMANAGER_HPP
# define YAPOG_CONTENTMANAGER_HPP

# include <SFML/Graphics/Image.hpp>
# include <SFML/Graphics/Texture.hpp>
# include <SFML/Graphics/Font.hpp>
# include <SFML/Audio/SoundBuffer.hpp>
# include <SFML/Audio/Music.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/System/Path.hpp"
# include "YAPOG/System/IOStream.hpp"

namespace yap
{
  class ID;

  class YAPOG_LIB ContentManager
  {
      DISALLOW_COPY(ContentManager);

    public:

      static ContentManager& Instance ();

      void Init (const Path& rootPath);
      const Path& GetContentPath () const;

      void SetImagePath (const Path& path);
      void SetTexturePath (const Path& path);
      void SetFontPath (const Path& path);
      void SetSoundBufferPath (const Path& path);
      void SetMusicPath (const Path& path);

      sf::Image& LoadImage (const String& name);
      sf::Texture& LoadTexture (const String& name);
      sf::Font& LoadFont (const String& name);
      sf::SoundBuffer& LoadSoundBuffer (const String& name);
      sf::Music& LoadMusic (const String& name);

      void UnloadImage (const String& name);
      void UnloadTexture (const String& name);
      void UnloadFont (const String& name);
      void UnloadSoundBuffer (const String& name);
      void UnloadMusic (const String& name);

      IFStream& LoadFile (const String& name, IFStream& iFStream);
      IFStream& LoadFile (
        const Path& rootPath,
        const ID& id,
        IFStream& iFStream);

    private:

      ContentManager (const Path& rootPath);
      ~ContentManager ();

      static const Path DEFAULT_ROOT_PATH;
      static const Path DEFAULT_IMAGE_PATH;
      static const Path DEFAULT_TEXTURE_PATH;
      static const Path DEFAULT_FONT_PATH;
      static const Path DEFAULT_SOUND_BUFFER_PATH;
      static const Path DEFAULT_MUSIC_PATH;

      static const String DEFAULT_DATA_RESOURCE_FILE_EXTENSION;

      Path rootPath_;

      Path imagePath_;
      Path texturePath_;
      Path fontPath_;
      Path soundBufferPath_;
      Path musicPath_;

      collection::Map<String, sf::Image*> images_;
      collection::Map<String, sf::Texture*> textures_;
      collection::Map<String, sf::Font*> fonts_;
      collection::Map<String, sf::SoundBuffer*> soundBuffers_;
      collection::Map<String, sf::Music*> musics_;
  };
} // namespace yap

#endif // YAPOG_CONTENTMANAGER_HPP
