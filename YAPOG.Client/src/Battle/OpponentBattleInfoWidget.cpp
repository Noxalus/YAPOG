#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/Gui/BackgroundWidget.hpp"

#include "YAPOG/Graphics/Gui/BorderWidget.hpp"

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
    yap::BackgroundWidget* background = 
      new yap::BackgroundWidget ("Pictures/opponent_battle_info.png", false);
    verticalLayout_.SetBackground (*background);
    verticalLayout_.SetBorder (*new yap::BorderWidget ("Test/black.png"));
    horizontalLayout_.SetBorder (*new yap::BorderWidget ("Test/red.png"));
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
