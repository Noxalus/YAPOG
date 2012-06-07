#ifndef YAPOG_CHATHEADER_HPP
# define YAPOG_CHATHEADER_HPP

# include <utility>
# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"

# define HISTORYMAX 1000
# define DEFAULTCHAN 1
# define DEFAULTTAB 0

namespace yap
{
  class ChatCommand;
  typedef collection::Array<String>   BufferType;
  // Which chan to display
  typedef collection::Array<Int16>    ChanType;
  // Pointers on functions
  typedef std::pair<
    std::pair<bool, UInt32>,
    std::pair<UInt32, BufferType>>    DisplayType;
  
  typedef collection::Array<
    std::pair<UInt32, String>>        ResponsesType;
  typedef std::pair<
    bool, ResponsesType>              ResponseType;
  typedef DisplayType                 (ChatCommand::*func) (BufferType b);
} // namespace yap

#endif // YAPOG_CHATHEADER_HPP