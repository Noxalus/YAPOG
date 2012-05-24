#ifndef YAPOG_CLIENT_POKEMONFIGHTER_HPP
# define YAPOG_CLIENT_POKEMONFIGHTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/PokemonFighter.hpp"

namespace ycl
{
  class Pokemon;

  class PokemonFighter : public yap::PokemonFighter
  {
    DISALLOW_COPY (PokemonFighter);
  public:
    PokemonFighter (Pokemon* originalPokemon);
    virtual ~PokemonFighter ();
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONFIGHTER_HPP
