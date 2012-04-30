#ifndef YAPOG_IDRAWABLEWORLDOBJECT_HPP
# define YAPOG_IDRAWABLEWORLDOBJECT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"

namespace yap
{
  struct IDrawableWorldObject : public IDrawable
  {
      virtual ~IDrawableWorldObject () {}

      virtual int CompareOrder (const IDrawableWorldObject& other) const = 0;
  };
} // namespace yap

#endif // YAPOG_IDRAWABLEWORLDOBJECT_HPP
