#include "World/Map/RemoveObjectHandler.hpp"
#include "World/Map/Map.hpp"

namespace ycl
{
  RemoveObjectHandler::RemoveObjectHandler (const yap::ID& worldID, Map& map)
    : worldID_ (worldID)
    , map_ (map)
  {
  }

  RemoveObjectHandler::~RemoveObjectHandler ()
  {
  }

  void RemoveObjectHandler::VisitPlayer (const yap::IPlayer& visitable)
  {
    yap::BaseDynamicWorldObjectConstVisitor::VisitPlayer (visitable);

    map_.RemovePlayer (worldID_);
  }

  void RemoveObjectHandler::VisitNPC (const yap::INPC& visitable)
  {
    yap::BaseDynamicWorldObjectConstVisitor::VisitNPC (visitable);

    map_.RemoveNPC (worldID_);
  }

  void RemoveObjectHandler::VisitTeleporter (const yap::Teleporter& visitable)
  {
    yap::BaseDynamicWorldObjectConstVisitor::VisitTeleporter (visitable);

    RemoveDrawableDynamicObject (worldID_);
  }

  void RemoveObjectHandler::VisitDestructibleObject (
    const yap::DestructibleObject& visitable)
  {
    yap::BaseDynamicWorldObjectConstVisitor::VisitDestructibleObject (
      visitable);

    RemoveDrawableDynamicObject (worldID_);
  }

  void RemoveObjectHandler::VisitBattleSpawnerArea (
    const yap::BattleSpawnerArea& visitable)
  {
    yap::BaseDynamicWorldObjectConstVisitor::VisitBattleSpawnerArea (
      visitable);

    RemoveDrawableDynamicObject (worldID_);
  }

  void RemoveObjectHandler::RemoveDrawableDynamicObject (
    const yap::ID& worldID)
  {
    map_.RemoveDrawableDynamicObject (worldID);
  }
} // namespace ycl
