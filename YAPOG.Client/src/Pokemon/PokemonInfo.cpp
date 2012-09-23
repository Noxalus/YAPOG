#include "Pokemon/PokemonInfo.hpp"

namespace ycl
{
  PokemonInfo::PokemonInfo ()
    : yap::PokemonInfo ()
  {
  }

  PokemonInfo::PokemonInfo (const yap::ID& id)
    : yap::PokemonInfo (id)
  {
  }

  PokemonInfo::~PokemonInfo ()
  {
  }

  PokemonInfo::PokemonInfo (const PokemonInfo& copy)
    : yap::PokemonInfo (copy)
  {
  }

  PokemonInfo* PokemonInfo::Clone () const
  {
    return new PokemonInfo (*this);
  }
} // namespace ycl
