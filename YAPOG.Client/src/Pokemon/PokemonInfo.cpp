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

} // namespace ycl