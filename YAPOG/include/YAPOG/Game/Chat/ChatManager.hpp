#ifndef YAPOG_CHATMANAGER_HPP
# define YAPOG_CHATMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/ChatHeader.hpp"
# include "YAPOG/Game/Chat/ChatDisplayer.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class ChatCommand;

  typedef collection::Array<ChatDisplayer*> ChatDisplayerType;

  typedef struct ChatManager
  {
    ChatManager ();

    bool              Local;
    UInt32            ChanNb;
    BufferType				Request;
    UInt32            TabNb;
    UInt32            Count;
    ChatDisplayerType Cd;
  } ChatManagerType;
} // namespace yap

#endif // YAPOG_CHATMANAGER_HPP