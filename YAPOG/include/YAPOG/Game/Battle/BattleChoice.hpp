#ifndef YAPOG_BATTLECHOICE_HPP
# define YAPOG_BATTLECHOICE_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  enum class BattleChoice : int
  {
    Move,
    Item,
    Switch,
    Run,
    None
  };
} // namespace yap

#endif // YAPOG_BATTLECHOICE_HPP
