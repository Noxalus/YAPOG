#include "YAPOG/Graphics/Game/World/Map/DrawableWorldObjectOrderComparer.hpp"

namespace yap
{
  DrawableWorldObjectOrderComparer::DrawableWorldObjectOrderComparer ()
    : LessComparator<IDrawableWorldObject> ()
  {
  }

  DrawableWorldObjectOrderComparer::~DrawableWorldObjectOrderComparer ()
  {
  }

  int DrawableWorldObjectOrderComparer::HandleCompare (
    const IDrawableWorldObject& left,
    const IDrawableWorldObject& right) const
  {
    return left.CompareOrder (right);
  }
} // namespace yap
