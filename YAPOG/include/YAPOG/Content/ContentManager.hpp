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

namespace yap
{
  class YAPOG_LIB ContentManager
  {
    public:

      DISALLOW_COPY(ContentManager);

      static ContentManager& Instance ();

      void Init (const Path& rootPath);

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

    private:

      ContentManager (const Path& rootPath);
      ~ContentManager ();

      static const Path DEFAULT_ROOT_PATH;
      static const Path DEFAULT_IMAGE_PATH;
      static const Path DEFAULT_TEXTURE_PATH;
      static const Path DEFAULT_FONT_PATH;
      static const Path DEFAULT_SOUND_BUFFER_PATH;
      static const Path DEFAULT_MUSIC_PATH;

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
