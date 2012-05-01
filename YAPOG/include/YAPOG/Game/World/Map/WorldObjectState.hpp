#ifndef YAPOG_WORLDOBJECTSTATE_HPP
# define YAPOG_WORLDOBJECTSTATE_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class YAPOG_LIB WorldObjectState
  {
    public:

      WorldObjectState ();

      WorldObjectState (const WorldObjectState& copy);
      WorldObjectState& operator= (const WorldObjectState& copy);

      bool operator< (const WorldObjectState& right) const;
  };
} // namespace yap

#endif // YAPOG_WORLDOBJECTSTATE_HPP
