#ifndef YAPOG_IMAPEVENTCONDITION_HPP
# define YAPOG_IMAPEVENTCONDITION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/ICloneable.hpp"

namespace yap
{
  class MapEventArgs;

  struct IMapEventCondition : public ICloneable
  {
      virtual ~IMapEventCondition () { }

      virtual bool IsValid (MapEventArgs& args) const = 0;

      virtual IMapEventCondition* Clone () const { return nullptr; }
  };
} // namespace yap

#endif // YAPOG_IMAPEVENTCONDITION_HPP
