#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/Pokemon/PokemonMoveSet.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/Game/Pokemon/Pokemon.hpp"

namespace yap
{
  const UInt8 PokemonMoveSet::DEFAULT_MOVE_NUMBER = 0;

  PokemonMoveSet::PokemonMoveSet ()
    : moveSet_ (Pokemon::MAX_POKEMON_MOVE_NUMBER, nullptr)
    , moveNumber_ (DEFAULT_MOVE_NUMBER)
  {
  }

  PokemonMoveSet::PokemonMoveSet (const PokemonMoveSet& copy)
    : moveSet_ (Pokemon::MAX_POKEMON_MOVE_NUMBER, nullptr)
    , moveNumber_ (copy.moveNumber_)
  {
    for (int i = 0; i < Pokemon::MAX_POKEMON_MOVE_NUMBER; i++)
    {
      if (copy.moveSet_[i] != nullptr)
        moveSet_[i] = new PokemonMove (*copy.moveSet_[i]);
    }
  }

  PokemonMoveSet::~PokemonMoveSet ()
  {
    for (int i = 0; i < Pokemon::MAX_POKEMON_MOVE_NUMBER; i++)
    {
      if (moveSet_[i] != nullptr)
        delete moveSet_[i];
    }
  }

  // Getters
  const collection::Array<PokemonMove*>& 
    PokemonMoveSet::GetMoves () const
  { return moveSet_; }

  const UInt8 PokemonMoveSet::GetMoveNumber () const
  { return moveNumber_; }

  // Return a pointeur to check if there is a move or not
  const PokemonMove* PokemonMoveSet::GetMove (const UInt8& index) const
  { return moveSet_[index]; }

  void PokemonMoveSet::AddMove (PokemonMove* move, const UInt8& index)
  {
    if (index >= moveSet_.Count ())
    {
      throw yap::Exception (
        "Impossible to add this move, out of bound.");
    }

    if (moveSet_[index] != nullptr)
      ReplaceMove (move, index);
    else
    {
      moveSet_[index] = move;

      moveNumber_++;
    }
  }

  bool PokemonMoveSet::AddMove (const ID& moveID)
  {
    for (int i = 0; i < 4; i++)
    {
      if (moveSet_[i] == nullptr)
      {
        moveSet_[i] = new PokemonMove (moveID);
        return true;
      }
    }

    return false;
  }

  void PokemonMoveSet::ReplaceMove (const ID& moveID, UInt8 index)
  {
    if (moveSet_[index] != nullptr)
      delete moveSet_[index];

    moveSet_[index] = new PokemonMove (moveID);
  }

  void PokemonMoveSet::ReplaceMove (PokemonMove* move, UInt8 index)
  {
    if (moveSet_[index] != nullptr)
      delete moveSet_[index];

    moveSet_[index] = move;
  }

}