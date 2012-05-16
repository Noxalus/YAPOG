#ifndef YAPOG_CHATDISPLAYER_HPP
# define YAPOG_CHATDISPLAYER_HPP

# include <iostream>
# include <sstream>
# include "YAPOG/Game/Chat/Chat.hpp"

namespace yap
{
	class YAPOG_LIB ChatDisplayer
	{
		DISALLOW_COPY(ChatDisplayer);
	public:
		ChatDisplayer();

		void								display(Chat& c);
	};
} // namespace yap

#endif // YAPOG_CHATDISPLAYER_HPP
