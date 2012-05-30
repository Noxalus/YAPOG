#include "YAPOG/Game/Chat/ChatCommand.hpp"
#include "YAPOG/Game/Chat/ChatManager.hpp"

namespace yap
{
  ChatManager::ChatManager ()
    : Local (false)
    , ChanNb (DEFAULTCHAN)
    , Request ()
    , TabNb (DEFAULTTAB)
    , Count (4)
    , Cd ()
  {
    Cd.Add (new ChatDisplayer (0));
    Cd.Add (new ChatDisplayer (1));
    Cd.Add (new ChatDisplayer (2));
    Cd.Add (new ChatDisplayer (3));
  }
  
} // namespace yap