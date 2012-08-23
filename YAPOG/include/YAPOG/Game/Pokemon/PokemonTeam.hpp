#ifndef YAPOG_POKEMONTEAM_HPP
# define YAPOG_POKEMONTEAM_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class YAPOG_LIB PokemonTeam
  {
    DISALLOW_COPY (PokemonTeam);

  public:
    PokemonTeam ();

    static const int MAX_POKEMON_TEAM_NUMBER;
  };
} // namespace yap

#endif // YAPOG_POKEMONTEAM_HPP
