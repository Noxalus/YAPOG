# include "YAPOG/Game/Battle/BattlePhase.hpp"
# include "YAPOG/Game/Battle/Battle.hpp"

namespace yap
{
  BattlePhase::BattlePhase (const BattlePhaseState& battlePhaseState)
    : state_ (battlePhaseState)
  {
  }

  void BattlePhase::Start ()
  {
    HandleStart ();
  }

  void BattlePhase::End ()
  {
    HandleEnd ();
  }

  void BattlePhase::Update (const Time& dt)
  {
    nextPhase_ = state_; 
    HandleUpdate (dt);
  }

  void BattlePhase::HandleStart ()
  {
  }

  void BattlePhase::HandleEnd ()
  {
  }

  void BattlePhase::HandleUpdate (const Time& dt)
  {
  }

  Battle& BattlePhase::GetBattle ()
  {
    return *battle_;
  }

   void BattlePhase::SetBattle (Battle* battle)
   {
     battle_ = battle;
   }

   const BattlePhaseState& BattlePhase::GetNext () const
   {
     return nextPhase_;
   }
}