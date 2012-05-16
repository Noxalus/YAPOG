#ifndef YAPOG_CHAT_HPP
# define YAPOG_CHAT_HPP

# include <vector>
# include <iostream>
# include <sstream>
# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/ChatDisplayer.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/StringHelper.hpp"

namespace yap
{
	class YAPOG_LIB Chat
	{
		DISALLOW_COPY(Chat);
	public:
		typedef std::vector<yap::String>	t_b;
		enum E_Cmds
		{
			c_Help,
			c_Trade,
			c_Unknown,
		};
		typedef struct s_ChatManager 
		{
			int			cmd;
			yap::String request;
			E_Cmds		request_cmd;
		} s_CM;

		Chat ();

		void								setbuf(std::string b);

		s_CM								parse();
		void								display(Chat& c);

	private:
		// Check if the user's entry is a command
		bool								check();

		// Get the command
		E_Cmds								getCmd (const char *pString);
		// Execute the command
		yap::String							execcmd();

		// Commands
		yap::String							help(yap::String s = "");
		yap::String							unknown(yap::String s = "");
		yap::String							trade(yap::String name);

		yap::String							entry_;
		t_b									buffer_;
	};
} // namespace yap

#endif // YAPOG_CHAT_HPP
