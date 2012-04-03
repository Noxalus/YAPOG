#include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  Vector2 Vector2FromVector2u (const sf::Vector2u& vector2u)
  {
    return Vector2 (
      static_cast<float> (vector2u.x),
      static_cast<float> (vector2u.y));
  }
} // namespace yap
