#ifndef YAPOG_CHATCOMMAND_HPP
# define YAPOG_CHATCOMMAND_HPP

# include <iostream>
# include <sstream>
# include "YAPOG/Game/Chat/ChatHeader.hpp"
# include "YAPOG/Game/Chat/ChatManager.hpp"
# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/StringHelper.hpp"

# define NBCMDS 3

namespace yap
{
  class Chat;
  class ChatDisplayer;

  class YAPOG_LIB ChatCommand
  {
    DISALLOW_COPY(ChatCommand);
  public:
    typedef struct MyCmd
    {
      String  PtrString;
      func    PtrFunc;
    } MyCmdType;
    ChatCommand ();

    // Commands
    String							Help (BufferType b);
    String							Unknown (BufferType b);
    String							Trade (BufferType b);
    String							Echo (BufferType b);
    String              ChangeChan (BufferType b);

    // Get the command
    func								GetCmd (const char *pString);
    // Execute the command
    String							ExecCmd (ChatDisplayer* cd, ChatManagerType* f);
  private:
    MyCmdType           tab_[NBCMDS];
  };
} // namespace yap

#endif // YAPOG_CHATCOMMAND_HPP
