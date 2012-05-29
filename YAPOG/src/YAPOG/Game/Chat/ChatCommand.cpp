#include "YAPOG/Game/Chat/ChatCommand.hpp"
#include "YAPOG/Game/Chat/Chat.hpp"

namespace yap
{
  ChatCommand::ChatCommand ()
    : tab_ ()
    , command_ (&ChatCommand::Unknown)
  {
    MyCmdType tabs[] =
    {
      {"help", &ChatCommand::Help, nullptr},
      {"trade", &ChatCommand::Trade, nullptr},
      {"echo", &ChatCommand::Echo, nullptr}
    };
    MyCmdType tabsloc[] =
    {
      {"changechan", &ChatCommand::ChangeChan, &ChatCommand::SwitchChan}
    };

    for (unsigned i = 0; i < NBCMDSLOC; i++)
      tab_[i] = tabsloc[i];

    for (unsigned i = 0; i < NBCMDS; i++)
      tab_[NBCMDSLOC + i] = tabs[i];
  }

  std::pair<std::pair<bool, UInt32>, BufferType> MyPair (bool b,
    UInt32 i,
    BufferType bt)
  {
    return std::make_pair (std::make_pair (b, i), bt);
  }

  DisplayType         ArgMiss ()
  {
    BufferType bt;
    bt.Add ("Argument is missing.");

    return MyPair (false, 0, bt);
  }

  DisplayType         TooMuchArg ()
  {
    BufferType bt;
    bt.Add ("Too much argument.");

    return MyPair (false, 0, bt);
  }

  DisplayType         TestArg (BufferType b, UInt32 nbarg)
  {
    BufferType bt;

    if (b.Count () > nbarg)
      return TooMuchArg ();
    if (b.Count () < nbarg)
      return ArgMiss ();

    bt.Add ("Test argument failed.");

    return MyPair (false, 0, bt);
  }

  DisplayType 				ChatCommand::Help (BufferType s)
  {
    DisplayType dt;
    BufferType bt;

    bt.Add ("Command list: ");
    bt.Add ("/help\t\t: to display command list");
    bt.Add ("/trade x\t: to trade with the player x");

    return MyPair (false, 1, bt);

    return dt;
  }

  DisplayType 				ChatCommand::Echo (BufferType b)
  {
    DisplayType toret;
    BufferType bt;

    if (b.Count () > 0)
    {
      if (b[0].compare("/echo") == 0)
      {
        if (b.Count () == 1)
          return ArgMiss ();
        else
          for (size_t i = 1; i < b.Count (); i++)
            bt.Add (b[i]);
      }
      else
        bt.Add (b[0]);
    }

    toret = MyPair (false, 1, bt);

    return toret;
  }

  DisplayType	  			ChatCommand::Unknown (BufferType s)
  {
    BufferType bt;

    bt.Add ("Command " + s[0].substr (1) + " not exist.");

    return MyPair (false, 0, bt);
  }

  DisplayType		  		ChatCommand::Trade (BufferType name)
  {
    BufferType bt;

    if (name.Count () != 2)
      return TestArg (name, 2);

    bt.Add ("Trying to trade with " + name[1] + ".");

    return MyPair (false, 1, bt);
  }

  DisplayType         ChatCommand::ChangeChan (BufferType b)
  {
    BufferType bt;

    if (b.Count () != 2)
      return TestArg (b, 2);

    bt.Add ("Change to channel : " + b[1] + ".");
    bt.Add (b[1]);

    return MyPair (true, 1, bt);
  }

  void								ChatCommand::SetCommand (func cmd)
  {
    command_ = cmd;
  }

  func					      ChatCommand::GetCmd (const char *pString)
  {
    String s (pString);

    for (unsigned i = 0; i < NBCMDS + NBCMDSLOC; i++)
      if (StringHelper::CompareString(tab_[i].PtrString, s) == 0)
        return tab_[i].PtrFunc;

    return &ChatCommand::Unknown;
  }

  BufferType          ChatCommand::SwitchChan (BufferType b,
    ChatManagerType* cm,
    ChatDisplayer* cd)
  {
    BufferType bt;

    if (b.Count() > 2)
      bt.Add ("Too much argument.");
    if (b.Count() == 2)
    {
      String chanNb = b[0];

      if (StringFilter::IsNumeric(chanNb))
      {
        std::istringstream buf(chanNb);
        UInt32 tmp = 0;
        buf >> tmp;
        if (tmp >= 0 && tmp < cd->GetChanNb())
          cm->ChanNb = tmp;
        else
          bt.Add (tmp + " is not an chan number.");
      }
      else
        bt.Add ("Bad argument.");
    }

    return bt;
  }

  void  						  ChatCommand::ExecCmd (ChatDisplayer* cd,
    ChatManagerType* cm)
  {
    BufferType bt;

    DisplayType response (
      cm->Request.IsEmpty () ?
      MyPair (false, 0, bt) :
      (this->*command_) (cm->Request));

    if (response.first.first)
    {
    }

    // Re-init command line
    SetCommand (&ChatCommand::Unknown);
    cm->Request.Clear ();
  }
} // namespace yap
