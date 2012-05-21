#ifndef YAPOG_BATTLE_HPP
# define YAPOG_BATTLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/IBattleEntity.hpp"
# include "YAPOG/Game/Battle/BattlePhaseManager.hpp"

namespace yap
{
  class YAPOG_LIB Battle
  {
  public:
    Battle (IBattleEntity& playerTeam, IBattleEntity& opponent);

    void Init ();
    void Run ();
    void DisplayMoves ();
    void DisplayTeam ();
    virtual void DisplayBeginMessage () = 0;

  protected:
    IBattleEntity& playerTeam_;
    IBattleEntity& opponent_;
    int turnCount_;
    BattlePhaseManager battlePhaseManager_;
  };
} // namespace yap

#endif // YAPOG_BATTLE_HPP
