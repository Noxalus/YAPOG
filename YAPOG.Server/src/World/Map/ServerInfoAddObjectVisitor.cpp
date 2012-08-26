#include "YAPOG/System/Network/IPacket.hpp"
#include "YAPOG/Graphics/RectWriter.hpp"
#include "YAPOG/Game/World/Map/DestructibleObject.hpp"
#include "YAPOG/Game/World/Map/BattleSpawnerArea.hpp"

#include "World/Map/ServerInfoAddObjectVisitor.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/NPC.hpp"
#include "World/Map/Teleporter.hpp"

namespace yse
{
  ServerInfoAddObjectVisitor::ServerInfoAddObjectVisitor (yap::IPacket& packet)
    : BaseDynamicWorldObjectConstVisitor ()
    , packet_ (packet)
  {
  }

  ServerInfoAddObjectVisitor::~ServerInfoAddObjectVisitor ()
  {
  }

  void ServerInfoAddObjectVisitor::VisitCharacter (
    const yap::Character& visitable)
  {
    yap::BaseDynamicWorldObjectConstVisitor::VisitCharacter (visitable);

    WriteAddObject (visitable);
  }

  void ServerInfoAddObjectVisitor::VisitPlayer (const yap::IPlayer& visitable)
  {
    yap::BaseDynamicWorldObjectConstVisitor::VisitPlayer (visitable);

    packet_.Write (visitable.GetName ());
  }

  void ServerInfoAddObjectVisitor::VisitTeleporter (
    const yap::Teleporter& visitable)
  {
    yap::BaseDynamicWorldObjectConstVisitor::VisitTeleporter (visitable);

    WriteAddObject (visitable);

    packet_.Write (visitable.GetMapWorldID ());
    packet_.Write (visitable.GetMapPoint ());

    yap::RectWriter<float> rectangleWriter (visitable.GetArea ());
    packet_.Accept (rectangleWriter);
  }

  void ServerInfoAddObjectVisitor::VisitDestructibleObject (
    const yap::DestructibleObject& visitable)
  {
    yap::BaseDynamicWorldObjectConstVisitor::VisitDestructibleObject (
      visitable);

    WriteAddObject (visitable);
  }

  void ServerInfoAddObjectVisitor::VisitBattleSpawnerArea (
    const yap::BattleSpawnerArea& visitable)
  {
    yap::BaseDynamicWorldObjectConstVisitor::VisitBattleSpawnerArea (
      visitable);

    WriteAddObject (visitable);

    packet_.Write (visitable.GetWidth ());
    packet_.Write (visitable.GetHeight ());
  }

  void ServerInfoAddObjectVisitor::WriteAddObject (
    const yap::DynamicWorldObject& object)
  {
    packet_.Write (object.GetWorldID ());
    packet_.Write (object.GetTypeID ());
    packet_.Write (object.GetID ());

    packet_.Write (object.GetPosition ());
    packet_.Write (object.GetState ());
  }
} // namespace yap
