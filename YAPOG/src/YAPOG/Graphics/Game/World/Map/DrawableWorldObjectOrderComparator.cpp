#include "YAPOG/Graphics/Game/World/Map/DrawableWorldObjectOrderComparator.hpp"
#include "YAPOG/Graphics/Game/World/Map/IDrawableWorldObject.hpp"

namespace yap
{
  DrawableWorldObjectOrderComparator::DrawableWorldObjectOrderComparator ()
    : LessComparator<IDrawableWorldObject*> ()
  {
  }

  DrawableWorldObjectOrderComparator::~DrawableWorldObjectOrderComparator ()
  {
  }

  int DrawableWorldObjectOrderComparator::HandleCompare (
    IDrawableWorldObject* const& left,
    IDrawableWorldObject* const& right) const
  {
    return left->CompareOrder (*right);
  }
} // namespace yap
