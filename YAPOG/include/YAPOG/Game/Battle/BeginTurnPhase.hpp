#ifndef YAPOG_BEGINTURNPHASE_HPP
# define YAPOG_BEGINTURNPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/BattlePhase.hpp"

namespace yap
{
  class YAPOG_LIB BeginTurnPhase : public BattlePhase
  {
  public:
    BeginTurnPhase ();

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart ();
    virtual void HandleUpdate (const Time& dt);
    virtual void HandleEnd ();
    /// @}
  };
} // namespace yap

#endif // YAPOG_BEGINTURNPHASE_HPP
