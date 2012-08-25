#ifndef YAPOG_POKEMONSTATUS_HPP
# define YAPOG_POKEMONSTATUS_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  enum class YAPOG_LIB PokemonStatus
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

#endif // YAPOG_POKEMONSTATUS_HPP
