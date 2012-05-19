#ifndef YAPOG_CHAT_HPP
# define YAPOG_CHAT_HPP

# include <iostream>
# include <sstream>
# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/OPTChat.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/StringHelper.hpp"

namespace yap
{
	class ChatCommand;
	class YAPOG_LIB Chat : public OPTChat
	{
		DISALLOW_COPY(Chat);
	public:
    typedef collection::Array<String> VStringType;
		Chat ();
		Chat (String b);
    ~Chat ();

    // Parse chat line
		ChatManagerType Parse();
    
    // Getter & Setter for buffer_
		BufferType			GetBuf();
		void            SetBuf(String b);

    // Chat History
    String          GetUpHistory();
    BufferType      GetBufHistory();
    VStringType     GetHistory();

	private:
		// Check if the user's entry is a command
		bool						Check();

		String					entry_;
		BufferType			buffer_;
		String					output_;
    VStringType     history_;
    size_t          offset_;
    Int32           index_;
	};
} // namespace yap

#endif // YAPOG_CHAT_HPP
