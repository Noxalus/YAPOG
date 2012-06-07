#ifndef YAPOG_CHANMANAGER_HPP
# define YAPOG_CHANMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Chat/ChatHeader.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class ChatCommand;

  typedef struct ChanManager
  {
    ChanManager ();
    ChanManager (String name, String color, UInt32 chanNb);

    String        Name;
    String        Color;
    UInt32        ChanNb;
  } CMType;
} // namespace yap

#endif // YAPOG_CHANMANAGER_HPP