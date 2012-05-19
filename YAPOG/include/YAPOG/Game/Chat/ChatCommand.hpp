#ifndef YAPOG_CHATCOMMAND_HPP
# define YAPOG_CHATCOMMAND_HPP

# include <iostream>
# include <sstream>
# include "YAPOG/Game/Chat/OPTChat.hpp"
# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/StringHelper.hpp"

# define NBCMDS 4

namespace yap
{
	class Chat;

	class YAPOG_LIB ChatCommand : public OPTChat
	{
		DISALLOW_COPY(ChatCommand);
	public:
		typedef String (ChatCommand::*func)(BufferType b);
		typedef struct sMyCmd
		{
			MyCmds m_Key;
			String m_ptS;
		} sMC;
		ChatCommand();

		// Commands
		String							Help(BufferType b);
		String							Unknown(BufferType b);
		String							Trade(BufferType b);
		String							ChangeChan(BufferType b);
		String							Echo(BufferType b);

		// Get the command
		func								GetCmd (const char *pString);
		// Execute the command
		String							ExecCmd(BufferType b, ChatManagerType f);
	private:
		sMC                 tab_[NBCMDS];
	};
} // namespace yap

#endif // YAPOG_CHATCOMMAND_HPP
