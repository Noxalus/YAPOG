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

  bool GameInputEntry::IsTriggered () const
  {
    return isActive_ && !previousIsActive_;
  }

  void GameInputEntry::BeginUpdate ()
  {
    if (IsTriggered ())
      previousIsActive_ = true;
  }

  void GameInputEntry::EndUpdate ()
  {

  }
} /// namespace yap
