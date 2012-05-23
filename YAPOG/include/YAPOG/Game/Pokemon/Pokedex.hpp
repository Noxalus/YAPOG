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

    void SetPokemonSeenInfoList (const collection::Map<ID, Pokedex*>& pokSeen);
    void SetPokemonCaughtInfoList (const collection::Map<ID, Pokedex*>& pokCaught);
    void SetPokemonList (const collection::Array<Pokedex*>& pokList);
    void Init ();

  private:
    collection::Map<ID, Pokedex*> pokSeen_;
    collection::Map<ID, Pokedex*> pokCaught_;
    collection::Array<Pokedex*> pokList_;
  };
} // namespace yap

#endif // YAPOG_POKEDEX_HPP
