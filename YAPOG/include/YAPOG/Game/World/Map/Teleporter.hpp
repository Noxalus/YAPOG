#ifndef YAPOG_TELEPORTER_HPP
# define YAPOG_TELEPORTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class Teleporter : public DynamicWorldObject
  {
      DISALLOW_ASSIGN(Teleporter);

    public:

      virtual ~Teleporter ();

      virtual void Accept (IDynamicWorldObjectVisitor& visitor);
      virtual void Accept (IDynamicWorldObjectConstVisitor& visitor) const;

      void SetMapWorldID (const ID& mapWorldID);
      void SetMapPoint (const Vector2& mapPoint);

      void SetArea (const FloatRect& area);

    protected:

      explicit Teleporter (const ID& id);

      Teleporter (const Teleporter& copy);

    private:

      ID mapWorldID_;
      Vector2 mapPoint_;
  };
} // namespace yap

#endif // YAPOG_TELEPORTER_HPP
