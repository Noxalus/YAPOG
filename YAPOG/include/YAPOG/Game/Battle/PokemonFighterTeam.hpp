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
    virtual const ID& GetID () const;
    virtual const String& GetName () const;
    virtual const UInt16& GetLevel () const;
    virtual const Gender& GetGender () const;
    virtual const UInt16& GetCurrentHP () const;
    virtual const UInt16& GetMaxHP () const;
    virtual float GetHPPercentage () const;
    virtual const collection::Array<PokemonSkill*>& GetMoves () const;
    virtual const PokemonSkill& GetMove (int index) const;
    virtual const PokemonStat& GetStats () const;

    virtual void TakeDamage (int value);

    virtual Event<
      const IBattleEntity&, 
      const ChangeEventArgs<const HitPoint&>&>& 
      OnHPChangedEvent ();
    /// @}

    /// @name IUpdateable members.
    /// @{
    virtual void Update (const Time& dt);
    /// @}

  protected:
    virtual void HandleUpdate (const Time& dt);

    virtual PokemonFighter& GetCurrentFighter () = 0;
    virtual const PokemonFighter& GetCurrentFighter () const = 0;
    int currentFighterIndex_;

  };
} // namespace yap

#endif // YAPOG_POKEMONFIGHTERTEAM_HPP
