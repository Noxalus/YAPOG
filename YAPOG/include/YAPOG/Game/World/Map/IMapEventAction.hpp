#ifndef YAPOG_IMAPEVENTACTION_HPP
# define YAPOG_IMAPEVENTACTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/ICloneable.hpp"

namespace yap
{
  class MapEventArgs;

  struct IMapEventAction : public ICloneable
  {
      virtual ~IMapEventAction () { }

      virtual bool Execute (MapEventArgs& args) = 0;

      virtual IMapEventAction* Clone () const { return nullptr; }
  };
} // namespace yap

#endif // YAPOG_IMAPEVENTACTION_HPP
