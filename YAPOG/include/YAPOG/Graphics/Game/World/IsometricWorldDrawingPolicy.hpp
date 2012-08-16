#ifndef YAPOG_ISOMETRICWORLDDRAWINGPOLICY_HPP
# define YAPOG_ISOMETRICWORLDDRAWINGPOLICY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/World/WorldDrawingPolicy.hpp"

namespace yap
{
  class YAPOG_LIB IsometricWorldDrawingPolicy : public WorldDrawingPolicy
  {
      DISALLOW_COPY(IsometricWorldDrawingPolicy);

    public:

      IsometricWorldDrawingPolicy ();
      virtual ~IsometricWorldDrawingPolicy ();

    protected:

      virtual Vector2 HandleToScreenPosition (
        const Vector3& worldPosition) const;

      virtual float HandleGetComparisonPoint (
        const ISpatial3& spatial) const;
  };
} // namespace yap

#endif // YAPOG_ISOMETRICWORLDDRAWINGPOLICY_HPP
