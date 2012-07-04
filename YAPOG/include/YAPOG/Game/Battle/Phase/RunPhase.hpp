#ifndef YAPOG_RUNBATTLEPHASE_HPP
# define YAPOG_RUNBATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"

namespace yap
{
  class PhaseArgs;

  class YAPOG_LIB RunPhase : public BattlePhase
  {
  public:
    RunPhase (Battle& battle);

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (PhaseArgs* args);
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_RUNBATTLEPHASE_HPP
