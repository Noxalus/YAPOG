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

  String              argmiss()
  {
    return "Argument is missing.";
  }
  String              toomucharg()
  {
    return "Too much argument.";
  }
  String              testarg(BufferType b, Int32 nbarg)
  {
    if (b.Count() > 2)
      return toomucharg();
    if (b.Count() < 2)
      return argmiss();
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
    String toret = "";

    if (b.Count() > 0)
    {
      if (b[0].compare("/echo") == 0)
      {
        if (b.Count() == 1)
          toret = argmiss();
        else
        {
          toret += b[1];
          for (size_t i = 2; i < b.Count(); i++)
            toret += " " + b[i];
        }
      }
      else
        toret = b[0];
    }

    return toret;
  }

  String							ChatCommand::Unknown(BufferType s)
  {
    return ("Command " + s[0].substr(1) + " not exist.");
  }

  String							ChatCommand::Trade(BufferType name)
  {
    if (name.Count() != 2)
      return testarg(name, 2);
    return ("Trying to trade with " + name[1] + ".");
  }

  String              ChatCommand::ChangeChan(BufferType b)
  {
    if (b.Count() != 2)
      return testarg(b, 2);
    return "";
  }

  func					      ChatCommand::GetCmd (const char *pString)
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
