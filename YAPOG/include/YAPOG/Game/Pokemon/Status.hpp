#ifndef YAPOG_STATUS_HPP
# define YAPOG_STATUS_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  enum class YAPOG_LIB Status
  {
    Normal,
    Poisoned,
    Paralyzed,
    Burned,
    Asleep,
    Frozen,
    Confused,
    Flinch,
    Toxic
  };
} // namespace yap

#endif // YAPOG_STATUS_HPP
