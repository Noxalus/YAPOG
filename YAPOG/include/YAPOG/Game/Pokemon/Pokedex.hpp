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

    void SetPokemonSeenInfoList (const collection::Array<PokemonInfo*>& pokSeen);
    void SetPokemonCaughtInfoList (const collection::Array<PokemonInfo*>& pokCaught);
    void SetPokemonList (const collection::Array<PokemonInfo*>& pokList);

    uint GetMaxIDSeen () const;
    const PokemonInfo& GetPokemonSeen (uint index) const;
    const PokemonInfo* GetPokemonSeenID (uint ID) const;
    PokemonInfo* GetPokemon (uint index) const;
    uint GetPokemonSeenCount () const;
    uint GetPokemonCaughtCount () const;
    uint GetPokemonCount () const;

    void AddPokemon (PokemonInfo* pok);
    void AddPokemonSeen (PokemonInfo* pokSeen);
    void AddPokemonCaught (PokemonInfo* pokCaught);
    void Init ();

  private:
    collection::Array<PokemonInfo*> pokSeen_;
    collection::Array<PokemonInfo*> pokCaught_;
    collection::Array<PokemonInfo*> pokList_;
  };
} // namespace yap

#endif // YAPOG_POKEDEX_HPP
