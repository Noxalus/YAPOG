#ifndef YAPOG_POKEMONFIGHTER_HPP
# define YAPOG_POKEMONFIGHTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/IBattleEntity.hpp"
# include "YAPOG/Game/Pokemon/Pokemon.hpp"
# include "YAPOG/Game/Pokemon/PokemonStat.hpp"

namespace yap
{
  class YAPOG_LIB PokemonFighter : public virtual IBattleEntity
  {
  public:
    PokemonFighter (Pokemon* originalPokemon);

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
    PokemonStat stats_;

  private:
    Pokemon* originalPokemon_;

    /// @name Private setters.
    /// @{
    void SetCurrentHP (int value);
    /// @}

  };
} // namespace yap

#endif // YAPOG_POKEMONFIGHTER_HPP
