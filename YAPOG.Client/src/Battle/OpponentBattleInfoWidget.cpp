#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"

#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

#include "Battle/OpponentBattleInfoWidget.hpp"

namespace ycl
{
  OpponentBattleInfoWidget::OpponentBattleInfoWidget ()
    : opponentName_ ("COUCOU")
    , horizontalLayout_ ()
    , verticalLayout_ ()
  {
    horizontalLayout_.SetSize (yap::Vector2 (200.f, 50.f));
    verticalLayout_.SetSize (yap::Vector2 (300.f, 84.f));
    yap::WidgetBackground* background = 
      new yap::WidgetBackground ("Pictures/opponent_battle_info.png", false);
    verticalLayout_.SetBackground (*background);
    verticalLayout_.SetBorder (*new yap::WidgetBorder ("black.png"));
    horizontalLayout_.SetBorder (*new yap::WidgetBorder ("red.png"));
    opponentName_.ChangeColor (sf::Color::Black);

    horizontalLayout_.AddChild (opponentName_);
    verticalLayout_.AddChild (horizontalLayout_, yap::LayoutBox::Align::LEFT);
    this->AddChild (verticalLayout_);
  }

  /// Getters
  yap::Label& OpponentBattleInfoWidget::GetOpponentName ()
  {
    return opponentName_;
  }
}
