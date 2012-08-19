#ifndef YAPOG_WORLDCAMERA_HPP
# define YAPOG_WORLDCAMERA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Camera.hpp"

namespace yap
{
  struct IWorldDrawingPolicy;

  class WorldCamera : public Camera
  {
      DISALLOW_COPY(WorldCamera);

    public:

      WorldCamera (const Vector2& position, const Vector2& size);
      virtual ~WorldCamera ();

      void SetWorldDrawingPolicy (
        const IWorldDrawingPolicy& worldDrawingPolicy);

    protected:

      virtual bool HandleIsInView (
        const Vector2& point,
        const Vector2& size) const;

      virtual Vector2 HandleToLocal (const Vector2& globalPoint) const;
      virtual Vector2 HandleToGlobal (const Vector2& localPoint) const;

    private:

      const IWorldDrawingPolicy* worldDrawingPolicy_;
  };
} // namespace yap

#endif // YAPOG_WORLDCAMERA_HPP
