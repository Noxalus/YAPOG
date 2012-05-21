# include "YAPOG/Game/Battle/BattlePhase.hpp"
# include "YAPOG/Game/Battle/Battle.hpp"

namespace yap
{
  BattlePhase::BattlePhase ()
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
}