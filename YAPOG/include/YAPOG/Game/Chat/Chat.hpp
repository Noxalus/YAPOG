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
		Chat ();
		Chat (std::string b);

		s_CM								parse();
		t_buffer							getbuf();

	private:
		void								setbuf(std::string b);
		// Check if the user's entry is a command
		bool								check();

		yap::String							entry_;
		t_buffer							buffer_;
		yap::String							output_;
	};
} // namespace yap

#endif // YAPOG_CHAT_HPP
