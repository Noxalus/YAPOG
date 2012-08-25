#include "YAPOG/Audio/AudioManager.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Content/ContentManager.hpp"

namespace yap
{
  AudioManager::AudioManager ()
    : currentMusic_ (nullptr)
    , previousMusic_ (nullptr)
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

  void AudioManager::PlayMusic (const String& musicName, bool fromBegin)
  {    
    if (currentMusic_ != nullptr)
    {
      currentMusic_->pause ();
      previousMusic_ = currentMusic_;
    }

    currentMusic_ = &ContentManager::Instance ().LoadMusic (musicName);

    currentMusic_->setLoop (true);

    if (fromBegin)
      currentMusic_->stop ();

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

  void AudioManager::ResumePreviousMusic ()
  {
    if (previousMusic_ != nullptr)
    {
      void* tmp = currentMusic_;

      currentMusic_->pause ();
      previousMusic_->play ();
      currentMusic_ = previousMusic_;
      previousMusic_ = (sf::Music*)tmp;
    }
  }

} // namespace yap
