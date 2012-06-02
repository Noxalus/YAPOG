#ifndef YAPOG_MAPELEMENT_HPP
# define YAPOG_MAPELEMENT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/StaticWorldObject.hpp"

namespace yap
{
  /// @brief A static map element that is just figurative.
  class YAPOG_LIB MapElement : public StaticWorldObject
  {
      DISALLOW_ASSIGN(MapElement);

    public:

      explicit MapElement (const ID& id);
      virtual ~MapElement ();

      virtual void Accept (IStaticWorldObjectVisitor& visitor);
      virtual void Accept (IStaticWorldObjectConstVisitor& visitor) const;

      /// @name ICloneable members.
      /// @{
      virtual MapElement* Clone () const;
      /// @}

    protected:

      MapElement (const MapElement& copy);
  };
} // namespace yap

#endif // YAPOG_MAPELEMENT_HPP
