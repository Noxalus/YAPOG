#ifndef YAPOG_DRAWABLEWORLDOBJECTORDERCOMPARATOR_HPP
# define YAPOG_DRAWABLEWORLDOBJECTORDERCOMPARATOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/LessComparator.hpp"

namespace yap
{
  struct IDrawableWorldObject;

  class DrawableWorldObjectOrderComparator
    : LessComparator<IDrawableWorldObject>
  {
      DISALLOW_COPY(DrawableWorldObjectOrderComparator);

    public:

      DrawableWorldObjectOrderComparator ();
      virtual ~DrawableWorldObjectOrderComparator ();

    protected:

      virtual int HandleCompare (
        const IDrawableWorldObject& left,
        const IDrawableWorldObject& right) const;
  };
} // namespace yap

#endif // YAPOG_DRAWABLEWORLDOBJECTORDERCOMPARATOR_HPP
