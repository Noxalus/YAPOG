#include "YAPOG/Content/ContentManager.hpp"
#include "YAPOG/System/Error/ContentLoadingFailException.hpp"
#include "YAPOG/Game/ID.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  const Path ContentManager::DEFAULT_ROOT_PATH = Path ("Content/");
  const Path ContentManager::DEFAULT_IMAGE_PATH = Path ("Image/");
  const Path ContentManager::DEFAULT_TEXTURE_PATH = Path ("Image/");
  const Path ContentManager::DEFAULT_FONT_PATH = Path ("Font/");
  const Path ContentManager::DEFAULT_SOUND_BUFFER_PATH = Path ("Sound/");
  const Path ContentManager::DEFAULT_MUSIC_PATH = Path ("Sound/");

  ContentManager::ContentManager (const Path& rootPath)
    : rootPath_ (rootPath)
    , imagePath_ (DEFAULT_IMAGE_PATH)
    , texturePath_ (DEFAULT_TEXTURE_PATH)
    , fontPath_ (DEFAULT_FONT_PATH)
    , soundBufferPath_ (DEFAULT_SOUND_BUFFER_PATH)
    , musicPath_ (DEFAULT_MUSIC_PATH)
    , images_ ()
    , textures_ ()
    , fonts_ ()
    , soundBuffers_ ()
    , musics_ ()
  {
  }

  ContentManager::~ContentManager ()
  {
    for (const auto& it : images_)
      delete it.second;

    for (const auto& it : textures_)
      delete it.second;

    for (const auto& it : fonts_)
      delete it.second;

    for (const auto& it : soundBuffers_)
      delete it.second;

    for (const auto& it : musics_)
      delete it.second;
  }

  ContentManager& ContentManager::Instance ()
  {
    static ContentManager instance (DEFAULT_ROOT_PATH);

    return instance;
  }

  void ContentManager::Init (const Path& rootPath)
  {
    rootPath_ = rootPath;
  }

  const Path& ContentManager::GetContentPath () const
  {
    return rootPath_;
  }

  sf::Image& ContentManager::LoadImage (const String& name)
  {
    if (images_.Contains (name))
      return *images_[name];

    sf::Image* image = new sf::Image;

    String path = (rootPath_ + imagePath_ + Path (name)).GetValue ();
    if (!image->loadFromFile (path))
      throw ContentLoadingFailException (path);

    images_.Add (name, image);

    return *image;
  }

  sf::Texture& ContentManager::LoadTexture (const String& name)
  {
    if (textures_.Contains (name))
      return *textures_[name];

    sf::Texture* texture = new sf::Texture;

    String path = (rootPath_ + texturePath_ + Path (name)).GetValue ();
    if (!texture->loadFromFile (path))
      throw ContentLoadingFailException (path);

    textures_.Add (name, texture);

    return *texture;
  }

  sf::Font& ContentManager::LoadFont (const String& name)
  {
    if (fonts_.Contains (name))
      return *fonts_[name];

    sf::Font* font = new sf::Font;

    String path = (rootPath_ + fontPath_ + Path (name)).GetValue ();
    if (!font->loadFromFile (path))
      throw ContentLoadingFailException (path);

    fonts_.Add (name, font);

    return *font;
  }

  sf::SoundBuffer& ContentManager::LoadSoundBuffer (const String& name)
  {
    if (soundBuffers_.Contains (name))
      return *soundBuffers_[name];

    sf::SoundBuffer* soundBuffer = new sf::SoundBuffer;

    String path = (rootPath_ + soundBufferPath_ + Path (name)).GetValue ();
    if (!soundBuffer->loadFromFile (path))
      throw ContentLoadingFailException (path);

    soundBuffers_.Add (name, soundBuffer);

    return *soundBuffer;
  }

  sf::Music& ContentManager::LoadMusic (const String& name)
  {
    if (musics_.Contains (name))
      return *musics_[name];

    sf::Music* music = new sf::Music;

    String path = (rootPath_ + musicPath_ + Path (name)).GetValue ();
    if (!music->openFromFile (path))
      throw ContentLoadingFailException (path);

    musics_.Add (name, music);

    return *music;
  }

  void ContentManager::UnloadImage (const String& name)
  {
    delete images_[name];
    images_.Remove (name);
  }

  void ContentManager::UnloadTexture (const String& name)
  {
    delete textures_[name];
    textures_.Remove (name);
  }

  void ContentManager::UnloadFont (const String& name)
  {
    delete fonts_[name];
    fonts_.Remove (name);
  }

  void ContentManager::UnloadSoundBuffer (const String& name)
  {
    delete soundBuffers_[name];
    soundBuffers_.Remove (name);
  }

  void ContentManager::UnloadMusic (const String& name)
  {
    delete musics_[name];
    musics_.Remove (name);
  }

  IFStream& ContentManager::LoadFile (const String& name, IFStream& iFStream)
  {
    String path = (rootPath_ + Path (name)).GetValue ();

    iFStream.open (path);

    if (!iFStream.is_open ())
      throw ContentLoadingFailException (path);

    return iFStream;
  }

  IFStream& ContentManager::LoadFile (
    const Path& rootPath,
    const ID& id,
    IFStream& iFStream)
  {
    return LoadFile (
      (rootPath + Path (StringHelper::ToString (id.GetValue ()))).GetValue (),
      iFStream);
  }
} // namespace yap
