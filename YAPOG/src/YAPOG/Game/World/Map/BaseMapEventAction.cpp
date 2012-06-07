#include "YAPOG/Game/World/Map/BaseMapEventAction.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"

namespace yap
{
  BaseMapEventAction::BaseMapEventAction (MapEventActionType type)
    : type_ (type)
  {
  }

  BaseMapEventAction::~BaseMapEventAction ()
  {
  }

  BaseMapEventAction::BaseMapEventAction (const BaseMapEventAction& copy)
    : type_ (copy.type_)
  {
  }

  bool BaseMapEventAction::Execute (
    DynamicWorldObject& trigger,
    MapEventArgs& args)
  {
    trigger.Accept (*this);

    return HandleExecute (args);
  }

  const MapEventActionType& BaseMapEventAction::GetType () const
  {
    return type_;
  }

  void BaseMapEventAction::VisitCharacter (Character& visitable)
  {
  }

  void BaseMapEventAction::VisitPlayer (IPlayer& visitable)
  {
  }

  bool BaseMapEventAction::HandleExecute (MapEventArgs& args)
  {
    return true;
  }
} // namespace yap
