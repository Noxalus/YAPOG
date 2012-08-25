#ifndef YAPOG_AUDIOMANAGER_HPP
# define YAPOG_AUDIOMANAGER_HPP

# include "SFML/Audio/Music.hpp"
# include "SFML/Audio/Sound.hpp"

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class YAPOG_LIB AudioManager
  {
    DISALLOW_COPY (AudioManager);

  public:
    static AudioManager& Instance ();
    void PlayMusic (const String& musicName, bool fromBegin = true);
    void PlaySound (const String&soundName);
    void ResumePreviousMusic ();

  private:
    AudioManager ();
    ~AudioManager ();
    sf::Music* currentMusic_;
    sf::Music* previousMusic_;
    sf::Sound* currentSound_;
  };
} // namespace yap

#endif // YAPOG_AUDIOMANAGER_HPP
