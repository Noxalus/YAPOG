#ifndef YAPOG_IBATTLEENTITYE_HPP
# define YAPOG_IBATTLEENTITYE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  class HitPoint;

  struct YAPOG_LIB IBattleEntity : public IUpdateable
  {
    virtual ~IBattleEntity () {}

    /// @name Getters.
    /// @{
    virtual const String& GetName () const = 0;
    virtual const UInt16& GetLevel () const = 0;
    virtual const Gender& GetGender () const = 0;
    virtual const UInt16& GetCurrentHP () const = 0;
    virtual const UInt16& GetMaxHP () const = 0;
    virtual float GetHPPercentage () const = 0;
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