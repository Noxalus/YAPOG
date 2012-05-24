#ifndef YAPOG_POKEMONFIGHTERTEAM_HPP
# define YAPOG_POKEMONFIGHTERTEAM_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/IBattleEntity.hpp"
# include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
# include "YAPOG/Game/Battle/PokemonFighter.hpp"

namespace yap
{
  class YAPOG_LIB PokemonFighterTeam : public IBattleEntity
  {
  public:
    PokemonFighterTeam ();
    PokemonFighterTeam (const PokemonTeam& pokemonTeam);

    /// @name IBattleEntity members
    /// @{
    virtual const String& GetName () const;
    /// @}

    PokemonFighter* GetPokemon (int index) const;
    const collection::Array<PokemonFighter*>& GetTeam () const;
    bool AddPokemon (PokemonFighter* pokemon);

    /// Debug
    void PrintTeam ();
  private:
    PokemonFighter* GetCurrentFighter () const;

    int currentFighterIndex_;
    collection::Array<PokemonFighter*> fighters_;
  };
} // namespace yap

#endif // YAPOG_POKEMONFIGHTERTEAM_HPP
