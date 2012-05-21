#ifndef YAPOG_BATTLEPHASEMANAGER_HPP
# define YAPOG_BATTLEPHASEMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Game/Battle/BattlePhase.hpp"
# include "YAPOG/Game/Battle/BattlePhaseState.hpp"

namespace yap
{
  class Battle;

  class YAPOG_LIB BattlePhaseManager
  {
  public:
    BattlePhaseManager (Battle& battle);

    void Init ();
    const BattlePhaseState& GetCurrentPhase () const;
    void Update ();

  private:
    Battle& battle_;
    BattlePhaseState currentPhase_;
    collection::Map<BattlePhaseState, BattlePhase*> battlePhases_;

    static const BattlePhaseState DEFAULT_BATTLE_PHASE;
  };
} // namespace yap

#endif // YAPOG_BATTLEPHASEMANAGER_HPP
