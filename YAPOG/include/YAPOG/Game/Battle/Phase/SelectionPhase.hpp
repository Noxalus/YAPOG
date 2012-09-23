#ifndef YAPOG_SELECTIONPHASE_HPP
# define YAPOG_SELECTIONPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"

namespace yap
{
  class PhaseArgs;

  class YAPOG_LIB SelectionPhase : public BattlePhase
  {
  public:
    SelectionPhase (Battle& battle);

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (const PhaseArgs& args);
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_SELECTIONPHASE_HPP
