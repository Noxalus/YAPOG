#ifndef YAPOG_CHAT_HPP
# define YAPOG_CHAT_HPP

# include <iostream>
# include <sstream>
# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/ChatCommand.hpp"
# include "YAPOG/Game/Chat/ChatDisplayer.hpp"
# include "YAPOG/Game/Chat/ChatHeader.hpp"
# include "YAPOG/Game/Chat/ChatManager.hpp"
# include "YAPOG/System/IntTypes.hpp"
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

    // Parse chat line - Return a string if arrow up/down is pushed
    String                  Parse ();
    // Execute the line - Return chan number and a string to display
    ResponseType            Exec ();

    // Getter & Setter for buffer_
    void                    SetBuf (String b);

    // Chat History
    std::pair<bool, String> GetUpHistory ();
    std::pair<bool, String> GetDownHistory ();
    String                  GetStringHistory ();
    BufferType              GetBufHistory ();
    BufferType              GetHistory ();
    bool                    GetIsCommand ();
    bool                    ChangeChan (ChatDisplayer& display);

    String                  GetTabName (UInt32 TabNb);
    UInt32                  GetTabCount ();
    UInt32                  GetTabNb ();

  private:
    void                    IncOff ();
    // Check if the user's entry is a command
    void					  	      Check ();
    // Execute Echo
    void                    ToEcho (String s);
    // Test History
    std::pair<bool, String> TestHistoryChecker ();

    ChatManagerType*        chatmanager_;
    ChatCommand*            chatcommand_;
    size_t                  offset_;
    UInt32                  index_;
    Int32                   chan_;
    String					        entry_;
    String					        output_;
    BufferType			        buffer_;
    BufferType              history_;
    bool                    isCommand_;
  };
} // namespace yap

#endif // YAPOG_CHAT_HPP
