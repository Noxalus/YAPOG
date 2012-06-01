#ifndef YAPOG_IDRAWABLE_HPP
# define YAPOG_IDRAWABLE_HPP

# include <SFML/Graphics/Color.hpp>

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct IDrawingContext;

  struct YAPOG_LIB IDrawable
  {
      virtual ~IDrawable () {}

      virtual void Draw (IDrawingContext& context) = 0;

      virtual bool IsVisible () const = 0;
      virtual void Show (bool isVisible) = 0;

      virtual void ChangeColor (const sf::Color& color) = 0;
  };
} // namespace yap

#endif // YAPOG_IDRAWABLE_HPP
