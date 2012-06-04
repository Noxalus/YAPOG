#ifndef YAPOG_CHATDISPLAYER_HPP
# define YAPOG_CHATDISPLAYER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/ChanManager.hpp"
# include "YAPOG/System/IOStream.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/Array.hpp"

# define CHANMAXBUF  1000
# define NBCHAN      6
# define DISPLAYS(s) std::cout << (s) << std::endl

namespace yap
{
  // Channel type
  typedef collection::Array<CMType*>        ChansType;
  typedef std::pair <CMType*, String>       ChanOutputType;
  typedef collection::Array<ChanOutputType> ChanBufType;

  class YAPOG_LIB ChatDisplayer
  {
    DISALLOW_COPY(ChatDisplayer);
  public:

    ChatDisplayer ();
    ChatDisplayer (String name, UInt32 c);
    //ChatDisplayer (ChansBoolType chanbooltab);
    ChatDisplayer (String name, bool* chanbooltab);
    ~ChatDisplayer ();

    UInt32          GetChanNb ();
    void            AddToChan (Int32 c, BufferType b);
    String          GetLastStrChan (UInt32 c);
    void            AddChan (UInt32 c);
    void            RmChan (UInt32 c);
    void            DisplayChanOn ();
    void			    	DisplayChan ();
    void		    		Display ();

    String          GetName ();
    ChanBufType     GetBuff ();
  private:
    void	  			  MyDisplay (size_t index, size_t last);

    String          name_;
    size_t          offset_;
    ChanBufType     buff_;
    ChansType       chans_;
    ChanOutputType  output_;
    bool*           chanbooltab_;
  };
} // namespace yap

#endif // YAPOG_CHATDISPLAYER_HPP
