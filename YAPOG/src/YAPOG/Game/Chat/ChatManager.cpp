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
    boost::filesystem::path path ("D:/git/YAPOG_chat/chat.conf");
    if (true)
    {
      Cd.Add (new ChatDisplayer ("Test 1", StringHelper::Parse<UInt32> ("0")));
      Cd.Add (new ChatDisplayer ("Test 2", StringHelper::Parse<UInt32> ("1")));
      Cd.Add (new ChatDisplayer ("Test 3", StringHelper::Parse<UInt32> ("2")));
      Cd.Add (new ChatDisplayer ("Test 4", StringHelper::Parse<UInt32> ("3")));
    }
    else
    {
      std::ifstream f;
      String line = "";
      f.open ("D:/git/YAPOG_try/chat.conf");
      while (true)
      {
        std::getline (f, line);
        if (!line.empty ())
        {
          std::cout << line << std::endl;
        }
        else
        {
          line.clear ();
          break;
        }
      }
    }
  }
  
  ChatManager::~ChatManager ()
  {
    ChatDisplayerType::ItType it (Cd.Begin ());
    ChatDisplayerType::ItType ite (Cd.End ());

    for (; it < ite; it++)
      delete (*it);
  }

} // namespace yap