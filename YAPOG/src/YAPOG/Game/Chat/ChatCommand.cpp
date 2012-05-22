#include "YAPOG/Game/Chat/ChatCommand.hpp"
#include "YAPOG/Game/Chat/Chat.hpp"

namespace yap
{
  ChatCommand::ChatCommand()
  {
    MyCmdType tabs [] =
    {
      {"help", &ChatCommand::Help},
      {"trade", &ChatCommand::Trade},
      {"echo", &ChatCommand::Echo}
    };

    for (unsigned i = 0; i < NBCMDS; i++)
      tab_[i] = tabs[i];
  }

  String							ChatCommand::Help(BufferType s)
  {
    String ret = "";
    String nl = "\r\n";


    ret = "Command list: " + nl
      + "/help\t\t: to display command list" + nl
      + "/trade x\t: to trade with the player x";

    return ret;
  }

  String							ChatCommand::Echo(BufferType b)
  {
    if (b[0].compare(0, 4, "/echo") == 0)
      return b[0].substr(5);

    return b[0];
  }

  String							ChatCommand::Unknown(BufferType s)
  {
    return ("Command " + s[0].substr(1) + " not exist.");
  }

  String							ChatCommand::Trade(BufferType name)
  {
    if (name.Count() > 2)
      return ("Unable to trade with so much people!!");
    if (name.Count() < 2)
      return ("Unable to trade with nobody...");
    return ("Trying to trade with " + name[1] + ".");
  }

  func					     ChatCommand::GetCmd (const char *pString)
  {
    String s(pString);

    for (unsigned i = 0; i < NBCMDS; i++)
      if (StringHelper::CompareString(tab_[i].PtrString, s) == 0)
        return tab_[i].PtrFunc;

    return &ChatCommand::Unknown;
  }

  String						ChatCommand::ExecCmd(ChatDisplayer* cd,
                                         ChatManagerType* cm)
  {
    String response = 
      cm->Request.IsEmpty() ? 
      "" :
      (this->*cm->RequestCmd)(cm->Request);

    cm->RequestCmd = &ChatCommand::Unknown;
    cm->Request = *(new BufferType);

    return response;
  }
} // namespace yap
