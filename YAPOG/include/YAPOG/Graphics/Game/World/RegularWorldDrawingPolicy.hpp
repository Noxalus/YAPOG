#ifndef YAPOG_REGULARWORLDDRAWINGPOLICY_HPP
# define YAPOG_REGULARWORLDDRAWINGPOLICY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/World/WorldDrawingPolicy.hpp"

namespace yap
{
  class YAPOG_LIB RegularWorldDrawingPolicy : public WorldDrawingPolicy
  {
      DISALLOW_COPY(RegularWorldDrawingPolicy);

    public:

      RegularWorldDrawingPolicy ();
      virtual ~RegularWorldDrawingPolicy ();

    protected:

      virtual Vector2 HandleToScreenPosition (
        const Vector3& worldPosition) const;

      virtual float HandleGetComparisonPoint (
        const ISpatial3& spatial) const;
  };
} // namespace yap

#endif // YAPOG_REGULARWORLDDRAWINGPOLICY_HPP
