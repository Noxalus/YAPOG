#ifndef YAPOG_CHATDISPLAYER_HPP
# define YAPOG_CHATDISPLAYER_HPP

# include <iostream>
# include <sstream>
# include "YAPOG/Game/Chat/Chat.hpp"
# include "YAPOG/Game/Chat/OPTChat.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
	class YAPOG_LIB ChatDisplayer : public OPTChat
	{
		DISALLOW_COPY(ChatDisplayer);
	public:
		ChatDisplayer();
		
		void								display(t_buffer& s, s_CM& c);
	};
} // namespace yap

#endif // YAPOG_CHATDISPLAYER_HPP
