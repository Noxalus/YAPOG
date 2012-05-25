#include "Battle/PokemonFighter.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  PokemonFighter::PokemonFighter (Pokemon* originalPokemon)
    : yap::PokemonFighter (originalPokemon)
  {
  }

  PokemonFighter::~PokemonFighter ()
  {
  }

} // namespace yap