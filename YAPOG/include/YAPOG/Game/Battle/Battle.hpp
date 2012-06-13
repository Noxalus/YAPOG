#ifndef YAPOG_BATTLE_HPP
# define YAPOG_BATTLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Game/Battle/IBattleEntity.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhaseManager.hpp"

namespace yap
{
  class PokemonFighter;
  class PokemonFighterTeam;

  class YAPOG_LIB Battle : public  IUpdateable
  {
  public:
    Battle ();

    void Init ();
    void DisplayMoves ();
    void DisplayTeam ();

    /// @name IUpdateable members.
    /// @{
    virtual void Update (const Time& dt);
    /// @}

    /// Getters
    virtual IBattleEntity& GetPlayerTeam () = 0;
    virtual IBattleEntity& GetOpponent () = 0;

  protected:
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleInit ();
    void AddPhase (
      const BattlePhaseState& battlePhaseState,
      BattlePhase* battlePhase);

  private:
    int turnCount_;
    BattlePhaseManager battlePhaseManager_;
  };
} // namespace yap

#endif // YAPOG_BATTLE_HPP
