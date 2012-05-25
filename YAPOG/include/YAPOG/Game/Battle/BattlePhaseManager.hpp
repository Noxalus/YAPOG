#ifndef YAPOG_BATTLEPHASEMANAGER_HPP
# define YAPOG_BATTLEPHASEMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/Battle/BattlePhaseState.hpp"

namespace yap
{
  class Battle;
  class BattlePhase;

  class YAPOG_LIB BattlePhaseManager : public IUpdateable
  {
  public:
    BattlePhaseManager ();

    const BattlePhaseState& GetCurrentPhaseState () const;

    void SetCurrentPhaseState (
      const BattlePhaseState& battlePhaseState);
    void SetBattle (Battle* battle);

    void SwitchPhase (const BattlePhaseState& battlePhaseState);

    void AddPhase (
      const BattlePhaseState& battlePhaseState, 
      BattlePhase* battlephase);

    /// @name IUpdateable members.
    /// @{
    virtual void Update (const Time& dt);
    /// @}

  private:
    Battle* battle_;
    BattlePhaseState currentPhaseState_;
    BattlePhase* currentBattlePhase_;
    collection::Map<BattlePhaseState, BattlePhase*> battlePhases_;

    static const BattlePhaseState DEFAULT_BATTLE_PHASE;
  };
} // namespace yap

#endif // YAPOG_BATTLEPHASEMANAGER_HPP
