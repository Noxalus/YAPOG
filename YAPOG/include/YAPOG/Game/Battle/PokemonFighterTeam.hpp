#ifndef YAPOG_POKEMONFIGHTERTEAM_HPP
# define YAPOG_POKEMONFIGHTERTEAM_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/IBattleEntity.hpp"
# include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
# include "YAPOG/Game/Battle/PokemonFighter.hpp"

namespace yap
{
  class YAPOG_LIB PokemonFighterTeam : public virtual IBattleEntity
  {
  public:
    PokemonFighterTeam ();
    PokemonFighterTeam (const PokemonTeam& pokemonTeam);

    /// @name IBattleEntity members
    /// @{
    virtual const String& GetName () const;
    virtual const UInt16& GetLevel () const;
    virtual const Gender& GetGender () const;
    virtual Event<
      const IBattleEntity&, 
      const ChangeEventArgs<const HitPoint&>&>& 
      OnHPChangedEvent ();
    /// @}

    virtual PokemonFighter& GetPokemon (int index) const = 0;

    /// @name IUpdateable members.
    /// @{
    virtual void Update (const Time& dt);
    /// @}

  protected:
    virtual PokemonFighter& GetCurrentFighter () = 0;
    virtual const PokemonFighter& GetCurrentFighter () const = 0;
    virtual void HandleUpdate (const Time& dt);
    int currentFighterIndex_;

  };
} // namespace yap

#endif // YAPOG_POKEMONFIGHTERTEAM_HPP
