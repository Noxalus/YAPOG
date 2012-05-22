#ifndef YAPOG_CHATCOMMANDLOC_HPP
# define YAPOG_CHATCOMMANDLOC_HPP

# include <iostream>
# include <sstream>
# include "YAPOG/Game/Chat/ChatHeader.hpp"
# include "YAPOG/Game/Chat/ChatManager.hpp"
# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/StringHelper.hpp"

# define NBCMDSLOC 1

namespace yap
{
	class Chat;
  class ChatDisplayer;

	class YAPOG_LIB ChatCommandLoc
	{
		DISALLOW_COPY(ChatCommandLoc);
	public:
		typedef struct MyCmd
		{
			String  PtrString;
      funcloc PtrFunc;
		} MyCmdType;
		ChatCommandLoc();

		// Commands
		String							Help(BufferType b);
		String							Unknown(BufferType b);

		// Get the command
		funcloc							GetCmd (const char *pString);
		// Execute the command
		String							ExecCmd(ChatDisplayer* cd, ChatManagerType* f);
	private:
		MyCmdType           tab_[NBCMDSLOC];
	};
} // namespace yap

#endif // YAPOG_CHATCOMMANDLOC_HPP
