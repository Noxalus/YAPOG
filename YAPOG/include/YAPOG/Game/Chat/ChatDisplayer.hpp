#ifndef YAPOG_CHATDISPLAYER_HPP
# define YAPOG_CHATDISPLAYER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/ChanManager.hpp"
# include "YAPOG/System/IOStream.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/Array.hpp"

# define CHANMAXBUF  1000

namespace yap
{
  class YAPOG_LIB ChatDisplayer
  {
    DISALLOW_COPY(ChatDisplayer);
  public:
    // Channel type
    typedef collection::Array<CMType*>  ChansType;
    typedef collection::Array<String>   ChanBuf;

    ChatDisplayer ();
    ~ChatDisplayer ();

    UInt32      GetChanNb ();
    //void			  Display(ChatManagerType* c);
    String      GetLastStrChan (Int32 c);
    void        AddToChan (Int32 c, String s);
    void				DisplayChan (Int32 c);
    void				Display ();
  private:
    size_t      offset_;
    ChanBuf     buff_;
    ChansType   chans_;
  };
} // namespace yap

#endif // YAPOG_CHATDISPLAYER_HPP
