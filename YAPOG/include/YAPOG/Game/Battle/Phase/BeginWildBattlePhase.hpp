#ifndef YAPOG_BEGINWILDBATTLEPHASE_HPP
# define YAPOG_BEGINWILDBATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/BeginBattlePhase.hpp"

namespace yap
{
  class PhaseArgs;

  class YAPOG_LIB BeginWildBattlePhase : public BeginBattlePhase
  {
    DISALLOW_COPY(BeginWildBattlePhase);
  protected:
    BeginWildBattlePhase (Battle& battle);
    ~BeginWildBattlePhase ();

  public:
    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (PhaseArgs* args);
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_BEGINWILDBATTLEPHASE_HPP
