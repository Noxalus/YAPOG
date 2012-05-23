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
    ChanManager (String name, String color);

    String       Name;
    String       Color;
    BufferType   Buff;
    size_t       Offset;
  } CMType;
} // namespace yap

#endif // YAPOG_CHANMANAGER_HPP