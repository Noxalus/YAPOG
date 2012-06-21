#ifndef YAPOG_BEGINTRAINERBATTLEPHASE_HPP
# define YAPOG_BEGINTRAINERBATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/BeginBattlePhase.hpp"

namespace yap
{
  class PhaseArgs;

  class YAPOG_LIB BeginTrainerBattlePhase : public BeginBattlePhase
  {
    DISALLOW_COPY(BeginTrainerBattlePhase);
  protected:
    BeginTrainerBattlePhase (Battle& battle);
    ~BeginTrainerBattlePhase ();

  public:
    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (PhaseArgs* args);
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_BEGINTRAINERBATTLEPHASE_HPP
