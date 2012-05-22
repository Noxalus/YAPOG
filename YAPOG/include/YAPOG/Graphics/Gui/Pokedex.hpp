#ifndef YAPOG_POKEDEX_HPP
# define YAPOG_POKEDEX_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class YAPOG_LIB Pokedex : public Pokedex
  {
  public:
    Pokedex ();

    void Init ();
    void DisplayMoves ();
    void DisplayTeam ();

    /// @name IUpdateable members.
    /// @{
    virtual void Update (const Time& dt);
    /// @}

  protected:
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleInit ();
    void AddPhase (
      const BattlePhaseState& battlePhaseState, 
      BattlePhase* battlePhase);

  private:
    IBattleEntity& playerTeam_;
    IBattleEntity& opponent_;
    int turnCount_;
    BattlePhaseManager battlePhaseManager_;
  };
} // namespace yap

#endif // YAPOG_POKEDEX_HPP
