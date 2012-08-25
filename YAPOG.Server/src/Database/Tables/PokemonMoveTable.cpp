#include "YAPOG/Game/Pokemon/PokemonMove.hpp"

#include "Database/Tables/PokemonMoveTable.hpp"
#include "Pokemon/Pokemon.hpp"

namespace yse
{
  const yap::ID PokemonMoveTable::DEFAULT_STATIC_ID (0);
  const yap::UInt16 PokemonMoveTable::DEFAULT_PP = 0;
  const yap::UInt16 PokemonMoveTable::DEFAULT_MAX_PP = 0;

  PokemonMoveTable::PokemonMoveTable ()
    : pokemonID_ (1)
  {
  }

  void PokemonMoveTable::LoadFromPokemon (
    const Pokemon& pokemon,
    const yap::ID& index)
  {
    pokemonID_ = pokemon.GetUniqueID ();
    index_ = index;

    yap::collection::Array<yap::PokemonMove*> moves = 
      pokemon.GetMoveSet ().GetMoves ();

    if (moves[index.GetValue ()] == nullptr)
    {
      staticID_ = DEFAULT_STATIC_ID;
      pp_ = DEFAULT_PP;
      maxPP_ = DEFAULT_MAX_PP;
    }
    else
    {
      staticID_ = moves[index.GetValue ()]->GetStaticID ();
      pp_ = moves[index.GetValue ()]->GetCurrentPP ();
      maxPP_ = moves[index.GetValue ()]->GetMaxPP ();
    }
  }

} // namespace yse