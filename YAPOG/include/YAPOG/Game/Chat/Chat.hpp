#ifndef YAPOG_CHAT_HPP
# define YAPOG_CHAT_HPP

# include <iostream>
# include <sstream>
# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/ChatCommand.hpp"
# include "YAPOG/Game/Chat/OPTChat.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/StringHelper.hpp"

namespace yap
{
	class YAPOG_LIB Chat : public OPTChat
	{
		DISALLOW_COPY(Chat);
	public:
    typedef collection::Array<String> VStringType;
		Chat ();
		Chat (String b);
    ~Chat ();

    // Parse chat line
		ChatManagerType*  Parse();
    
    // Getter & Setter for buffer_
		//BufferType			GetBuf();
		void              SetBuf(String b);

    // Chat History
    String            GetUpHistory();
    String            GetStringHistory();
    BufferType        GetBufHistory();
    VStringType       GetHistory();
    bool              ChangeChan();

	private:
    void              IncOff();
		// Check if the user's entry is a command
		bool					  	Check();
    
    ChatManagerType*  chatmanager_;
    size_t            offset_;
    Int32             index_;
    Int32             chan_;
		String					  entry_;
		String					  output_;
		BufferType			  buffer_;
    VStringType       history_;
	};
} // namespace yap

#endif // YAPOG_CHAT_HPP
