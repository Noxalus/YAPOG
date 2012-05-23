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
  typedef collection::Array<String>   BufferType;
  // Which chan to display
  typedef collection::Array<Int16>    ChanType;
  // Pointers on functions
  typedef String (ChatCommand::*func) (BufferType b);
} // namespace yap

#endif // YAPOG_CHATHEADER_HPP