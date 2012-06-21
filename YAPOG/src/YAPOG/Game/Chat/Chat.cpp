#include "YAPOG/Game/Chat/Chat.hpp"

namespace yap
{
  Chat::Chat ()
    : chatmanager_ (new ChatManager ())
    , chatcommand_ (new ChatCommand ())
    , offset_ (0)
    , index_ (0)
    , chan_ (0)
    , entry_ ("")
    , output_ ("")
    , buffer_ ()
    , history_ ()
    , isCommand_ (false)
  {
  }

  Chat::Chat (String b)
    : chatmanager_ (new ChatManager ())
    , chatcommand_ (new ChatCommand ())
    , offset_ (0)
    , index_ (0)
    , chan_ (0)
    , entry_ ("")
    , output_ ("")
    , buffer_ ()
    , history_ (*(new BufferType ()))
    , isCommand_ (false)
  {
    SetBuf (b);
  }

  Chat::~Chat ()
  {
    delete (chatmanager_);
    chatmanager_ = nullptr;
    delete (chatcommand_);
    chatcommand_ = nullptr;
  }

  void								      Chat::SetBuf (String b)
  {
    BufferType* tmp = new BufferType;
    entry_ = b;
    String w;
    std::stringstream ss (entry_);

    while (ss >> w)
      tmp->Add (w);

    buffer_ = *tmp;
  }

  void                      Chat::IncOff ()
  {
    if (history_.Count () < HISTORYMAX)
    {
      history_.Add (entry_);
      offset_++;
    }
    else
      history_[offset_++] = entry_;

    if (offset_ == HISTORYMAX)
      offset_ = 0;
    index_ = offset_;
  }

  void                      Chat::ToEcho (String s)
  {
    chatcommand_->SetCommand (&ChatCommand::Echo);
    chatmanager_->Request.Add (s);
  }

  std::pair<bool, String>   Chat::TestHistoryChecker ()
  {
    if (isCommand_ && 
        StringHelper::CompareString (buffer_[0], String ("/up")) == 0)
      return GetUpHistory ();
    if (isCommand_ && 
        StringHelper::CompareString (buffer_[0], String ("/down")) == 0)
      return GetDownHistory ();

    return std::make_pair (false, "");
  }

  String                    Chat::Parse ()
  {
    chatmanager_->Request.Clear ();
    std::pair<bool, String> upOrDown = TestHistoryChecker ();

    if (buffer_.IsEmpty ())
    {
      ToEcho (entry_);
      return "";
    }

    if (upOrDown.first)
      return upOrDown.second;

    IncOff ();

    Check ();
    if (isCommand_ &&
        StringHelper::CompareString (buffer_[0], String ("/history")) == 0)
      return GetStringHistory ();

    if (isCommand_)
    {
      chatcommand_->SetCommand (
        chatcommand_->GetCmd (buffer_[0].substr (1).c_str ()));
      chatmanager_->Request = buffer_;
    }
    else
      ToEcho (entry_);
    return "";
  }

  ResponseType              Chat::Exec ()
  {
    return chatcommand_->ExecCmd (chatmanager_);
  }

  std::pair<bool, String>   Chat::GetUpHistory ()
  {
    UInt32 size = history_.Count ();

    if (size == 0)
      return std::make_pair (true, "");
    if (--index_ >= size)
      index_ = size - 1;
 
    return std::make_pair (true, (index_ >= 0) ? history_[index_] : "");
  }

  std::pair<bool, String>   Chat::GetDownHistory ()
  {
    UInt32 size = history_.Count ();

    if (size == 0)
      return std::make_pair (true, "");
    if (++index_ >= size)
      index_ = 0;

    return std::make_pair (true, (index_ < size) ? history_[index_] : "");
  }

  String                    Chat::GetStringHistory ()
  {
    String stringtosend = "";

    stringtosend += "History :\r\n";
    for (size_t i = 0; i < history_.Count () - 1; i++)
      stringtosend += history_[i] + "\r\n";
    stringtosend += history_[history_.Count () - 1];

    return stringtosend;
  }

  BufferType                Chat::GetBufHistory ()
  {
    BufferType bufftosend;

    std::cout << history_.Count () << std::endl;
    bufftosend.Add("History :\r\n");
    for (size_t i = 0; i < history_.Count () - 1; i++)
      bufftosend.Add(history_[i] + "\r\n");
    bufftosend.Add(history_[history_.Count () - 1]);

    return bufftosend;
  }

  String                    Chat::GetTabName (UInt32 TabNb)
  {
    return chatmanager_->Cd[TabNb]->GetName ();
  }

  UInt32                    Chat::GetTabCount ()
  {
    return chatmanager_->Cd.Count ();
  }
  
  UInt32                    Chat::GetTabNb ()
  {
    return chatmanager_->TabNb;
  }

  BufferType                Chat::GetHistory ()
  {
    return history_;
  }

  bool                      Chat::GetIsCommand ()
  {
    return isCommand_;
  }

  void								      Chat::Check ()
  {
    isCommand_ = (buffer_.Count () > 0 && entry_[0] == '/');
  }
} // namespace yap
