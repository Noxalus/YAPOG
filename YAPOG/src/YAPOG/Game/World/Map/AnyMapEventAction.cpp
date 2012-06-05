#include "YAPOG/Game/World/Map/AnyMapEventAction.hpp"

namespace yap
{
  AnyMapEventAction::AnyMapEventAction (CallbackType callback)
    : callback_ (callback)
  {
  }

  AnyMapEventAction::~AnyMapEventAction ()
  {
  }

  bool AnyMapEventAction::Execute (MapEventArgs& args)
  {
    return callback_ (args);
  }
} // namespace yap
