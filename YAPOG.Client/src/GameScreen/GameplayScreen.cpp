#include "GameScreen/GameplayScreen.hpp"

namespace ycl
{
  GameplayScreen::GameplayScreen ()
    : BaseScreen ("Gameplay")
    , world_ ()
  {
  }

  GameplayScreen::~GameplayScreen ()
  {
  }

  const yap::ScreenType& GameplayScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    world_.Update (dt);

    world_.Draw (context);

    return BaseScreen::HandleRun (dt, context);
  }
} // namespace ycl
