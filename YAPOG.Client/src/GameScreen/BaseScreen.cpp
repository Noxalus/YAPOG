#include "YAPOG/System/IO/Log/DebugLogger.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/World/Map/WorldObjectStateFactory.hpp"
#include "YAPOG/Content/ContentManager.hpp"

#include "GameScreen/BaseScreen.hpp"
#include "Client/Session.hpp"

namespace ycl
{
  BaseScreen::BaseScreen (
    const yap::ScreenType& screenType,
    yap::IDrawingContext& context)
    : yap::GameScreen (screenType)
    , context_ (context)
    , session_ (Session::Instance ())
    , contentManager_ (yap::ContentManager::Instance ())
    , objectFactory_ (yap::ObjectFactory::Instance ())
    , worldObjectStateFactory_ (yap::WorldObjectStateFactory::Instance ())
    , gameInputManager_ (yap::GameInputManager::Instance ())
    , logger_ (yap::DebugLogger::Instance ())
  {
  }

  BaseScreen::~BaseScreen ()
  {
  }
} // namespace ycl
