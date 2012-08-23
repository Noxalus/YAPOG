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

    playerNameLabel_ = new yap::Label (player.GetName ());
    playerNameLabel_->SetTextSize (12);
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

  /// [TMP]
  void MapPlayerInfoPanel::UpdateLabel (const yap::Vector2& position)
  {
    playerNameLabel_->SetPosition (
      GetGameWorldRoot ().WorldPointToGuiPoint (
        yap::Vector3 (
          position.x - playerNameLabel_->GetSize ().x / 2.0f + 16.0f,
          position.y - 24.0f,
          0.0f)));
  }
} // namespace ycl
