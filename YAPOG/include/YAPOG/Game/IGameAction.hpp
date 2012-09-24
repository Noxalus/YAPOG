#ifndef YAPOG_IGAMEACTION_HPP
# define YAPOG_IGAMEACTION_HPP

# include "YAPOG/Game/Factory/ICloneable.hpp"

namespace yap
{
  struct IGameAction : public ICloneable
  {
      virtual ~IGameAction () { }

      virtual bool Execute () = 0;

      /// @name ICloneable members.
      /// @{
      virtual IGameAction* Clone () const { return nullptr; }
      /// @}
  };
} // namespace yap

#endif // YAPOG_IGAMEACTION_HPP
