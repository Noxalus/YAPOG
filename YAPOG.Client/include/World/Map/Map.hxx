#ifndef YAPOG_CLIENT_MAP_HXX
# define YAPOG_CLIENT_MAP_HXX

# include                                                               \
  "YAPOG/Graphics/Game/World/Map/DrawableWorldObjectOrderComparator.hpp"

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
        /// @todo Sort by adding manually.
        drawableObjects_.Sort<yap::DrawableWorldObjectOrderComparator> ();
      });

    AddDrawableDynamicObject (object->GetWorldID (), object);
  }
} // namespace ycl

#endif // YAPOG_CLIENT_MAP_HXX
