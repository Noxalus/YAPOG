#ifndef YAPOG_CHATMANAGER_HPP
# define YAPOG_CHATMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/ChatHeader.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class ChatCommand;
  typedef struct ChatManager
  {
    ChatManager();

    UInt32            ChanNb;
    BufferType				Request;
    func					    RequestCmd;
    funcloc 			    RequestCmdLoc;
  } ChatManagerType;
} // namespace yap

#endif // YAPOG_CHATMANAGER_HPP