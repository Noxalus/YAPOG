#ifndef YAPOG_DRAWABLEWORLDOBJECTORDERCOMPARATOR_HPP
# define YAPOG_DRAWABLEWORLDOBJECTORDERCOMPARATOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/LessComparator.hpp"

namespace yap
{
  struct IDrawableWorldObject;

  class YAPOG_LIB DrawableWorldObjectOrderComparator
    : public LessComparator<IDrawableWorldObject*>
  {
      DISALLOW_COPY(DrawableWorldObjectOrderComparator);

    public:

      DrawableWorldObjectOrderComparator ();
      virtual ~DrawableWorldObjectOrderComparator ();

    protected:

      virtual int HandleCompare (
        IDrawableWorldObject* const& left,
        IDrawableWorldObject* const& right) const;
  };
} // namespace yap

#endif // YAPOG_DRAWABLEWORLDOBJECTORDERCOMPARATOR_HPP
