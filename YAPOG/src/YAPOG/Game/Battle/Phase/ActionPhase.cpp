#include "YAPOG/Game/Battle/Phase/ActionPhase.hpp"
#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/Game/Battle/Battle.hpp"

namespace yap
{
  ActionPhase::ActionPhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::Action)
    , playerIsFirst_ (true)
    , battleCore_ ()
    , opponentMoveIndex_ (0)
    , textSkippedNumber_ (0)
    , playerAttack_ (false)
    , opponentAttack_ (false)
    , nextPhase_ (false)
  {
  }

  void ActionPhase::HandleStart (const PhaseArgs& args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN ACTION !" << std::endl;

    playerIsFirst_ = true;
    opponentMoveIndex_ = RandomHelper::GetNext (0, 
      battle_.GetOpponent ().GetMoveSet ().GetMoveNumber () - 1);

    textSkippedNumber_ = 0;
    playerAttack_ = false;
    opponentAttack_ = false;
    nextPhase_ = false;

    // Determine the first to play
    if (battle_.GetOpponent ().GetSpeed ().GetValue () > 
      battle_.GetPlayerTeam ().GetSpeed ().GetValue ())
    {
      playerIsFirst_ = false;
    }
    else if (battle_.GetOpponent ().GetSpeed ().GetValue () ==
      battle_.GetPlayerTeam ().GetSpeed ().GetValue ())
    {
      playerIsFirst_ = RandomHelper::GetNext (0, 1) == 1 ? true : false;
    }
  }

  void ActionPhase::HandleUpdate (const Time& dt)
  {
    if (playerAttack_)
    {
      if (battle_.GetPlayerTeam ().GetMove (
        phaseArgs_.index_).GetCategory () == 1)
      {
        // Compute damage for opponent
        battle_.GetOpponent ().TakeDamage (battleCore_.ComputeDamage (
          battle_.GetPlayerTeam ().GetMove (phaseArgs_.index_),
          battle_.GetPlayerTeam (),
          battle_.GetOpponent ()));
      }

      playerAttack_ = false;
    }

    if (opponentAttack_ && battle_.GetOpponent ().GetCurrentHP () > 0)
    {
      if (battle_.GetOpponent ().GetMove (
        opponentMoveIndex_).GetCategory () == 1)
      {
        // Compute damage for player
        battle_.GetPlayerTeam ().TakeDamage (battleCore_.ComputeDamage (
          battle_.GetOpponent ().GetMove (opponentMoveIndex_),
          battle_.GetOpponent (),
          battle_.GetPlayerTeam ()));
      }
      opponentAttack_ = false;
    }

    if (!opponentAttack_ && !playerAttack_ && nextPhase_)
      BattlePhase::SwitchPhase (BattlePhaseState::EndTurn);
  }

  void ActionPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END ACTION !" << std::endl;
  }
}