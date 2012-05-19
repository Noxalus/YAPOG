#ifndef YAPOG_OPTCHAT_HPP
# define YAPOG_OPTCHAT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"

# define HISTORYMAX 1000
# define DEFAULTCHAN 0

namespace yap
{
	class ChatCommand;
	typedef collection::Array<String>		BufferType;

	class YAPOG_LIB OPTChat
	{
		DISALLOW_COPY(OPTChat);
	public:
		OPTChat();
		typedef collection::Array<String>	BufferType;
    typedef collection::Array<Int16>	ChanType;
	  typedef String (ChatCommand::*func)(BufferType b);
		typedef struct ChatManager
		{
      ChatManager();

      UInt32            ChanNb;
			BufferType				Request;
			func					    RequestCmd;
		} ChatManagerType;
	};
} // namespace yap

#endif // YAPOG_OPTCHAT_HPP
