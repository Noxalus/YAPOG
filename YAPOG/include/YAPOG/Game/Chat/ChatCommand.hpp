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
		typedef struct sMyCmd
		{
			eCmds m_Key;
			yap::String m_ptS;
		} sMC;
		ChatCommand();

		// Commands
		yap::String							Help(t_buffer b);
		yap::String							Unknown(t_buffer b);
		yap::String							Trade(t_buffer b);
		yap::String							Echo(t_buffer b);

		// Get the command
		func								    GetCmd (const char *pString);
		// Execute the command
		yap::String							ExecCmd(t_buffer b, sCM f);
	private:
		sMC                     tab_[NBCMDS];
	};
} // namespace yap

#endif // YAPOG_CHATCOMMAND_HPP
