#include "YAPOG/Game/Chat/ChatCommandLoc.hpp"
#include "YAPOG/Game/Chat/Chat.hpp"

namespace yap
{
  ChatCommandLoc::ChatCommandLoc()
  {
    MyCmdType tabs [] =
    {
      {"help", &ChatCommandLoc::Help},
    };

    for (unsigned i = 0; i < NBCMDSLOC; i++)
      tab_[i] = tabs[i];
  }

  String							ChatCommandLoc::Help(BufferType s)
  {
    String ret = "";
    String nl = "\r\n";


    ret = "Command list: " + nl
      + "/help\t\t: to display command list" + nl
      + "/trade x\t: to trade with the player x";

    return ret;
  }
  String							ChatCommandLoc::Unknown(BufferType s)
  {
    return ("Command " + s[0].substr(1) + " not exist.");
  }

  funcloc 			      ChatCommandLoc::GetCmd (const char *pString)
  {
    String s(pString);

    for (unsigned i = 0; i < NBCMDSLOC; i++)
      if (StringHelper::CompareString(tab_[i].PtrString, s) == 0)
        return tab_[i].PtrFunc;

    return &ChatCommandLoc::Unknown;
  }

  String						  ChatCommandLoc::ExecCmd(ChatDisplayer* cd,
                                              ChatManagerType* cm)
  {
    String response = 
      cm->Request.IsEmpty() ? 
      "" :
      (this->*cm->RequestCmdLoc)(cm->Request);

    cm->RequestCmdLoc = &ChatCommandLoc::Unknown;
    cm->Request = *(new BufferType);

    return response;
  }
} // namespace yap
