#include "GameScreen/OptionScreen.hpp"

namespace ycl
{
  const yap::ScreenType OptionScreen::DEFAULT_NAME = "Option";

  OptionScreen::OptionScreen (yap::IDrawingContext& context)
    : BaseScreen (DEFAULT_NAME, context)
  {
  }

  OptionScreen::~OptionScreen ()
  {
  }
} // namespace ycl
