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

    const Attack& GetAttack () const;
    const Defense& GetDefense () const;
    const SpecialAttack& GetSpecialAttack () const;
    const SpecialDefense& GetSpecialDefense () const;
    const Speed& GetSpeed () const;

    void PrintBattleStats ();
    void PrintStats ();

    /// @name IBattleEntity members
    /// @{
    virtual const String& GetName () const;
    virtual const UInt16& GetLevel () const;
    virtual const Gender& GetGender () const;
    virtual const UInt16& GetCurrentHP () const;
    virtual const UInt16& GetMaxHP () const;
    virtual float GetHPPercentage () const;
    virtual const collection::Array<PokemonSkill*>& GetMoves () const;
    virtual const PokemonSkill& GetMove (int index) const;

    virtual void TakeDamage (int value);

    virtual Event<
      const IBattleEntity&, 
      const ChangeEventArgs<const HitPoint&>&>& 
      OnHPChangedEvent ();
    /// @}

    /// @brief Specifics to the Original Pokemon
    /// {
    const TypeInfo& GetType1 () const;
    const TypeInfo& GetType2 () const;
    float GetTypeEffectFactor (const TypeInfo& type) const;
    /// }

    /// @name IUpdateable members.
    /// @{
    virtual void Update (const Time& dt);
    /// @}

    Event<
      const IBattleEntity&, 
      const ChangeEventArgs<const HitPoint&>&> OnHPChanged;
  protected:
    virtual void HandleUpdate (const Time& dt);

  private:
    Pokemon* originalPokemon_;
    PokemonStat stats_;

    /// @name Private setters.
    /// @{
    void SetCurrentHP (int value);
    /// @}

  };
} // namespace yap

#endif // YAPOG_POKEMONFIGHTER_HPP
