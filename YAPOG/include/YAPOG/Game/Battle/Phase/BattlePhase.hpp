#ifndef YAPOG_BATTLEPHASE_HPP
# define YAPOG_BATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhaseState.hpp"
# include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  class Battle;
  class ActionPhaseArgs;
  class PhaseArgs;

  class YAPOG_LIB BattlePhase : public IUpdateable
  {
  public:
    BattlePhase (Battle& battle, const BattlePhaseState& battlePhaseState);

    /// Getters
    const BattlePhaseState& GetNext () const;

    void Start (const PhaseArgs& args);
    void End ();
    
    /// @name Getters.
    /// @{
    PhaseArgs GetPhaseArgs ();
    /// @}

    /// @name Setters.
    /// @{
    void SetPreviousPhase (const BattlePhaseState& value);
    /// @}

    /// @name IUpdateable members.
    /// @{
    virtual void Update (const Time& dt);
    /// @}

    void SwitchPhase (BattlePhaseState nextPhase);
    void SwitchPhase (BattlePhaseState nextPhase, const PhaseArgs& args);

  protected:
    virtual void HandleStart (const PhaseArgs& args);
    virtual void HandleEnd ();
    virtual void HandleUpdate (const Time& dt);

    Battle& GetBattle ();

    BattlePhaseState state_;
    BattlePhaseState previousPhase_;
    PhaseArgs phaseArgs_;
    Battle& battle_;

  private:
    BattlePhaseState nextPhase_;
  };
} // namespace yap

#endif // YAPOG_BATTLEPHASE_HPP
