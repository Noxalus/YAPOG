#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

#include "Battle/Phase/EndBattlePhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  const bool EndBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color EndBattlePhase::DEFAULT_COLOR = sf::Color ();

  EndBattlePhase::EndBattlePhase (
    Battle& battle, 
    BattleInterface& battleInterface)
    : yap::EndBattlePhase (battle)
    , battle_ (battle)
    , battleInterface_  (battleInterface)
  {
  }

  EndBattlePhase::~EndBattlePhase ()
  {
  }

  void EndBattlePhase::HandleStart (const yap::PhaseArgs& args)
  {
    yap::EndBattlePhase::HandleStart (args);

    // Transfert HP from PokemonFighter to Pokemon
    battle_.GetPlayerTeam ().TransfertHP ();
  }

  void EndBattlePhase::HandleUpdate (const yap::Time& dt)
  {
    yap::EndBattlePhase::HandleUpdate (dt);
    battle_.OnBattleEnd (battle_, yap::EmptyEventArgs ());
  }

  void EndBattlePhase::HandleEnd ()
  {
    yap::EndBattlePhase::HandleEnd ();
  }

  void EndBattlePhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool EndBattlePhase::IsVisible () const
  {
    return isVisible_;
  }

  void EndBattlePhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void EndBattlePhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void EndBattlePhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void EndBattlePhase::HandleShow (bool isVisible)
  {
  }

  void EndBattlePhase::HandleChangeColor (const sf::Color& color)
  {
  }
}