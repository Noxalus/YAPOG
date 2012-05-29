#include "GameScreen/CreditScreen.hpp"

namespace ycl
{
  const yap::ScreenType CreditScreen::DEFAULT_NAME = "Credit";

  CreditScreen::CreditScreen ()
    : BaseScreen (DEFAULT_NAME)
  {
  }

  CreditScreen::~CreditScreen ()
  {
  }

  const yap::ScreenType& CreditScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    return BaseScreen::HandleRun (dt, context);
  }
} // namespace ycl
