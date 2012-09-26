#include "YAPOG/Game/Battle/Phase/EndTurnPhase.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"
#include "YAPOG/Game/Battle/Battle.hpp"

namespace yap
{
  EndTurnPhase::EndTurnPhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::EndTurn)
    , addExperience_ (false)
    , experienceAmount_ (0)
    , textSkipped_ (false)
  {
  }

  void EndTurnPhase::HandleStart (const PhaseArgs& args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN END TURN PHASE !" << std::endl;

    addExperience_ = false;
    experienceAmount_ = 0;
    textSkipped_ = false;

    // We heal our invicible Pokemon !!
    if (battle_.GetPlayerTeam ().GetCurrentHP () == 0)
      battle_.GetPlayerTeam ().TakeDamage (
      battle_.GetPlayerTeam ().GetMaxHP ());

    // Add experience
    if (battle_.GetOpponent ().GetCurrentHP () == 0)
    {
      addExperience_ = true;

      /// @todo Compute experience amount
      experienceAmount_ = 4242;

      battle_.GetPlayerTeam ().AddExperience (experienceAmount_);
    }
  }

  void EndTurnPhase::HandleUpdate (const Time& dt)
  {
    if (!addExperience_)
      BattlePhase::SwitchPhase (BattlePhaseState::Selection);
    else
    {
      if (textSkipped_)
      {
        BattlePhase::SwitchPhase (BattlePhaseState::EndBattle);
      }
    }
  }

  void EndTurnPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout 
      << "END END TURN PHASE !" << std::endl
      << "---------------------" << std::endl;
  }
}