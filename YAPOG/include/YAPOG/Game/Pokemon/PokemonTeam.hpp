#ifndef YAPOG_POKEMONTEAM_HPP
# define YAPOG_POKEMONTEAM_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/Pokemon.hpp"

namespace yap
{
  class YAPOG_LIB PokemonTeam
  {
    DISALLOW_COPY (PokemonTeam);

    public:
      PokemonTeam ();

      Pokemon* GetPokemon (int index);
      bool AddPokemon (Pokemon* pokemon);

      /// Debug
      void PrintTeam ();
  private:
    Pokemon* pokemonTeam_[];

    static const int MAX_POKEMON_TEAM_NUMBER;
  };
} // namespace yap

#endif // YAPOG_POKEMONTEAM_HPP
