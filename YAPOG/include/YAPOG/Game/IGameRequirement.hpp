#ifndef YAPOG_IGAMEREQUIREMENT_HPP
# define YAPOG_IGAMEREQUIREMENT_HPP

# include "YAPOG/Game/Factory/ICloneable.hpp"

namespace yap
{
  struct IGameRequirement : public ICloneable
  {
      virtual ~IGameRequirement () { }

      virtual bool IsFulfilled () = 0;

      /// @name ICloneable members.
      /// @{
      virtual IGameRequirement* Clone () const { return nullptr; }
      /// @}
  };
} // namespace yap

#endif // YAPOG_IGAMEREQUIREMENT_HPP
