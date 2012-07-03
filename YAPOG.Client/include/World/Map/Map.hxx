#ifndef YAPOG_CLIENT_MAP_HXX
# define YAPOG_CLIENT_MAP_HXX

# include                                                               \
  "YAPOG/Graphics/Game/World/Map/DrawableWorldObjectOrderComparator.hpp"

#include "YAPOG/Log.hpp"
namespace ycl
{
  template <typename T>
  inline void Map::AddDrawableStaticObject (T* object)
  {
    AddStaticObject (object);
    AddDrawableObject (object);
  }

  template <typename T>
  inline void Map::RemoveDrawableStaticObject (T* object)
  {
    RemoveStaticObject (object);
    RemoveDrawableObject (object);
  }

  template <typename T>
  inline void Map::AddDrawableDynamicObject (T* object)
  {
    AddDynamicObject (object);

    object->OnOrderStateChangedEvent ().AddHandler (
      DRAW_ORDER_HANDLER_NAME,
      [this] (yap::IDrawableDynamicWorldObject& sender,
              const yap::Vector2& args)
      {
//        DLOGGER.LogLine ("SORT DRAWING");

        /// @todo Sort by adding manually.
        drawableObjects_.Sort<yap::DrawableWorldObjectOrderComparator> ();

        /*      RemoveDrawableObject (&sender);

        yap::DrawableWorldObjectOrderComparator comparator;

        yap::collection::Array<yap::IDrawableWorldObject*>::ItType it =
          drawableObjects_.Begin ();
        for (; it < drawableObjects_.End (); ++it)
        {
          if (comparator.Compare (&sender, *it) < 0)
            break;
        }

        drawableObjects_.Insert (it, &sender);*/
      });

    AddDrawableDynamicObject (object->GetWorldID (), object);
  }
} // namespace ycl

#endif // YAPOG_CLIENT_MAP_HXX
