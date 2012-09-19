#ifndef YAPOG_IPLAYER_HPP
# define YAPOG_IPLAYER_HPP

# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Graphics/Gui/GameInput/GameInputType.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  struct IDynamicWorldObjectVisitor;
  struct IDynamicWorldObjectConstVisitor;

  class DynamicWorldObject;

  struct IDialogActor;

  /// @brief Interface representing the actions that a player can perform.
  struct IPlayer
  {
      virtual ~IPlayer () { }

      virtual void Accept (IDynamicWorldObjectVisitor& visitor) = 0;
      virtual void Accept (
        IDynamicWorldObjectConstVisitor& visitor) const = 0;

      virtual const String& GetName () const = 0;

      virtual bool HasInputActivated (GameInputType gameInputType) const = 0;
      virtual bool HasInputDeactivated (GameInputType gameInputType) const = 0;
      virtual bool HasInputActive (GameInputType gameInputType) const = 0;

      virtual void Warp (const ID& mapWorldID, const Vector2& point) = 0;

      virtual void DestroyObject (const ID& objectWorldID) = 0;

      /// @todo Battle triggering management.
      virtual void TriggerBattle () = 0;

      virtual void Talk (const IDialogActor& dialogActor) = 0;

      virtual Event<DynamicWorldObject&, const Vector2&>& OnMovedEvent () = 0;
  };
} // namespace yap

#endif // YAPOG_IPLAYER_HPP
