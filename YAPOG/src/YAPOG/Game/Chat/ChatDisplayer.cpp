#include "YAPOG/Game/Chat/ChatDisplayer.hpp"
#include "YAPOG/Game/Chat/ChatCommand.hpp"

namespace yap
{
	ChatDisplayer::ChatDisplayer()
	{
	}
	
	void								ChatDisplayer::Display(ChatDisplayer::t_buffer& s,
															               ChatDisplayer::sCM& c)
	{
		if (s.size() > 0)
		{
			ChatCommand cc;
			std::cout << cc.ExecCmd(s, c) << std::endl;
		}
	}
} // namespace yap
