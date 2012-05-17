#ifndef YAPOG_CHATCOMMAND_HPP
# define YAPOG_CHATCOMMAND_HPP

# include <iostream>
# include <sstream>
# include "YAPOG/Game/Chat/OPTChat.hpp"
# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/StringHelper.hpp"

# define NBCMDS 3

namespace yap
{
	class Chat;

	class YAPOG_LIB ChatCommand : public OPTChat
	{
		DISALLOW_COPY(ChatCommand);
	public:
		typedef yap::String (ChatCommand::*func)(t_buffer b);
		typedef struct s_MyCmd
		{
			e_Cmds m_Key;
			yap::String m_ptS;
		} s_MC;
		ChatCommand();

		// Commands
		yap::String							help(t_buffer b);
		yap::String							unknown(t_buffer b);
		yap::String							trade(t_buffer b);
		yap::String							echo(t_buffer b);

		// Get the command
		func								getCmd (const char *pString);
		// Execute the command
		yap::String							execcmd(t_buffer b, s_CM f);
	private:
		s_MC tab[NBCMDS];
	};
} // namespace yap

#endif // YAPOG_CHATCOMMAND_HPP
