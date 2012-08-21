#include "Gui/MapRootWidget.hpp"
#include "World/Map/Map.hpp"
#include "Gui/MapPlayerInfoPanel.hpp"

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

    HandleSetCurrentMap (map);
  }

  Map& MapRootWidget::GetCurrentMap ()
  {
    return *currentMap_;
  }

  void MapRootWidget::HandleSetCurrentMap (Map* map)
  {
    currentMap_->OnPlayerAdded += [this] (
      Map& sender,
      Player& args)
    {
      HandlePlayerAdded (args);
    };
  }

  void MapRootWidget::HandlePlayerAdded (Player& player)
  {
    MapPlayerInfoPanel* playerInfoPanel = new MapPlayerInfoPanel ();

    playerInfoPanel->Init (player);

    AddGameWorldWidget (playerInfoPanel);
  }
} // namespace ycl
