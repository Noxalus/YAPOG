#ifndef YAPOG_ENDTRAINERBATTLEPHASE_HPP
# define YAPOG_ENDTRAINERBATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/EndBattlePhase.hpp"

namespace yap
{
  class PhaseArgs;

  class YAPOG_LIB EndTrainerBattlePhase : public EndBattlePhase
  {
  public:
    EndTrainerBattlePhase (Battle& battle);

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (PhaseArgs* args);
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_ENDTRAINERBATTLEPHASE_HPP