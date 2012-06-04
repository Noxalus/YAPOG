#ifndef YAPOG_IBATTLEENTITYE_HPP
# define YAPOG_IBATTLEENTITYE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  class HitPoint;

  struct YAPOG_LIB IBattleEntity : public IUpdateable
  {
    virtual ~IBattleEntity () {}

    virtual const String& GetName () const = 0;
    virtual const UInt16& GetLevel () const = 0;

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