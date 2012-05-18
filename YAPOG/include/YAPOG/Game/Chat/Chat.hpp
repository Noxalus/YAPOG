#ifndef YAPOG_CHAT_HPP
# define YAPOG_CHAT_HPP

# include <iostream>
# include <sstream>
# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/OPTChat.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/StringHelper.hpp"

# define HISTORYMAX 1000

namespace yap
{
	class ChatCommand;
	class YAPOG_LIB Chat : public OPTChat
	{
		DISALLOW_COPY(Chat);
	public:
    typedef std::vector<yap::String> t_vs;
		Chat ();
		Chat (std::string b);
    ~Chat ();

    // Parse chat line
		sCM								      Parse();
    
    // Getter & Setter for buffer_
		t_buffer							  GetBuf();
		void								    SetBuf(std::string b);

    // Chat History
    yap::String             GetUpHistory();
    t_buffer                GetBufHistory();
    t_vs                    GetHistory();

	private:
    void                    IncOff();
		// Check if the user's entry is a command
		bool								    Check();

		yap::String							entry_;
		t_buffer							  buffer_;
		yap::String							output_;
    t_vs                    history_;
    size_t                  offset_;
    int                     index_;
	};
} // namespace yap

#endif // YAPOG_CHAT_HPP
