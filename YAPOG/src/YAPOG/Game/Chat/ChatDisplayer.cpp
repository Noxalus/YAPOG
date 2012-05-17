#include "YAPOG/Game/Chat/ChatDisplayer.hpp"
#include "YAPOG/Game/Chat/ChatCommand.hpp"

namespace yap
{
	ChatDisplayer::ChatDisplayer()
	{
	}
	
	void								ChatDisplayer::display(ChatDisplayer::t_buffer& s,
															   ChatDisplayer::s_CM& c)
	{
		ChatCommand cc;
		std::cout << cc.execcmd(s, c) << std::endl;
	}
} // namespace yap
