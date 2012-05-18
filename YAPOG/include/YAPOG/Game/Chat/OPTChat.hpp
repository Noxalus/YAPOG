#ifndef YAPOG_OPTCHAT_HPP
# define YAPOG_OPTCHAT_HPP

# include <vector>
# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
	class ChatCommand;
	typedef std::vector<yap::String>		t_buffer;
	typedef yap::String (ChatCommand::*func)(t_buffer b);

	class YAPOG_LIB OPTChat
	{
		DISALLOW_COPY(OPTChat);
	public:
		OPTChat();
		typedef std::vector<yap::String>	t_buffer;
		
		enum eCmds
		{
			c_Help,
			c_Trade,
			c_Echo,
			c_Unknown,
		};
		typedef struct sChatManager
		{
			t_buffer				request;
			func					  request_cmd;
		} sCM;
	};
} // namespace yap

#endif // YAPOG_OPTCHAT_HPP
