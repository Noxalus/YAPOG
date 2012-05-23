#include "YAPOG/Game/Chat/ChanManager.hpp"

namespace yap
{
  ChanManager::ChanManager ()
  {
    Name = "Global";
    Color = "White";
  }

  ChanManager::ChanManager (String name,
                            String color)
  {
    Name = name;
    Color = color;
  }
} // namespace yap