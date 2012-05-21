#ifndef YAPOG_CHATDISPLAYER_HPP
# define YAPOG_CHATDISPLAYER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/Chat.hpp"
# include "YAPOG/Game/Chat/ChatHeader.hpp"
# include "YAPOG/System/IOStream.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
	class YAPOG_LIB ChatDisplayer : public ChatHeader
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
		
    int                 GetChanNb();
		void								Display(ChatManagerType* c);
  private:
    ChansType           chans_;
	};
} // namespace yap

#endif // YAPOG_CHATDISPLAYER_HPP
