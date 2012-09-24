#ifndef YAPOG_ENDTURNPHASE_HPP
# define YAPOG_ENDTURNPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"

namespace yap
{
  class PhaseArgs;

  class YAPOG_LIB EndTurnPhase : public BattlePhase
  {
  public:
    EndTurnPhase (Battle& battle);

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (const PhaseArgs& args);
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}

  protected:
    bool addExperience_;
    uint experienceAmount_;
    bool textSkipped_;
  };
} // namespace yap

#endif // YAPOG_ENDTURNPHASE_HPP
