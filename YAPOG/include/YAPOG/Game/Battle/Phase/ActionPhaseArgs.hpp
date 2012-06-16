#ifndef YAPOG_ACTIONPHASEARGS_HPP
# define YAPOG_ACTIONPHASEARGS_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  class YAPOG_LIB ActionPhaseArgs : public PhaseArgs
  {
  public:
    ActionPhaseArgs ();

    virtual void Accept (BattlePhase& visitor);
  };
} // namespace yap

#endif // YAPOG_ACTIONPHASEARGS_HPP
