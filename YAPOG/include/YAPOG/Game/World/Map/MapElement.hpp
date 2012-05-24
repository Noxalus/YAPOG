#ifndef YAPOG_MAPELEMENT_HPP
# define YAPOG_MAPELEMENT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/StaticWorldObject.hpp"

namespace yap
{
  /// @brief A static map element that is just figurative.
  class MapElement : public StaticWorldObject
  {
      DISALLOW_ASSIGN(MapElement);

    public:

      virtual ~MapElement ();

      virtual void Accept (IStaticWorldObjectVisitor& visitor);
      virtual void Accept (IStaticWorldObjectConstVisitor& visitor) const;

    protected:

      explicit MapElement (const ID& id);

      MapElement (const MapElement& copy);
  };
} // namespace yap

#endif // YAPOG_MAPELEMENT_HPP
