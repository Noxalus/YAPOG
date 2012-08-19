#ifndef YAPOG_CAMERA_HPP
# define YAPOG_CAMERA_HPP

# include <SFML/Graphics/Rect.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/ICamera.hpp"
# include "YAPOG/Graphics/SpatialInfo.hpp"

namespace yap
{
  /// @brief Common implementation of an ICamera.
  class YAPOG_LIB Camera : public ICamera
  {
      DISALLOW_COPY(Camera);

    public:

      Camera (const Vector2& position, const Vector2& size);
      virtual ~Camera ();

      /// @name ISpatial members.
      /// @{
      virtual const Vector2& GetPosition () const;
      virtual const Vector2& GetSize () const;

      virtual const Vector2& GetTopLeft () const;
      virtual const Vector2& GetBottomRight () const;
      virtual const Vector2& GetCenter () const;

      virtual const sf::FloatRect& GetRectangle () const;

      virtual void Move (const Vector2& offset);
      virtual void Scale (const Vector2& factor);

      virtual void SetPosition (const Vector2& position);
      virtual void SetSize (const Vector2& size);
      /// @}

      /// @name ICamera members.
      /// @{
      virtual bool IsInView (const Vector2& point) const;
      virtual bool IsInView (const Vector2& point, const Vector2& size) const;

      virtual Vector2 ToLocal (const Vector2& globalPoint) const;
      virtual Vector2 ToGlobal (const Vector2& localPoint) const;

      virtual const sf::View& GetInnerView () const;
      /// @}

    protected:

      virtual bool HandleIsInView (
        const Vector2& point,
        const Vector2& size) const;

      virtual Vector2 HandleToLocal (const Vector2& globalPoint) const;
      virtual Vector2 HandleToGlobal (const Vector2& localPoint) const;

    private:

      SpatialInfo spatialInfo_;
      sf::View view_;
  };
} // namespace yap

#endif // YAPOG_CAMERA_HPP
