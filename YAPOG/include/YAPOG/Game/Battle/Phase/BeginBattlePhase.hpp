#ifndef YAPOG_BEGINBATTLEPHASE_HPP
# define YAPOG_BEGINBATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"

namespace yap
{
  class PhaseArgs;

  class YAPOG_LIB BeginBattlePhase : public BattlePhase
  {
    DISALLOW_COPY(BeginBattlePhase);
  protected:
    BeginBattlePhase (Battle& battle);
    ~BeginBattlePhase ();

  public:
    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (const PhaseArgs& args);
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_BEGINBATTLEPHASE_HPP
