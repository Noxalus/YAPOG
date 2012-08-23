#ifndef YAPOG_CLIENT_POKEMONTEAM_HPP
# define YAPOG_CLIENT_POKEMONTEAM_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
# include "YAPOG/Collection/Array.hpp"

#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  class PokemonTeam : public yap::PokemonTeam
  {
    DISALLOW_COPY (PokemonTeam);

  public:
    PokemonTeam ();
    virtual ~PokemonTeam ();

    Pokemon& GetPokemon (int index) const;
    int GetPokemonCount () const;
    bool AddPokemon (Pokemon* pokemon);

  private:
    yap::collection::Array<Pokemon*> pokemonTeam_;
    yap::UInt8 pokemonCount_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONTEAM_HPP

