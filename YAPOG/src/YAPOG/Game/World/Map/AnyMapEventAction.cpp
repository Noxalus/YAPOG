#include "YAPOG/Game/World/Map/AnyMapEventAction.hpp"

namespace yap
{
  AnyMapEventAction::AnyMapEventAction (CallbackType callback)
    : BaseMapEventAction ()
    , callback_ (callback)
  {
  }

  AnyMapEventAction::~AnyMapEventAction ()
  {
  }

  AnyMapEventAction::AnyMapEventAction (const AnyMapEventAction& copy)
    : BaseMapEventAction (copy)
    , callback_ (copy.callback_)
  {
  }

  AnyMapEventAction* AnyMapEventAction::Clone () const
  {
    return new AnyMapEventAction (*this);
  }

  bool AnyMapEventAction::HandleExecute (MapEventArgs& args)
  {
    return callback_ (GetContextType (), args);
  }
} // namespace yap
