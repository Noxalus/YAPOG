#include "YAPOG/Audio/AudioManager.hpp"

#include "Gui/GameMenu.hpp"

namespace ycl
{

  GameMenu::GameMenu (
    yap::Menu::Type menuType,
        const yap::Padding& ext,
        const yap::Padding& in,
        bool fixed)
        : Menu (menuType, ext, in, fixed)
  {
  }

  GameMenu::~GameMenu ()
  {
  }

  bool GameMenu::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (yap::Menu::HandleOnEvent (guiEvent))
      return true;

    if (guiEvent.type == sf::Event::KeyPressed)
      return true;

    return false;
  }

  void GameMenu::HandleItemActivated ()
  {
    yap::Menu::HandleItemActivated ();

    // Play a sound
    yap::AudioManager::Instance ().PlaySound ("SE/Choose.wav");
  }

  void GameMenu::HandleItemSelected ()
  {
    yap::Menu::HandleItemSelected ();

    // Play a sound
    yap::AudioManager::Instance ().PlaySound ("SE/Select.wav");
  }

} // namespace ycl
