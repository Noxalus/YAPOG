#include "Gui/MapRootWidget.hpp"

#include "YAPOG/Collection/Queue.hpp"

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
    Map* oldMap = currentMap_;

    currentMap_ = map;

    HandleSetCurrentMap (oldMap, map);
  }

  Map& MapRootWidget::GetCurrentMap ()
  {
    return *currentMap_;
  }

  void MapRootWidget::AddPlayerInfoPanel (Player* player)
  {
    MapPlayerInfoPanel* playerInfoPanel = new MapPlayerInfoPanel ();

    playerInfoPanel->Init (*player);

    playerInfoPanels_.Add (player, playerInfoPanel);

    AddGameWorldWidget (playerInfoPanel);
  }

  void MapRootWidget::RemovePlayerInfoPanel (Player* player)
  {
    MapPlayerInfoPanel* playerInfoPanel = playerInfoPanels_[player];

    RemoveGameWorldWidget (playerInfoPanel);

    playerInfoPanels_.Remove (player);
  }

  void MapRootWidget::HandleSetCurrentMap (Map* oldMap, Map* map)
  {
    if (oldMap != nullptr)
    {
      oldMap->OnPlayerAdded.RemoveHandler ("AddPlayerInfoPanelHandler");
      oldMap->OnPlayerAdded.RemoveHandler ("RemovePlayerInfoPanelHandler");

      Clear ();
    }

    currentMap_->OnPlayerAdded.AddHandler (
      "AddPlayerInfoPanelHandler",
      [this] (
        Map& sender,
        Player& args)
      {
        AddPlayerInfoPanel (&args);
      });

      currentMap_->OnPlayerRemoved.AddHandler (
        "RemovePlayerInfoPanelHandler",
        [this] (
          Map& sender,
          Player& args)
        {
          RemovePlayerInfoPanel (&args);
        });
  }

  void MapRootWidget::Clear ()
  {
    yap::collection::Queue<Player*> playerInfoPanelsToRemove;
    for (auto& playerPlayerInfoPanelPair : playerInfoPanels_)
      playerInfoPanelsToRemove.Enqueue (playerPlayerInfoPanelPair.first);

    while (!playerInfoPanelsToRemove.IsEmpty ())
    {
      Player* player = playerInfoPanelsToRemove.Dequeue (player);

      RemovePlayerInfoPanel (player);
    }
  }
} // namespace ycl
