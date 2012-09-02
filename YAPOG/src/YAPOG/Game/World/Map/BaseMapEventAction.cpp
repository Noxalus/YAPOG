#include "YAPOG/Game/World/Map/BaseMapEventAction.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"

namespace yap
{
  const MapEventActionType BaseMapEventAction::DEFAULT_CONTEXT_TYPE =
    MapEventActionType::In;

  BaseMapEventAction::BaseMapEventAction ()
    : contextType_ (DEFAULT_CONTEXT_TYPE)
    , args_ (nullptr)
  {
  }

  BaseMapEventAction::~BaseMapEventAction ()
  {
  }

  BaseMapEventAction::BaseMapEventAction (const BaseMapEventAction& copy)
    : contextType_ (copy.contextType_)
    , args_ (nullptr)
  {
  }

  bool BaseMapEventAction::Execute (
    MapEventActionType contextType,
    DynamicWorldObject& trigger,
    MapEventArgs& args)
  {
    contextType_ = contextType;

    args_ = &args;

    trigger.Accept (*this);

    return HandleExecute (args);
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

  MapEventActionType BaseMapEventAction::GetContextType () const
  {
    return contextType_;
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
