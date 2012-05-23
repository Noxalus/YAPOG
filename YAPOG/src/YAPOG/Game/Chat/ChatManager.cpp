#include "YAPOG/Game/Chat/ChatCommand.hpp"
#include "YAPOG/Game/Chat/ChatManager.hpp"

namespace yap
{
  ChatManager::ChatManager()
  {
    Local = false;
    ChanNb = DEFAULTCHAN;
    Request = *(new BufferType);
    RequestCmd = &ChatCommand::Unknown;
  }
  
} // namespace yap