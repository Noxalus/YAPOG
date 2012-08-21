#include "Gui/MapPlayerInfoPanel.hpp"

#include "YAPOG/Graphics/Gui/Label.hpp"
#include "YAPOG/Graphics/Gui/Game/World/GameWorldGuiManager.hpp"
#include "YAPOG/Graphics/ICamera.hpp"

#include "World/Map/Player.hpp"

namespace ycl
{
  MapPlayerInfoPanel::MapPlayerInfoPanel ()
    : yap::GameWorldWidget ()
    , player_ (nullptr)
    , playerNameLabel_ (nullptr)
  {
  }

  MapPlayerInfoPanel::~MapPlayerInfoPanel ()
  {
  }

  void MapPlayerInfoPanel::Init (Player& player)
  {
    player_ = &player;

    playerNameLabel_ = new yap::Label ("<PLAYER>");
    AddChild (*playerNameLabel_);

    player.OnMoved += [this] (
      yap::DynamicWorldObject& sender,
      const yap::Vector2& args)
    {
      UpdateLabel (sender.GetPosition ());
    };
  }

  void MapPlayerInfoPanel::HandleSetGameWorldParent (
    const GameWorldWidget& gameWorldParent)
  {
    GameWorldWidget::HandleSetGameWorldParent (gameWorldParent);

    GetGameWorldRoot ().GetWorldCamera ().OnMovedEvent () += [this] (
      yap::ICamera& sender,
      const yap::Vector2& args)
    {
      UpdateLabel (player_->GetPosition ());
    };
  }

  void MapPlayerInfoPanel::UpdateLabel (const yap::Vector2& position)
  {
    playerNameLabel_->SetPosition (
      GetGameWorldRoot ().WorldPointToGuiPoint (
        yap::Vector3 (
          position.x,
          position.y,
          0.0f)));
  }
} // namespace ycl
