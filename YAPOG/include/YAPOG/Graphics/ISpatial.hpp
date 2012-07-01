#ifndef YAPOG_ISPATIAL_HPP
# define YAPOG_ISPATIAL_HPP

# include <SFML/Graphics/Rect.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  /// @brief Represents objects that evolve in the plan.
  struct ISpatial
  {
      virtual ~ISpatial () { }

      /// @brief Gets the coordinates in pixels
      /// of the origin of this ISpatial from the global origin.
      /// @return The coordinates in pixels
      /// of the origin of this ISpatial from the global origin.
      virtual const Vector2& GetPosition () const = 0;
      /// @brief Gets the size in pixels of this ISpatial.
      /// @return The size in pixels of this ISpatial.
      virtual const Vector2& GetSize () const = 0;

      virtual const Vector2& GetTopLeft () const = 0;
      virtual const Vector2& GetBottomRight () const = 0;
      virtual const Vector2& GetCenter () const = 0;

      virtual const sf::FloatRect& GetRectangle () const = 0;

      virtual void Move (const Vector2& offset) = 0;
      virtual void Scale (const Vector2& factor) = 0;

      virtual void SetPosition (const Vector2& position) = 0;
      virtual void SetSize (const Vector2& size) = 0;
  };
} // namespace yap

#endif // YAPOG_ISPATIAL_HPP
