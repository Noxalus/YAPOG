#ifndef YAPOG_BATTLE_HPP
# define YAPOG_BATTLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/Battle/IBattleEntity.hpp"
# include "YAPOG/Game/Battle/BattlePhaseManager.hpp"

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
    virtual IBattleEntity& GetPlayerTeam ();
    virtual IBattleEntity& GetOpponent ();

    /// Setters
    void SetPlayerTeam (PokemonFighterTeam* playerTeam);
    void SetOpponent (PokemonFighterTeam* opponent);
    void SetOpponent (PokemonFighter* opponent);

  protected:
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleInit ();
    void AddPhase (
      const BattlePhaseState& battlePhaseState, 
      BattlePhase* battlePhase);

  private:
    IBattleEntity* playerTeam_;
    IBattleEntity* opponent_;
    int turnCount_;
    BattlePhaseManager battlePhaseManager_;
  };
} // namespace yap

#endif // YAPOG_BATTLE_HPP
