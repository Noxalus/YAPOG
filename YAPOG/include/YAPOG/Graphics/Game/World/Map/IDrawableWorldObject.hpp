#ifndef YAPOG_IDRAWABLEWORLDOBJECT_HPP
# define YAPOG_IDRAWABLEWORLDOBJECT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"

namespace yap
{
  struct IWorldDrawingPolicy;

  struct IDrawableWorldObject : public IDrawable
  {
      virtual ~IDrawableWorldObject () { }

      /// @brief Specifies the point from which to make comparison.
      /// @return The point from which to make comparison.
      virtual float GetComparisonPoint () const = 0;

      /// @brief Specifies the layer depth whose this
      /// IDrawableWorldObject belongs to.
      /// The layer depth is a prioritary factor for drawing order.
      /// @return Layer depth
      virtual int GetLayerDepth () const = 0;

      /// @brief Changes the way that instance of IDrawableWorldObject
      /// is represented on the screen from its world position.
      /// @param New IWorldDrawingPolicy to be applied.
      virtual void ChangeWorldDrawingPolicy (
        const IWorldDrawingPolicy& worldDrawingPolicy) = 0;
  };
} // namespace yap

#endif // YAPOG_IDRAWABLEWORLDOBJECT_HPP
