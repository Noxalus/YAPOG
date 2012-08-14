#ifndef YAPOG_WORLDDRAWINGPOLICY_HPP
# define YAPOG_WORLDDRAWINGPOLICY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IWorldDrawingPolicy.hpp"

namespace yap
{
  class WorldDrawingPolicy : IWorldDrawingPolicy
  {
      DISALLOW_COPY(WorldDrawingPolicy);

    public:

      virtual ~WorldDrawingPolicy ();

      /// @IWorldDrawingPolicy members
      /// @{
      virtual Vector2 GetDrawingPosition (const Vector3& worldPosition) const;
      /// }

    protected:

      WorldDrawingPolicy ();

      virtual Vector2 HandleGetDrawingPosition (
        const Vector3& worldPosition) const = 0;
  };
} // namespace yap

#endif // YAPOG_WORLDDRAWINGPOLICY_HPP
