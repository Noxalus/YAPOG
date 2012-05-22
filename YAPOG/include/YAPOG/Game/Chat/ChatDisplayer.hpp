#ifndef YAPOG_CHATDISPLAYER_HPP
# define YAPOG_CHATDISPLAYER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/ChanManager.hpp"
# include "YAPOG/Game/Chat/Chat.hpp"
# include "YAPOG/Game/Chat/ChatHeader.hpp"
# include "YAPOG/Game/Chat/ChatManager.hpp"
# include "YAPOG/System/IOStream.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
	class YAPOG_LIB ChatDisplayer
	{
		DISALLOW_COPY(ChatDisplayer);
	public:
    typedef collection::Array<CMType*>  ChansType; // Channel type
		ChatDisplayer();
    ~ChatDisplayer();
		
    UInt32              GetChanNb();
		void								Display(ChatManagerType* c);
  private:
    ChansType           chans_;
	};
} // namespace yap

#endif // YAPOG_CHATDISPLAYER_HPP
