#include "World/Map/ObjectMoveInfoSender.hpp"

#include "YAPOG/System/Network/IPacket.hpp"
#include "YAPOG/System/IntTypes.hpp"
#include "YAPOG/Game/World/Map/Character.hpp"
#include "YAPOG/Game/World/Map/DestructibleObject.hpp"
#include "YAPOG/Game/World/Map/BattleSpawnerArea.hpp"
#include "YAPOG/Game/World/Map/Teleporter.hpp"

namespace yse
{
  ObjectMoveInfoSender::ObjectMoveInfoSender (
    yap::IPacket& packet,
    const yap::Vector2& objectVelocity)
    : BaseDynamicWorldObjectConstVisitor ()
    , packet_ (packet)
    , objectVelocity_ (objectVelocity)
  {
  }

  ObjectMoveInfoSender::~ObjectMoveInfoSender ()
  {
  }

  void ObjectMoveInfoSender::VisitDynamicWorldObject (
    const yap::DynamicWorldObject& visitable)
  {
    yap::BaseDynamicWorldObjectConstVisitor::VisitDynamicWorldObject (
      visitable);

    packet_.Write (visitable.GetWorldID ());
    packet_.Write (visitable.GetPosition ());
    packet_.Write (objectVelocity_);
  }
} // namespace yse
