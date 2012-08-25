#ifndef YAPOG_POKEMONMOVESET_HPP
# define YAPOG_POKEMONMOVESET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Game/Pokemon/PokemonMove.hpp"

namespace yap
{
  class YAPOG_LIB PokemonMoveSet
  {
    DISALLOW_ASSIGN (PokemonMoveSet);
  public:
    PokemonMoveSet ();
    PokemonMoveSet (const PokemonMoveSet& copy);
    ~PokemonMoveSet ();

    /// Getters
    const collection::Array<PokemonMove*>& GetMoves () const;
    const UInt8 GetMoveNumber () const;
    const PokemonMove* GetMove (const UInt8& index) const;

    void AddMove (PokemonMove* move, const UInt8& index);
    bool AddMove (const ID& moveID);

    void ReplaceMove (const ID& moveID, UInt8 index);
    void ReplaceMove (PokemonMove* move, UInt8 index);

  private:
    collection::Array<PokemonMove*> moveSet_;
    UInt8 moveNumber_;

    static const UInt8 DEFAULT_MOVE_NUMBER;
  };

} // namespace yap

#endif // YAPOG_POKEMONMOVESET_HPP
