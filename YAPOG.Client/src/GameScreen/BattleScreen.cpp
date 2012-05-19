#include "GameScreen/BattleScreen.hpp"

namespace ycl
{
  const yap::ScreenType BattleScreen::DEFAULT_NAME = "Battle";

  BattleScreen::BattleScreen ()
    : BaseScreen (DEFAULT_NAME)
  {
  }

  BattleScreen::~BattleScreen ()
  {
  }
} // namespace ycl
