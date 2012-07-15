#ifndef YAPOG_AUDIOMANAGER_HPP
# define YAPOG_AUDIOMANAGER_HPP

# include "SFML/Audio/Music.hpp"
# include "SFML/Audio/Sound.hpp"

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yap
{
  class YAPOG_LIB AudioManager
  {
    DISALLOW_COPY (AudioManager);

  public:
    static AudioManager& Instance ();
    void PlayMusic (const String& musicName);
    void PlaySound (const String&soundName);
    void PlayCry (const ID& staticID);

  private:
    AudioManager ();
    ~AudioManager ();
    sf::Music* currentMusic_;
    sf::Sound* currentSound_;
  };
} // namespace yap

#endif // YAPOG_AUDIOMANAGER_HPP
