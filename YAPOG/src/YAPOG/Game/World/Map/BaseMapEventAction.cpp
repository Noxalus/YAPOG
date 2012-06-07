#include "YAPOG/Game/World/Map/BaseMapEventAction.hpp"

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

  bool BaseMapEventAction::Execute (MapEventArgs& args)
  {
    return HandleExecute (args);
  }

  const MapEventActionType& BaseMapEventAction::GetType () const
  {
    return type_;
  }

  bool BaseMapEventAction::HandleExecute (MapEventArgs& args)
  {
    return true;
  }
} // namespace yap
