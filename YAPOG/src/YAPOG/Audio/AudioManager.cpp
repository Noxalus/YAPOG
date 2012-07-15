#include "YAPOG/Audio/AudioManager.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Content/ContentManager.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  AudioManager::AudioManager ()
    : currentMusic_ (nullptr)
    , currentSound_ (new sf::Sound ())
  {
  }

  AudioManager::~AudioManager ()
  {
  }

  AudioManager& AudioManager::Instance ()
  {
    static  AudioManager instance_;

    return instance_;
  }

  void AudioManager::PlayMusic (const String& musicName)
  {    
    if (currentMusic_ != nullptr)
      currentMusic_->stop ();

    currentMusic_ = &ContentManager::Instance ().LoadMusic (musicName);

    currentMusic_->setLoop (true);
    currentMusic_->play ();
  }

  void AudioManager::PlaySound (const String& soundName)
  {    
    if (currentSound_ != nullptr)
      currentSound_->stop ();

    currentSound_->setBuffer (
      ContentManager::Instance ().LoadSoundBuffer (soundName));

    currentSound_->play ();
  }

  void AudioManager::PlayCry (const ID& staticID)
  {
    PlaySound ("Cries/" + 
      StringHelper::ToString (staticID.GetValue ()) + ".wav");
  }

} // namespace yap
