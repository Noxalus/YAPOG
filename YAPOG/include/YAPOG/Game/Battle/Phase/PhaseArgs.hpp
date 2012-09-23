#ifndef YAPOG_PHASEARGS_HPP
# define YAPOG_PHASEARGS_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/BattleChoice.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class BattlePhase;

  class YAPOG_LIB PhaseArgs
  {
  public:
    PhaseArgs ();

    BattleChoice choice_; 
    uint index_;
  };
} // namespace yap

#endif // YAPOG_PHASEARGS_HPP
