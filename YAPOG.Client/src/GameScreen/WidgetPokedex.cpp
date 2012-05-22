#include "GameScreen/GameMainMenu.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

namespace ycl
{

  GameMainMenu::GameMainMenu ()
    : Menu (yap::Menu::Type::VERTICAL, yap::Padding (5, 5, 5, 5), yap::Padding (5, 5, 5, 5), false)
  {  
  }

  void GameMainMenu::Init (yap::String playerName)
  {
  
  }

  GameMainMenu::~GameMainMenu ()
  {
  }
} // namespace ycl
