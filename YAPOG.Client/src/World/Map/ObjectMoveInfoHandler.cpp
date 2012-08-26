#include "World/Map/ObjectMoveInfoHandler.hpp"

#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
#include "YAPOG/Game/World/Map/Character.hpp"
#include "YAPOG/System/Network/IPacket.hpp"

namespace ycl
{
  ObjectMoveInfoHandler::ObjectMoveInfoHandler (yap::IPacket& packet)
    : yap::BaseDynamicWorldObjectVisitor ()
    , packet_ (packet)
  {
  }

  ObjectMoveInfoHandler::~ObjectMoveInfoHandler ()
  {
  }

  void ObjectMoveInfoHandler::VisitDynamicWorldObject (
    yap::DynamicWorldObject& visitable)
  {
    yap::BaseDynamicWorldObjectVisitor::VisitDynamicWorldObject (visitable);

    yap::Vector2 objectPosition = packet_.ReadVector2 ();
    yap::Vector2 objectVelocity = packet_.ReadVector2 ();

    visitable.SetPosition (objectPosition);
    visitable.RawSetVelocity (objectVelocity);
  }
} // namespace ycl
