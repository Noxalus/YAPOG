#include "YAPOG/Graphics/Gui/GameInput/GameInputEntry.hpp"

namespace yap
{
  GameInputEntry::GameInputEntry ()
    : isActive_ (false)
    , previousIsActive_ (false)
  {
  }

  GameInputEntry::~GameInputEntry ()
  {
  }

  void GameInputEntry::Activate (bool isActive)
  {
    previousIsActive_ = isActive_;

    isActive_ = isActive;
  }

  bool GameInputEntry::IsActive () const
  {
    return isActive_;
  }

  bool GameInputEntry::IsActivated () const
  {
    return isActive_ && !previousIsActive_;
  }

  bool GameInputEntry::IsDeactivated () const
  {
    return !isActive_ && previousIsActive_;
  }

  void GameInputEntry::BeginUpdate ()
  {
    if (IsActivated ())
      previousIsActive_ = true;
    else if (IsDeactivated ())
      previousIsActive_ = false;
  }

  void GameInputEntry::EndUpdate ()
  {
  }
} // namespace yap
