#ifndef YAPOG_POKEMONFIGHTER_HPP
# define YAPOG_POKEMONFIGHTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/Pokemon.hpp"

namespace yap
{
  class YAPOG_LIB PokemonFighter
  {
  public:
    PokemonFighter (Pokemon* originalPokemon);

    const String& GetName () const;
    const UInt16& GetLevel () const;
    const Gender& GetGender () const;
    UInt16 GetCurrentHP () const;
    UInt16 GetMaxHP () const;
    const collection::Array<PokemonSkill*>& GetMoves () const;

    void PrintBattleStats ();
  private:
    Pokemon* originalPokemon_;
  };
} // namespace yap

#endif // YAPOG_POKEMONFIGHTER_HPP
