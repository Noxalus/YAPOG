#include "GameScreen/CreditScreen.hpp"

namespace ycl
{
  const yap::ScreenType CreditScreen::DEFAULT_NAME = "Credit";

  CreditScreen::CreditScreen (yap::IDrawingContext& context)
    : BaseScreen (DEFAULT_NAME, context)
  {
  }

  CreditScreen::~CreditScreen ()
  {
  }

  void CreditScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    BaseScreen::HandleRun (dt, context);
  }
} // namespace ycl
