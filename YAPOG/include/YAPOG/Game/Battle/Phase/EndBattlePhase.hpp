#ifndef YAPOG_ENDBATTLEPHASE_HPP
# define YAPOG_ENDBATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"

namespace yap
{
  class PhaseArgs;

  class YAPOG_LIB EndBattlePhase : public BattlePhase
  {
  public:
    EndBattlePhase (Battle& battle);

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (const PhaseArgs& args);
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_ENDBATTLEPHASE_HPP
