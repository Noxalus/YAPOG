#ifndef YAPOG_SPATIALINFO_HPP
# define YAPOG_SPATIALINFO_HPP

# include <SFML/Graphics/Rect.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class YAPOG_LIB SpatialInfo
  {
    public:

      DISALLOW_COPY(SpatialInfo);

      SpatialInfo () = default;
      SpatialInfo (const Vector2& position, const Vector2& size);

      const Vector2& GetPosition () const;
      const Vector2& GetSize () const;

      const Vector2& GetTopLeft () const;
      const Vector2& GetBottomRight () const;
      const Vector2& GetCenter () const;

      const sf::FloatRect& GetRectangle () const;

      void SetPosition (const Vector2& position);
      void SetSize (const Vector2& size);

    private:

      void Init (const Vector2& position, const Vector2& size);
      void Update ();

      Vector2 position_;
      Vector2 size_;

      Vector2 center_;
      Vector2 topLeft_;
      Vector2 bottomRight_;

      sf::FloatRect rectangle_;
  };
} // namespace yap

#endif // YAPOG_SPATIALINFO_HPP
