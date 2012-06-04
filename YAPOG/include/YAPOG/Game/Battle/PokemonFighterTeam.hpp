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
    virtual Event<
      const IBattleEntity&, 
      const ChangeEventArgs<const HitPoint&>&>& 
      OnHPChangedEvent ();
    /// @}

    virtual PokemonFighter* GetPokemon (int index) const;
    virtual const collection::Array<PokemonFighter*>& GetTeam () const;
    virtual bool AddPokemon (PokemonFighter* pokemon);

    /// Debug
    void PrintTeam ();

    /// @name IUpdateable members.
    /// @{
    virtual void Update (const Time& dt);
    /// @}

  protected:
    virtual void HandleUpdate (const Time& dt);
    int currentFighterIndex_;

  private:
    PokemonFighter* GetCurrentFighter () const;
    collection::Array<PokemonFighter*> fighters_;
  };
} // namespace yap

#endif // YAPOG_POKEMONFIGHTERTEAM_HPP
