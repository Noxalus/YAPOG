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

      const ID& GetMapWorldID () const;
      const Vector2& GetMapPoint () const;
      const FloatRect& GetArea () const;

    protected:

      explicit Teleporter (const ID& id);

      Teleporter (const Teleporter& copy);

      void SetMapWorldID (const ID& mapWorldID);
      void SetMapPoint (const Vector2& mapPoint);

      void SetArea (const FloatRect& area);

    private:

      static const int DEFAULT_AREA_Z;
      static const int DEFAULT_AREA_H;

      ID mapWorldID_;
      Vector2 mapPoint_;

      FloatRect area_;
  };
} // namespace yap

#endif // YAPOG_TELEPORTER_HPP
