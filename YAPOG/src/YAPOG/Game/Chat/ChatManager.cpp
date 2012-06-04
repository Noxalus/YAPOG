#include "YAPOG/Game/Chat/ChatCommand.hpp"
#include "YAPOG/Game/Chat/ChatManager.hpp"

namespace yap
{
  bool          CheckBoolTab (String str)
  {
    if (str.length () != NBCHAN)
      return false;
    for (size_t i = 0; i < str.length (); i++)
      if (!(str[i] == '0' || str[i] == '1'))
        return false;
    return true;
  }

  bool*         StrToBoolTab (String str)
  {
    bool* tabbool = new bool[NBCHAN];

    for (size_t i = 0; i < str.length (); i++)
      tabbool[i] = (str[i] == '0' ? 0 : 1);

    return tabbool;
  }

  ChatManager::ChatManager ()
    : Local (false)
    , ChanNb (DEFAULTCHAN)
    , Request ()
    , TabNb (DEFAULTTAB)
    , Count (4)
    , Cd ()
  {
    String file =
      boost::filesystem::current_path ().string () + "/chat.conf";
    boost::filesystem::path path (file);
    if (!boost::filesystem::exists (path))
    {
      Cd.Add (new ChatDisplayer ("System", StringHelper::Parse<UInt32> ("0")));
      Cd.Add (new ChatDisplayer ("Global", StringHelper::Parse<UInt32> ("1")));
      Cd.Add (new ChatDisplayer ("Group", StringHelper::Parse<UInt32> ("2")));
      Cd.Add (new ChatDisplayer ("Business", StringHelper::Parse<UInt32> ("3")));
    }
    else
    {
      std::ifstream f;
      String line = "";
      bool parse = false;
      f.open (path.string ());
      while (f.good ())
      {
        std::getline (f, line);
        if (line.compare ("</chat>") == 0)
          parse = false;
        if (parse)
        {
          BufferType bt;
          StringHelper::Split (line, " ", bt);
          if (bt.Count () != 2 || !CheckBoolTab (bt[1]))
            continue;
          bool *tabtoadd = StrToBoolTab (bt[1]);
          Cd.Add (new ChatDisplayer (bt[0], tabtoadd));
        }
        if (line.compare ("<chat>") == 0)
          parse = true;
      }
      f.close ();
    }
  }

  ChatManager::~ChatManager ()
  {
    ChatDisplayerType::ItType it (Cd.Begin ());
    ChatDisplayerType::ItType ite (Cd.End ());

    for (; it < ite; it++)
    {
      delete (*it);
      *it = nullptr;
    }
  }

} // namespace yap