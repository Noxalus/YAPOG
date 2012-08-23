#ifndef YAPOG_SERVER_POKEMONTEAM_HPP
# define YAPOG_SERVER_POKEMONTEAM_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
# include "YAPOG/Collection/Array.hpp"

#include "Pokemon/Pokemon.hpp"

namespace yse
{
  class PokemonTeam : public yap::PokemonTeam
  {
    DISALLOW_COPY (PokemonTeam);

  public:
    PokemonTeam ();
    virtual ~PokemonTeam ();

    virtual Pokemon* GetPokemon (int index) const;
    virtual int GetPokemonCount () const;
    virtual bool AddPokemon (Pokemon* pokemon);

  private:
    yap::collection::Array<Pokemon*> pokemonTeam_;
    yap::uint pokemonNumber_;
  };
} // namespace yse

#endif // YAPOG_SERVER_POKEMONTEAM_HPP

