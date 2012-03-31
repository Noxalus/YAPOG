#ifndef YAPOG_CONTENTMANAGER_HPP
# define YAPOG_CONTENTMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Content/IContentManager.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  typedef String Path;

  class YAPOG_LIB ContentManager : public IContentManager
  {
    public:

      DISALLOW_COPY(ContentManager);

      static ContentManager& Instance ();

      void Init ();
      void Init (const Path& rootPath);

      /// @name IContentManager members.
      /// @{
      virtual sf::Image& LoadImage (const String& name);
      virtual sf::Texture& LoadTexture (const String& name);
      virtual sf::Font& LoadFont (const String& name);
      virtual sf::SoundBuffer& LoadSoundBuffer (const String& name);
      virtual sf::Music& LoadMusic (const String& name);

      virtual void UnloadImage (const String& name);
      virtual void UnloadTexture (const String& name);
      virtual void UnloadFont (const String& name);
      virtual void UnloadSoundBuffer (const String& name);
      virtual void UnloadMusic (const String& name);
      /// @}

    private:

      ContentManager (const Path& rootPath);
      virtual ~ContentManager ();

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
