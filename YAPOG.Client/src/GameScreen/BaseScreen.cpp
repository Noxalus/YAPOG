#include "GameScreen/BaseScreen.hpp"
#include "Client/Session.hpp"

namespace ycl
{
  BaseScreen::BaseScreen (const yap::ScreenType& screenType)
    : yap::GameScreen (screenType)
    , session_ (Session::Instance ())
  {
  }

  BaseScreen::~BaseScreen ()
  {
  }
} // namespace ycl
