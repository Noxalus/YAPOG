#ifndef YAPOG_IDRAWABLEDYNAMICWORLDOBJECT_HPP
# define YAPOG_IDRAWABLEDYNAMICWORLDOBJECT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/World/Map/IDrawableWorldObject.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  struct IDrawableDynamicWorldObject : public IDrawableWorldObject
  {
      virtual ~IDrawableDynamicWorldObject () { }

      virtual Event<IDrawableDynamicWorldObject&,
                    const Vector2&>& OnMovedEvent () = 0;
  };
} // namespace yap

#endif // YAPOG_IDRAWABLEDYNAMICWORLDOBJECT_HPP
