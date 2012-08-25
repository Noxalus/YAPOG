#include "YAPOG/Graphics/Gui/Game/World/MapRootWidget.hpp"

namespace yap
{
  MapRootWidget::MapRootWidget ()
    : GameWorldWidget ()
    , currentMap_ (nullptr)
  {
  }

  MapRootWidget::~MapRootWidget ()
  {
  }

  void MapRootWidget::SetCurrentMap (Map* map)
  {
    currentMap_ = map;
  }

  Map& MapRootWidget::GetCurrentMap ()
  {
    return *currentMap_;
  }
} // namespace yap
