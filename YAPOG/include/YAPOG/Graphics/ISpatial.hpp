#ifndef YAPOG_ISPATIAL_HPP
# define YAPOG_ISPATIAL_HPP

# include <SFML/Graphics/Rect.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  struct YAPOG_LIB ISpatial
  {
      virtual ~ISpatial () {}

      virtual const Vector2& GetPosition () const = 0;
      virtual const Vector2& GetSize () const = 0;

      virtual const Vector2& GetTopLeft () const = 0;
      virtual const Vector2& GetBottomRight () const = 0;
      virtual const Vector2& GetCenter () const = 0;

      virtual const sf::FloatRect& GetRectangle () const = 0;

      virtual void Move (const Vector2& offset) = 0;
      virtual void Scale (const Vector2& factor) = 0;
  };
} // namespace yap

#endif // YAPOG_ISPATIAL_HPP
