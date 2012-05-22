#ifndef YAPOG_CHATHEADER_HPP
# define YAPOG_CHATHEADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"

# define HISTORYMAX 1000
# define DEFAULTCHAN 0

namespace yap
{
  class ChatCommand;
  class ChatCommandLoc;
  typedef collection::Array<String>   BufferType;
  typedef collection::Array<Int16>    ChanType; // Which chan to display
  // Pointers on functions
  // Local
  typedef String (ChatCommandLoc::*funcloc)(BufferType b);
  // Request
  typedef String (ChatCommand::*func)(BufferType b);
} // namespace yap

#endif // YAPOG_CHATHEADER_HPP