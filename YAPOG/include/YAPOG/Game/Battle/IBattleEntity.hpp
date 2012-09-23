#ifndef YAPOG_IBATTLEENTITYE_HPP
# define YAPOG_IBATTLEENTITYE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/System/Event/Event.hpp"
# include "YAPOG/Game/Pokemon/PokemonMove.hpp"
# include "YAPOG/Game/Pokemon/PokemonStat.hpp"

namespace yap
{
  class HitPoint;

  struct YAPOG_LIB IBattleEntity : public IUpdateable
  {
    virtual ~IBattleEntity () {}

    /// @name Getters.
    /// @{
    virtual const String& GetName () const = 0;
    virtual UInt16 GetLevel () const = 0;
    virtual Gender GetGender () const = 0;
    virtual UInt16 GetCurrentHP () const = 0;
    virtual UInt16 GetMaxHP () const = 0;
    virtual float GetHPPercentage () const = 0;
    virtual const PokemonMoveSet& GetMoveSet () const = 0;
    virtual const PokemonMove& GetMove (int index) const = 0;
    virtual const PokemonStat& GetStats () const = 0;

    virtual const Attack& GetAttack () const = 0;
    virtual const Defense& GetDefense () const = 0;
    virtual const SpecialAttack& GetSpecialAttack () const = 0;
    virtual const SpecialDefense& GetSpecialDefense () const = 0;
    virtual const Speed& GetSpeed () const = 0;

    virtual const TypeInfo& GetType1 () const = 0;
    virtual const TypeInfo& GetType2 () const = 0;
    virtual float GetTypeEffectFactor (const TypeInfo& type) const = 0;
    /// @}

    /// @name Setters.
    /// @{
    virtual void TakeDamage (int value) = 0;
    /// @}

    /// @name Events.
    /// @{
    virtual Event<
      const IBattleEntity&, 
      const ChangeEventArgs<const HitPoint&>&>& 
      OnHPChangedEvent () = 0;
    /// @}
  };
} // namespace yap

#endif // YAPOG_IBATTLEENTITYE_HPP