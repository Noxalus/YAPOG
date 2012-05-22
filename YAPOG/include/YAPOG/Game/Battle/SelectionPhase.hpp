#ifndef YAPOG_SELECTIONPHASE_HPP
# define YAPOG_SELECTIONPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/BattlePhase.hpp"

namespace yap
{
  class YAPOG_LIB SelectionPhase : public BattlePhase
  {
  public:
    SelectionPhase ();

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart ();
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_SELECTIONPHASE_HPP
