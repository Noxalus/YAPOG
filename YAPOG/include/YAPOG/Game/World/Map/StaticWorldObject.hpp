#ifndef YAPOG_STATICWORLDOBJECT_HPP
# define YAPOG_STATICWORLDOBJECT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yap
{
  struct IStaticWorldObjectVisitor;
  struct IStaticWorldObjectConstVisitor;

  class YAPOG_LIB StaticWorldObject : public WorldObject
                                    , public IUpdateable
  {
      DISALLOW_ASSIGN(StaticWorldObject);

    public:

      virtual ~StaticWorldObject ();

      virtual void Accept (IStaticWorldObjectVisitor& visitor) = 0;
      virtual void Accept (IStaticWorldObjectConstVisitor& visitor) const = 0;

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
