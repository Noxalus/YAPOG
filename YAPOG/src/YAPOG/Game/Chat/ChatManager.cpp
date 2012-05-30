#include "YAPOG/Game/Chat/ChatCommand.hpp"
#include "YAPOG/Game/Chat/ChatManager.hpp"

namespace yap
{
  ChatManager::ChatManager ()
    : Local (false)
    , ChanNb (DEFAULTCHAN)
    , Request ()
    , TabNb (DEFAULTTAB)
    , Count (4)
    , Cd ()
  {
    Cd.Add (new ChatDisplayer ("Test 1", StringHelper::Parse<UInt32> ("0")));
    Cd.Add (new ChatDisplayer ("Test 2", StringHelper::Parse<UInt32> ("1")));
    Cd.Add (new ChatDisplayer ("Test 3", StringHelper::Parse<UInt32> ("2")));
    Cd.Add (new ChatDisplayer ("Test 4", StringHelper::Parse<UInt32> ("3")));
  }
  
  ChatManager::~ChatManager ()
  {
    ChatDisplayerType::ItType it (Cd.Begin ());
    ChatDisplayerType::ItType ite (Cd.End ());

    for (; it < ite; it++)
      delete (*it);
  }

} // namespace yap