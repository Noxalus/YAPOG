#ifndef YAPOG_IDRAWABLE_HPP
# define YAPOG_IDRAWABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/ISpatial.hpp"

namespace yap
{
  struct IDrawingContext;

  struct YAPOG_LIB IDrawable : public ISpatial
  {
      virtual ~IDrawable () {}

      virtual void Draw (IDrawingContext& context) = 0;
  };
} // namespace yap

#endif // YAPOG_IDRAWABLE_HPP
