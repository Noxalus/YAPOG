#ifndef YAPOG_ACTIONPHASE_HPP
# define YAPOG_ACTIONPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"

namespace yap
{
  class YAPOG_LIB ActionPhase : public BattlePhase
  {
  public:
    ActionPhase (Battle& battle);

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (const PhaseArgs& args);
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}

  protected:
    bool playerIsFirst_;
  };
} // namespace yap

#endif // YAPOG_ACTIONPHASE_HPP
