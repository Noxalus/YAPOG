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

  DrawableWorldObjectOrderComparator::DrawableWorldObjectOrderComparator (
    const DrawableWorldObjectOrderComparator& copy)
    : LessComparator<IDrawableWorldObject*> (copy)
  {
  }

  DrawableWorldObjectOrderComparator&
  DrawableWorldObjectOrderComparator::operator= (
    const DrawableWorldObjectOrderComparator& copy)
  {
    if (this == &copy)
      return *this;

    LessComparator<IDrawableWorldObject*>::operator= (copy);

    return *this;
  }

  int DrawableWorldObjectOrderComparator::HandleCompare (
    IDrawableWorldObject* const& left,
    IDrawableWorldObject* const& right) const
  {
    return left->CompareOrder (*right);
  }
} // namespace yap
