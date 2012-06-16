#ifndef YAPOG_BEGINTURNPHASE_HPP
# define YAPOG_BEGINTURNPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"

namespace yap
{
  class PhaseArgs;

  class YAPOG_LIB BeginTurnPhase : public BattlePhase
  {
  public:
    BeginTurnPhase (Battle& battle);

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (PhaseArgs* args);
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_BEGINTURNPHASE_HPP
