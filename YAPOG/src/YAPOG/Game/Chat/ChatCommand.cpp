#include "YAPOG/Game/Chat/ChatCommand.hpp"
#include "YAPOG/Game/Chat/Chat.hpp"

namespace yap
{
  ChatCommand::ChatCommand ()
    : tab_ (new MyCmdType[NBCMDS + NBCMDSLOC])
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
      {"switchtab", &ChatCommand::SwitchTab, &ChatCommand::SwitchTab},
      {"switchchan", &ChatCommand::SwitchChan, &ChatCommand::SwitchChan},
      {"addchan", &ChatCommand::AddChan, &ChatCommand::AddChan},
      {"rmchan", &ChatCommand::RmChan, &ChatCommand::RmChan}
    };

    for (unsigned i = 0; i < NBCMDSLOC; i++)
      tab_[i] = tabsloc[i];

    for (unsigned i = 0; i < NBCMDS; i++)
      tab_[NBCMDSLOC + i] = tabs[i];
  }

  ChatCommand::~ChatCommand ()
  {
    delete[] tab_;
    tab_ = nullptr;
  }

  std::pair<
    std::pair<bool, UInt32>,
    std::pair<UInt32, BufferType>> MyPair (bool b,
    UInt32 fct,
    UInt32 chan,
    BufferType bt)  
  {
    return std::make_pair (
      std::make_pair (b, fct),
      std::make_pair (chan, bt));
  }

  DisplayType         ArgMiss ()
  {
    BufferType bt;
    bt.Add ("Argument is missing.");

    return MyPair (false, NBTOTCMDS + 1, 0, bt);
  }

  DisplayType         TooMuchArg ()
  {
    BufferType bt;
    bt.Add ("Too much argument.");

    return MyPair (false, NBTOTCMDS + 1, 0, bt);
  }

  DisplayType         TestArg (BufferType b, UInt32 nbarg)
  {
    BufferType bt;

    if (b.Count () > nbarg)
      return TooMuchArg ();
    if (b.Count () < nbarg)
      return ArgMiss ();

    bt.Add ("Test argument failed.");

    return MyPair (false, NBTOTCMDS + 1, 0, bt);
  }

  DisplayType 				ChatCommand::Help (BufferType s)
  {
    DisplayType dt;
    BufferType bt;

    bt.Add ("Command list: ");
    bt.Add ("/help\t\t: to display command list");
    bt.Add ("/trade x\t: to trade with the player x");

    return MyPair (false, NBTOTCMDS + 1, 1, bt);

    return dt;
  }

  DisplayType 				ChatCommand::Echo (BufferType b)
  {
    DisplayType toret;
    UInt32 channb = StringHelper::Parse<int> (b[b.Count () - 1]);
    BufferType bt;

    b.RemoveBack ();
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

    toret = MyPair (false, NBTOTCMDS + 1, channb, bt);

    return toret;
  }

  DisplayType	  			ChatCommand::Unknown (BufferType s)
  {
    BufferType bt;

    bt.Add ("Command " + s[0].substr (1) + " not exist.");

    return MyPair (false, NBTOTCMDS + 1, 0, bt);
  }

  DisplayType		  		ChatCommand::Trade (BufferType name)
  {
    BufferType bt;
    name.RemoveBack ();

    if (name.Count () != 2)
      return TestArg (name, 2);

    bt.Add ("Trying to trade with " + name[1] + ".");

    return MyPair (false, NBTOTCMDS + 1, 0, bt);
  }

  DisplayType         ChatCommand::SwitchTab (BufferType b)
  {
    BufferType bt;
    b.RemoveBack ();

    if (b.Count () != 2)
      return TestArg (b, 2);

    bt.Add ("Switch to tab : " + b[1] + ".");
    bt.Add (b[1]);

    return MyPair (true, 0, 0, bt);
  }

  DisplayType         ChatCommand::SwitchChan (BufferType b)
  {
    BufferType bt;
    b.RemoveBack ();

    if (b.Count () != 2)
      return TestArg (b, 2);

    bt.Add ("Switch to chan : " + b[1] + ".");
    bt.Add (b[1]);

    return MyPair (true, 1, 0, bt);
  }

  DisplayType         ChatCommand::AddChan (BufferType b)
  {
    BufferType bt;
    b.RemoveBack ();

    if (b.Count () != 2)
      return TestArg (b, 2);

    bt.Add ("Channel " + b[1] + " has been added.");
    bt.Add (b[1]);

    return MyPair (true, 2, 0, bt);
  }

  DisplayType         ChatCommand::RmChan (BufferType b)
  {
    BufferType bt;
    b.RemoveBack ();

    if (b.Count () != 2)
      return TestArg (b, 2);

    bt.Add ("Channel : " + b[1] + " has been removed.");
    bt.Add (b[1]);

    return MyPair (true, 3, 0, bt);
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

  BufferType          ChatCommand::SwitchTab (UInt32* channb,
    BufferType* b,
    ChatManagerType* cm,
    ChatDisplayer* cd)
  {
    BufferType bt;

    if (b->Count() > 2)
      bt.Add ("Too much argument.");
    if (b->Count() == 2)
    {
      String chanNb = (*b)[1];

      if (StringFilter::IsNumeric (chanNb))
      {
        std::istringstream buf (chanNb);
        UInt32 tmp = 0;
        buf >> tmp;
        if (tmp >= 0 && tmp < cm->Count)
        {
          cm->TabNb = tmp;
          b->RemoveBack ();
        }
        else
          bt.Add (tmp + " is not an tab number.");
      }
      else
        bt.Add ("Bad argument.");
    }

    return bt;
  }

  BufferType          ChatCommand::SwitchChan (UInt32* channb,
    BufferType* b,
    ChatManagerType* cm,
    ChatDisplayer* cd)
  {
    BufferType bt;

    if (b->Count() > 2)
      bt.Add ("Too much argument.");
    if (b->Count() == 2)
    {
      String chanNb = (*b)[1];

      if (StringFilter::IsNumeric (chanNb))
      {
        std::istringstream buf (chanNb);
        UInt32 tmp = 0;
        buf >> tmp;
        if (tmp >= 0 && tmp < cd->GetChanNb ())
        {
          (*channb) = 0;
          cm->ChanNb = tmp;
          b->RemoveBack ();
        }
        else
          bt.Add (tmp + " is not an chan number.");
      }
      else
        bt.Add ("Bad argument.");
    }

    return bt;
  }

  BufferType          ChatCommand::AddChan (UInt32* channb,
    BufferType* b,
    ChatManagerType* cm,
    ChatDisplayer* cd)
  {
    BufferType bt;

    if (b->Count() > 2)
      bt.Add ("Too much argument.");
    if (b->Count() == 2)
    {
      String chanNb = (*b)[1];

      if (StringFilter::IsNumeric (chanNb))
      {
        std::istringstream buf (chanNb);
        UInt32 tmp = 0;
        buf >> tmp;
        if (tmp >= 0 && tmp < cd->GetChanNb())
        {
          cd->AddChan (tmp);
          b->RemoveBack ();
        }
        else
          bt.Add (tmp + " is not an chan number.");
      }
      else
        bt.Add ("Bad argument.");
    }

    return bt;
  }


  BufferType          ChatCommand::RmChan (UInt32* channb,
    BufferType* b,
    ChatManagerType* cm,
    ChatDisplayer* cd)
  {
    BufferType bt;

    if (b->Count() > 2)
      bt.Add ("Too much argument.");
    if (b->Count() == 2)
    {
      String chanNb = (*b)[1];

      if (StringFilter::IsNumeric (chanNb))
      {
        std::istringstream buf (chanNb);
        UInt32 tmp = 0;
        buf >> tmp;
        if (tmp >= 0 && tmp < cd->GetChanNb())
        {
          cd->RmChan (tmp);
          b->RemoveBack ();
        }
        else
          bt.Add (tmp + " is not an chan number.");
      }
      else
        bt.Add ("Bad argument.");
    }

    return bt;
  }

  ResponseType			  ChatCommand::ExecCmd (ChatManagerType* cm)
  {
    BufferType bt;

    cm->Request.Add (StringHelper::ToString (cm->ChanNb));

    DisplayType response (
      cm->Request.IsEmpty () ?
      MyPair (false, NBTOTCMDS + 1, 0, bt) :
      (this->*command_) (cm->Request));

    ChatDisplayer* cd = cm->Cd[cm->TabNb];

    if (response.first.first)
      bt = (this->*(tab_[response.first.second].PtrFuncloc))
      (&response.second.first, &response.second.second, cm, cd);
    if (bt.Count () == 0)
    {
      for (UInt32 i = 0; i < cm->Count; i++)
        cm->Cd[i]->AddToChan (response.second.first, response.second.second);

      // Switch Tab detected.
      if (response.first.second == 0)
      {
        SetCommand (&ChatCommand::Unknown);
        return cm->Cd[cm->TabNb]->DisplayTab (cm->Cd[0]);
      }
    }
    else
      cd->AddToChan (0, bt);
    SetCommand (&ChatCommand::Unknown);
    return cd->Display ();
  }
} // namespace yap
