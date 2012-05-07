#ifndef YAPOG_WORLDOBJECTSTATE_HPP
# define YAPOG_WORLDOBJECTSTATE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/World/Map/WorldObjectStateFactory.hpp"

namespace yap
{
  class YAPOG_LIB WorldObjectState
  {
    public:

      WorldObjectState ();

      WorldObjectState (const WorldObjectState& copy);
      WorldObjectState (const String& state);
      WorldObjectState& operator= (const WorldObjectState& copy);
      WorldObjectState& operator= (const String& other);

      bool operator< (const WorldObjectState& right) const;

      bool operator== (const WorldObjectState& right) const;
      bool operator!= (const WorldObjectState& right) const;

      bool operator== (const String& right) const;
      bool operator!= (const String& right) const;

      const String& GetName () const;
      const String& GetLogicalName () const;
      bool IsJoinedTo (const String& other) const;

    private:

      WorldObjectStateFactory::WorldObjectStateInfo* info_;
  };
} // namespace yap

#endif // YAPOG_WORLDOBJECTSTATE_HPP
