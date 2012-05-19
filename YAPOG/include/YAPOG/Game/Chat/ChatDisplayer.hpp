#ifndef YAPOG_CHATDISPLAYER_HPP
# define YAPOG_CHATDISPLAYER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/Chat.hpp"
# include "YAPOG/Game/Chat/OPTChat.hpp"
# include "YAPOG/System/IOStream.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
	class YAPOG_LIB ChatDisplayer : public OPTChat
	{
		DISALLOW_COPY(ChatDisplayer);
	public:
    typedef struct ChanManager
    {
      ChanManager ();
      ChanManager (String name, String color);

      String       Name;
      String       Color;
      BufferType   Buff;
    } CMType;
    typedef collection::Array<CMType*> ChansType;
		ChatDisplayer();
    ~ChatDisplayer();
		
		void								Display(BufferType& s, ChatManagerType& c);
  private:
    ChansType           chans_;
	};
} // namespace yap

#endif // YAPOG_CHATDISPLAYER_HPP
