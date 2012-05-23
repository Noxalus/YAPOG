#ifndef YAPOG_STATICWORLDOBJECT_HPP
# define YAPOG_STATICWORLDOBJECT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yap
{
  class StaticWorldObject : public WorldObject
                          , public IUpdateable
  {
      DISALLOW_ASSIGN(StaticWorldObject);

    public:

      virtual ~StaticWorldObject ();

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    protected:

      explicit StaticWorldObject (const ID& id);
      StaticWorldObject (const StaticWorldObject& copy);

      virtual void HandleUpdate (const Time& dt);
  };
} // namespace yap

#endif // YAPOG_STATICWORLDOBJECT_HPP
