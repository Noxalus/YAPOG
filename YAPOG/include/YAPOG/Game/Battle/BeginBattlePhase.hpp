#ifndef YAPOG_BEGINBATTLEPHASE_HPP
# define YAPOG_BEGINBATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/BattlePhase.hpp"

namespace yap
{
  class YAPOG_LIB BeginBattlePhase : public BattlePhase
  {
  public:
    BeginBattlePhase ();

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart ();
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_BEGINBATTLEPHASE_HPP
