#include "YAPOG/Game/World/Map/BaseMapEventAction.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"

namespace yap
{
  BaseMapEventAction::BaseMapEventAction (MapEventActionType type)
    : type_ (type)
    , args_ (nullptr)
  {
  }

  BaseMapEventAction::~BaseMapEventAction ()
  {
  }

  BaseMapEventAction::BaseMapEventAction (const BaseMapEventAction& copy)
    : type_ (copy.type_)
    , args_ (nullptr)
  {
  }

  bool BaseMapEventAction::Execute (
    DynamicWorldObject& trigger,
    MapEventArgs& args)
  {
    args_ = &args;

    trigger.Accept (*this);

    return HandleExecute (args);
  }

  const MapEventActionType& BaseMapEventAction::GetType () const
  {
    return type_;
  }

  void BaseMapEventAction::VisitDynamicWorldObject (
    DynamicWorldObject& visitable)
  {
  }

  void BaseMapEventAction::VisitCharacter (Character& visitable)
  {
  }

  void BaseMapEventAction::VisitPlayer (IPlayer& visitable)
  {
  }

  void BaseMapEventAction::VisitTeleporter (Teleporter& visitable)
  {
  }

  void BaseMapEventAction::VisitDestructibleObject (
    DestructibleObject& visitable)
  {
  }

  void BaseMapEventAction::VisitBattleSpawnerArea (
    BattleSpawnerArea& visitable)
  {
  }

  MapEventArgs& BaseMapEventAction::GetArgs ()
  {
    return *args_;
  }

  bool BaseMapEventAction::HandleExecute (MapEventArgs& args)
  {
    return true;
  }
} // namespace yap
