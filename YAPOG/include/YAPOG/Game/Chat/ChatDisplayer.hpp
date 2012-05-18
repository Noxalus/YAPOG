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
		
		void								Display(t_buffer& s, sCM& c);
	};
} // namespace yap

#endif // YAPOG_CHATDISPLAYER_HPP
