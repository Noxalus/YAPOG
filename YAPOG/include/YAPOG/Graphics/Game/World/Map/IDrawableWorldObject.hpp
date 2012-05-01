#ifndef YAPOG_IDRAWABLEWORLDOBJECT_HPP
# define YAPOG_IDRAWABLEWORLDOBJECT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"

namespace yap
{
  struct YAPOG_LIB IDrawableWorldObject : public IDrawable
  {
      virtual ~IDrawableWorldObject () {}

      /// @brief Determines if this IDrawableWorldObject must be drawn
      /// before @a other.
      /// @param other IDrawableWorldObject to determine if it must be drawn
      /// before this.
      /// @return A negative number if this IDrawableWorldObject must be drawn
      /// before @a other, else a positive number.
      virtual int CompareOrder (const IDrawableWorldObject& other) const = 0;

      /// @brief Specifies the point from which to make comparison.
      /// @return The point from which to make comparison.
      virtual float GetComparisonPoint () const = 0;
  };
} // namespace yap

#endif // YAPOG_IDRAWABLEWORLDOBJECT_HPP
