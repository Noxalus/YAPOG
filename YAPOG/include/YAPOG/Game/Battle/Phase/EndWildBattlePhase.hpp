#ifndef YAPOG_ENDWILDBATTLEPHASE_HPP
# define YAPOG_ENDWILDBATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/EndBattlePhase.hpp"

namespace yap
{
  class PhaseArgs;

  class YAPOG_LIB EndWildBattlePhase : public EndBattlePhase
  {
  public:
    EndWildBattlePhase (Battle& battle);

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (PhaseArgs* args);
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_ENDWILDBATTLEPHASE_HPP
