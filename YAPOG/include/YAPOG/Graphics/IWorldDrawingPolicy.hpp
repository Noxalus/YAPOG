#ifndef YAPOG_IWORLDDRAWINGPOLICY_HPP
# define YAPOG_IWORLDDRAWINGPOLICY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  /// @brief Describes actions to perform when drawing game world.
  struct IWorldDrawingPolicy
  {
      virtual ~IWorldDrawingPolicy () { }

      virtual Vector2 GetDrawingPosition (
        const Vector3& worldPosition) const = 0;
  };
} // namespace yap

#endif // YAPOG_IWORLDDRAWINGPOLICY_HPP
