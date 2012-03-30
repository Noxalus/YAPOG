#ifndef YAPOG_ICONTENTMANAGER_HPP
# define YAPOG_ICONTENTMANAGER_HPP

# include <SFML/Graphics/Image.hpp>
# include <SFML/Graphics/Texture.hpp>
# include <SFML/Graphics/Font.hpp>
# include <SFML/Audio/SoundBuffer.hpp>
# include <SFML/Audio/Music.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  struct IContentManager
  {
      virtual ~IContentManager () {}

      virtual sf::Image& LoadImage (const String& name) = 0;
      virtual sf::Texture& LoadTexture (const String& name) = 0;
      virtual sf::Font& LoadFont (const String& name) = 0;
      virtual sf::SoundBuffer& LoadSoundBuffer (const String& name) = 0;
      virtual sf::Music& LoadMusic (const String& name) = 0;

      virtual void UnloadImage (const String& name) = 0;
      virtual void UnloadTexture (const String& name) = 0;
      virtual void UnloadFont (const String& name) = 0;
      virtual void UnloadSoundBuffer (const String& name) = 0;
      virtual void UnloadMusic (const String& name) = 0;
  };
} // namespace yap

#endif // YAPOG_ICONTENTMANAGER_HPP
