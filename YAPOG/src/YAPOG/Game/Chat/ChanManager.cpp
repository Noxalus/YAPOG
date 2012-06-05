#include "YAPOG/Game/Chat/ChanManager.hpp"

namespace yap
{
  ChanManager::ChanManager ()
    : Name ("System")
    , Color ("Red")
    , ChanNb (0)
  {
  }

  ChanManager::ChanManager (String name,
                            String color,
                            UInt32 chanNb)
    : Name (name)
    , Color (color)
    , ChanNb (chanNb)
  {
  }
} // namespace yap