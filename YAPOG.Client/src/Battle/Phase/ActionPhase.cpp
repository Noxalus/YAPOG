#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"
#include "YAPOG/Game/Pokemon/PokemonMove.hpp"
#include "YAPOG/Game/Pokemon/PokemonMoveSet.hpp"

#include "Battle/Phase/ActionPhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  const bool ActionPhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color ActionPhase::DEFAULT_COLOR = sf::Color ();

  ActionPhase::ActionPhase (Battle& battle, BattleInterface& battleInterface)
    : yap::ActionPhase (battle)
    , battle_ (battle)
    , battleInterface_ (battleInterface)
  {
  }

  ActionPhase::~ActionPhase ()
  {
  }

  void ActionPhase::HandleStart (const yap::PhaseArgs& args)
  {
    yap::ActionPhase::HandleStart (args);

    battleInterface_.GetBattleInfoDialogBox ().Show (true);
    battleInterface_.GetBattleInfoDialogBox ().SetEnable (true);

    if (playerIsFirst_)
    {
      battleInterface_.GetBattleInfoDialogBox ().AddText (
        battle_.GetPlayerTeam ().GetName () + " utilise "
        + battle_.GetPlayerTeam ().GetMove (phaseArgs_.index_).GetName () 
        + " !");

      battleInterface_.GetBattleInfoDialogBox ().AddText (
        battle_.GetOpponent ().GetName () + " utilise "
        + battle_.GetOpponent ().GetMove (opponentMoveIndex_).GetName () 
        + " !");

      battleInterface_.GetBattleInfoDialogBox ().OnTextChanged.AddHandler (
        "ACTION_TEXT_SKIPPED",
        [&] (const yap::BaseWidget& sender, const yap::EmptyEventArgs& args)
      {
        if (textSkippedNumber_ == 0)
          playerAttack_ = true;
        else if (textSkippedNumber_ == 1)
        {
          opponentAttack_ = true;
          nextPhase_ = true;
        }

        textSkippedNumber_++;
      });
    }
    else
    {
      battleInterface_.GetBattleInfoDialogBox ().AddText (
        battle_.GetOpponent ().GetName () + " utilise "
        + battle_.GetOpponent ().GetMove (opponentMoveIndex_).GetName () 
        + " !");

      battleInterface_.GetBattleInfoDialogBox ().AddText (
        battle_.GetPlayerTeam ().GetName () + " utilise "
        + battle_.GetPlayerTeam ().GetMove (phaseArgs_.index_).GetName () 
        + " !");

      battleInterface_.GetBattleInfoDialogBox ().OnTextChanged.AddHandler (
        "ACTION_TEXT_SKIPPED",
        [&] (const yap::BaseWidget& sender, const yap::EmptyEventArgs& args)
      {
        if (textSkippedNumber_ == 0)
          opponentAttack_ = true;
        else if (textSkippedNumber_ == 1)
        {
          playerAttack_ = true;
          nextPhase_ = true;
        }

        textSkippedNumber_++;
      });
    }
  }

  void ActionPhase::HandleUpdate (const yap::Time& dt)
  {
    yap::ActionPhase::HandleUpdate (dt);
  }

  void ActionPhase::HandleEnd ()
  {
    yap::ActionPhase::HandleEnd ();

    battleInterface_.GetBattleInfoDialogBox ().OnTextChanged.RemoveHandler (
      "ACTION_TEXT_SKIPPED");
  }

  void ActionPhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool ActionPhase::IsVisible () const
  {
    return isVisible_;
  }

  void ActionPhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void ActionPhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void ActionPhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void ActionPhase::HandleShow (bool isVisible)
  {
  }

  void ActionPhase::HandleChangeColor (const sf::Color& color)
  {
  }
}