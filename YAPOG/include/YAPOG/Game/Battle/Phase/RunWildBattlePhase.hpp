#ifndef YAPOG_RUNWILDBATTLEPHASE_HPP
# define YAPOG_RUNWILDBATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/RunPhase.hpp"

namespace yap
{
  class PhaseArgs;

  class YAPOG_LIB RunWildBattlePhase : public RunPhase
  {
  public:
    RunWildBattlePhase (Battle& battle);

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (const PhaseArgs& args);
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_RUNWILDBATTLEPHASE_HPP
