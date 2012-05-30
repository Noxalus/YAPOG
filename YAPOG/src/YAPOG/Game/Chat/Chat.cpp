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
  {
    SetBuf (b);
  }

  Chat::~Chat ()
  {
    delete (chatmanager_);
  }

  void								    Chat::SetBuf (String b)
  {
    BufferType* tmp = new BufferType;
    entry_ = b;
    String w;
    std::stringstream ss (entry_);

    while (ss >> w)
      tmp->Add (w);

    buffer_ = *tmp;
  }

  void                    Chat::IncOff ()
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

  void                    Chat::ToEcho (String s)
  {
    chatcommand_->SetCommand (&ChatCommand::Echo);
    chatmanager_->Request.Add (s);
  }

  bool                    Chat::TestHistoryChecker ()
  {
    if (Check () && 
        StringHelper::CompareString (buffer_[0], String ("/up")) == 0)
    {
      std::cout << "UP : '" << GetUpHistory () << "'" << std::endl;
      std::cout << "index " << index_ << std::endl;

      return true;
    }
    if (Check () && 
        StringHelper::CompareString (buffer_[0], String ("/down")) == 0)
    {
      std::cout << "DOWN : '" << GetDownHistory () << "'" << std::endl;
      std::cout << "index " << index_ << std::endl;

      return true;
    }

    return false;
  }

  void            	      Chat::Parse ()
  {
    if (buffer_.IsEmpty ())
    {
      ToEcho (entry_);
      return;
    }

    /* Test Arrow history */
    if (TestHistoryChecker ())
      return;
    /* End Test */

    IncOff ();

    /* Test History */
    if (Check () &&
        StringHelper::CompareString (buffer_[0], String ("/history")) == 0)
    {
      std::cout << GetStringHistory () << std::endl;
      return;
    }
    /* End TEST */

    if (Check ())
    {
      chatcommand_->SetCommand (
        chatcommand_->GetCmd (buffer_[0].substr (1).c_str ()));
      chatmanager_->Request = buffer_;
    }
    else
      ToEcho (entry_);
  }

  void                    Chat::Exec (ChatDisplayer& display)
  {
    for (UInt32 i = 0; i < 6; i++)
      display.AddChan (i);

    chatcommand_->ExecCmd (&display, chatmanager_);
  }

  String                  Chat::GetUpHistory ()
  {
    if ((index_-- - 1) < 0)
    {
      index_ = history_.Count ();
      if (history_.Count () > 0)
        return (history_[--index_]);
      else
        return "";
    }

    return history_[index_];
  }

  String                  Chat::GetDownHistory ()
  {
    UInt32 size = history_.Count ();

    if (size == 0)
      return "";
    if (++index_ >= size)
      index_ = 0;
    return history_[index_];
  }

  String                  Chat::GetStringHistory ()
  {
    String stringtosend = "";

    stringtosend += "History :\r\n";
    for (size_t i = 0; i < history_.Count () - 1; i++)
      stringtosend += history_[i] + "\r\n";
    stringtosend += history_[history_.Count () - 1];

    return stringtosend;
  }

  BufferType              Chat::GetBufHistory ()
  {
    BufferType bufftosend;

    std::cout << history_.Count () << std::endl;
    bufftosend.Add("History :\r\n");
    for (size_t i = 0; i < history_.Count () - 1; i++)
      bufftosend.Add(history_[i] + "\r\n");
    bufftosend.Add(history_[history_.Count () - 1]);

    return bufftosend;
  }

  BufferType              Chat::GetHistory ()
  {
    return history_;
  }

  bool								    Chat::Check ()
  {
    return (buffer_.Count () > 0 && entry_[0] == '/');
  }
} // namespace yap
