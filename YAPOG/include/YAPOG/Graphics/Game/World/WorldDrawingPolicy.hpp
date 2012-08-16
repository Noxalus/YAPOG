#ifndef YAPOG_WORLDDRAWINGPOLICY_HPP
# define YAPOG_WORLDDRAWINGPOLICY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/World/IWorldDrawingPolicy.hpp"

namespace yap
{
  class WorldDrawingPolicy : public IWorldDrawingPolicy
  {
      DISALLOW_COPY(WorldDrawingPolicy);

    public:

      virtual ~WorldDrawingPolicy ();

      /// @IWorldDrawingPolicy members
      /// @{
      virtual Vector2 ToScreenPosition (
        const Vector3& worldPosition) const;

      virtual Vector2 ToScreenOffset (
        const Vector3& worldOffset) const;

      virtual float GetComparisonPoint (
        const ISpatial3& spatial) const;
      /// @}

    protected:

      WorldDrawingPolicy ();

      virtual Vector2 HandleToScreenPosition (
        const Vector3& worldPosition) const = 0;

      virtual float HandleGetComparisonPoint (
        const ISpatial3& spatial) const = 0;
  };
} // namespace yap

#endif // YAPOG_WORLDDRAWINGPOLICY_HPP
