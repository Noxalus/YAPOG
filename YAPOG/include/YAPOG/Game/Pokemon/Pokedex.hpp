#ifndef YAPOG_POKEDEX_HPP
# define YAPOG_POKEDEX_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yap
{
  class YAPOG_LIB Pokedex
  {
  public:
    Pokedex ();
    ~Pokedex ();

    void SetPokemonSeenInfoList (const collection::Map<ID, PokemonInfo*>& pokSeen);
    void SetPokemonCaughtInfoList (const collection::Map<ID, PokemonInfo*>& pokCaught);
    void SetPokemonList (const collection::Array<PokemonInfo*>& pokList);

    void AddPokemon (PokemonInfo* pok);
    void AddPokemonSeen (PokemonInfo* pokSeen);
    void AddPokemonCaught (PokemonInfo* pokCaught);
    void Init ();

  private:
    collection::Map<ID, PokemonInfo*> pokSeen_;
    collection::Map<ID, PokemonInfo*> pokCaught_;
    collection::Array<PokemonInfo*> pokList_;
  };
} // namespace yap

#endif // YAPOG_POKEDEX_HPP
