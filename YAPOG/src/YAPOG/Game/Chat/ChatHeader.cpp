#include "YAPOG/Game/Chat/Chat.hpp"
#include "YAPOG/Game/Chat/ChatCommand.hpp"

namespace yap
{
	ChatHeader::ChatHeader()
	{
	}

  ChatHeader::ChatManager::ChatManager()
  {
    ChanNb = DEFAULTCHAN;
    Request = *(new BufferType);
    RequestCmd = &ChatCommand::Unknown;
  }
  
} // namespace yap