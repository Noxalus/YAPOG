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
    virtual const PokemonExperience& GetExperience () const;
    virtual UInt16 GetLevel () const;
    virtual Gender GetGender () const;
    virtual UInt16 GetCurrentHP () const;
    virtual UInt16 GetMaxHP () const;
    virtual float GetHPPercentage () const;
    virtual const PokemonMoveSet& GetMoveSet () const;
    virtual const PokemonMove& GetMove (int index) const;
    virtual const PokemonStat& GetStats () const;

    virtual const Attack& GetAttack () const;
    virtual const Defense& GetDefense () const;
    virtual const SpecialAttack& GetSpecialAttack () const;
    virtual const SpecialDefense& GetSpecialDefense () const;
    virtual const Speed& GetSpeed () const;

    /// Specifics to the Original Pokemon
    virtual const TypeInfo& GetType1 () const;
    virtual const TypeInfo& GetType2 () const;
    virtual float GetTypeEffectFactor (const TypeInfo& type) const;

    virtual void AddExperience (int value);
    virtual void TakeDamage (int value);
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
