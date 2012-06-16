#ifndef YAPOG_IPLAYER_HPP
# define YAPOG_IPLAYER_HPP

# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Graphics/Gui/GameInput/GameInputType.hpp"

namespace yap
{
  struct IDynamicWorldObjectVisitor;
  struct IDynamicWorldObjectConstVisitor;

  /// @brief Interface representing the actions that a player can perform.
  struct IPlayer
  {
      virtual ~IPlayer () { }

      virtual void Accept (IDynamicWorldObjectVisitor& visitor) = 0;
      virtual void Accept (
        IDynamicWorldObjectConstVisitor& visitor) const = 0;

      virtual bool HasInput (GameInputType gameInputType) const = 0;

      virtual void Warp (const ID& mapWorldID, const Vector2& point) = 0;

      virtual void DestroyObject (const ID& objectWorldID) = 0;
  };
} // namespace yap

#endif // YAPOG_IPLAYER_HPP
