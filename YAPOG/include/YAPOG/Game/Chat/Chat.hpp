#ifndef YAPOG_CHAT_HPP
# define YAPOG_CHAT_HPP

# include <iostream>
# include <sstream>
# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/ChatCommand.hpp"
# include "YAPOG/Game/Chat/ChatDisplayer.hpp"
# include "YAPOG/Game/Chat/ChatHeader.hpp"
# include "YAPOG/Game/Chat/ChatManager.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/StringFilter.hpp"
# include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  class YAPOG_LIB Chat
  {
    DISALLOW_COPY(Chat);
  public:
    typedef collection::Array<String> BufferType;
    Chat ();
    Chat (String b);
    ~Chat ();

    // Parse chat line
    void              Parse ();
    // Execute the line
    void              Exec ();

    // Getter & Setter for buffer_
    //BufferType			GetBuf();
    void              SetBuf (String b);

    // Chat History
    String            GetUpHistory ();
    String            GetDownHistory ();
    String            GetStringHistory ();
    BufferType        GetBufHistory ();
    BufferType        GetHistory ();
    bool              ChangeChan (ChatDisplayer& display);

  private:
    void              IncOff ();
    // Check if the user's entry is a command
    bool					  	Check ();
    // Execute Echo
    void              ToEcho (String s);
    // Test History
    bool              TestHistoryChecker ();

    ChatManagerType*  chatmanager_;
    ChatCommand*      chatcommand_;
    size_t            offset_;
    UInt32            index_;
    Int32             chan_;
    String					  entry_;
    String					  output_;
    BufferType			  buffer_;
    BufferType        history_;
  };
} // namespace yap

#endif // YAPOG_CHAT_HPP
