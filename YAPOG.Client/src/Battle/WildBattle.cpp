#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

#include "Battle/WildBattle.hpp"
#include "Battle/Phase/BeginBattlePhase.hpp"
#include "Battle/Battle.hpp"

namespace ycl
{
  WildBattle::WildBattle (
    yap::IBattleEntity& playerTeam, 
    yap::IBattleEntity& wildPokemon)
    : Battle (playerTeam, wildPokemon)
  {
  }

  WildBattle::~WildBattle ()
  {
  }

  void WildBattle::HandleInit ()
  {
    Battle::HandleInit ();

    BeginBattlePhase* beginBattlePhase = new BeginBattlePhase ();

    AddPhase (yap::BattlePhaseState::BeginBattle, beginBattlePhase);
  }

  void WildBattle::HandleUpdate (const yap::Time& dt)
  {
    Battle::HandleUpdate (dt);
  }

  void WildBattle::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool WildBattle::IsVisible () const
  {
    return isVisible_;
  }

  void WildBattle::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void WildBattle::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void WildBattle::HandleDraw (yap::IDrawingContext& context)
  {
    /*
    background_->Draw (context);
    playerGround_->Draw (context);
    opponentGround_->Draw (context);
    */
    //battleTextLabel_->Draw (context);
  }

  void WildBattle::HandleShow (bool isVisible)
  {
  }

  void WildBattle::HandleChangeColor (const sf::Color& color)
  {
  }

} // namespace yap