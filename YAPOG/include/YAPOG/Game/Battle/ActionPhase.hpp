#ifndef YAPOG_ACTIONPHASE_HPP
# define YAPOG_ACTIONPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/BattlePhase.hpp"

namespace yap
{
  class YAPOG_LIB ActionPhase : public BattlePhase
  {
  public:
    ActionPhase ();

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart ();
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_ACTIONPHASE_HPP
