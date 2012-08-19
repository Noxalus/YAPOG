#include "Gui/MapRootWidget.hpp"

namespace ycl
{
  MapRootWidget::MapRootWidget ()
    : yap::GameWorldWidget ()
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
} // namespace ycl
