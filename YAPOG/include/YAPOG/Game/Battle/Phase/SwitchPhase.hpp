#ifndef YAPOG_SWITCHPHASE_HPP
# define YAPOG_SWITCHPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"

namespace yap
{
  class YAPOG_LIB SwitchPhase : public BattlePhase
  {
  public:
    SwitchPhase (Battle& battle);

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart ();
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_SWITCHPHASE_HPP
