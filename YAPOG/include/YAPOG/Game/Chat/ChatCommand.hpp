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
# define NBCMDSLOC 1

namespace yap
{
  class Chat;
  class ChatDisplayer;
  typedef BufferType         (ChatCommand::*funcloc) (BufferType* b,
                                                      ChatManager* cm,
                                                      ChatDisplayer* cd);

  class YAPOG_LIB ChatCommand
  {
    DISALLOW_COPY(ChatCommand);
  public:
    typedef struct MyCmd
    {
      String  PtrString;
      func    PtrFunc;
      funcloc PtrFuncloc;
    } MyCmdType;
    ChatCommand ();

    // Commands
    // With request
    DisplayType				 	Trade (BufferType b);
    DisplayType					Echo (BufferType b);
    // Without request
    DisplayType					Help (BufferType b);
    DisplayType         ChangeChan (BufferType b);
    DisplayType					Unknown (BufferType b);
    
    // Set the command
    void								SetCommand (func cmd);
    // Get the command
    func								GetCmd (const char *pString);
    // Execute the command
    void  							ExecCmd (ChatDisplayer* cd, ChatManagerType* cm);
  private:
    BufferType          SwitchChan (BufferType* b,
                                    ChatManagerType* cm,
                                    ChatDisplayer* cd);

    MyCmdType           tab_[NBCMDS + NBCMDSLOC];
    func                command_;
  };
} // namespace yap

#endif // YAPOG_CHATCOMMAND_HPP