#include "YAPOG/Game/Chat/ChatCommand.hpp"
#include "YAPOG/Game/Chat/ChatCommandLoc.hpp"
#include "YAPOG/Game/Chat/ChatManager.hpp"

namespace yap
{
  ChatManager::ChatManager()
  {
    ChanNb = DEFAULTCHAN;
    Request = *(new BufferType);
    RequestCmd = &ChatCommand::Unknown;
    RequestCmdLoc = &ChatCommandLoc::Unknown;
  }
  
} // namespace yap