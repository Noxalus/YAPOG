#ifndef YAPOG_PHASEARGS_HPP
# define YAPOG_PHASEARGS_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class BattlePhase;

  class YAPOG_LIB PhaseArgs
  {
  public:
    PhaseArgs ();

    virtual void Accept (BattlePhase& visitor) = 0;
  };
} // namespace yap

#endif // YAPOG_PHASEARGS_HPP
