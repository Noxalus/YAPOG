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

  void CreditScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    BaseScreen::HandleRun (dt, context);
  }
} // namespace ycl
