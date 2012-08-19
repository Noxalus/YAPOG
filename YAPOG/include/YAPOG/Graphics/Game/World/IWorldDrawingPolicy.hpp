#ifndef YAPOG_IWORLDDRAWINGPOLICY_HPP
# define YAPOG_IWORLDDRAWINGPOLICY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  struct ISpatial3;

  /// @brief Describes actions to perform when drawing game world.
  struct IWorldDrawingPolicy
  {
      virtual ~IWorldDrawingPolicy () { }

      /// @todo Rename into ToWorldPosition...
      virtual Vector2 ToScreenPosition (
        const Vector3& worldPosition) const = 0;

      virtual Vector2 ToScreenOffset (
        const Vector3& worldOffset) const = 0;

      virtual float GetComparisonPoint (
        const ISpatial3& spatial) const = 0;
  };
} // namespace yap

#endif // YAPOG_IWORLDDRAWINGPOLICY_HPP
