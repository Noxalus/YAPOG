#include "YAPOG/Game/Chat/Chat.hpp"

namespace yap
{
  Chat::Chat ()
    : chatmanager_ (new ChatManager ())
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
      history_.Add (entry_);
    else
      history_[offset_++] = entry_;

    if (offset_ == HISTORYMAX)
      offset_ = 0;
    index_ = offset_;
  }

  ChatManagerType*	      Chat::Parse ()
  {
    ChatCommand cc;

    if (buffer_.Count () == 0)
    {
      chatmanager_->RequestCmd = cc.GetCmd ("echo");
      chatmanager_->Request.Add (entry_);
      IncOff ();
      return chatmanager_;
    }
    /* Test Up arrow history */
    if (Check () && 
        StringHelper::CompareString (buffer_[0], String ("/up")) == 0)
    {
      chatmanager_->RequestCmd = cc.GetCmd ("echo");
      chatmanager_->Request.Add ("UP : '" + GetUpHistory() + "'");
      std::cout << "index " << index_ << std::endl;

      return chatmanager_;
    }
    /* End Test */

    IncOff ();

    /* Test History */
    if (Check () &&
        StringHelper::CompareString (buffer_[0], String ("/history")) == 0)
    {
      chatmanager_->RequestCmd = cc.GetCmd ("echo");
      chatmanager_->Request.Add (GetStringHistory ());

      return chatmanager_;
    }
    /* End TEST */

    if (Check())
    {
      chatmanager_->RequestCmd = cc.GetCmd(buffer_[0].substr(1).c_str());
      chatmanager_->Request = buffer_;
    }
    else
    {
      chatmanager_->RequestCmd = cc.GetCmd("echo");
      chatmanager_->Request.Add(entry_);
    }
    // Send the request

    return chatmanager_;
  }

  bool                    Chat::Exec (ChatDisplayer& display)
  {
    bool  toret = false;
    ChatCommand cc;

    String test = cc.ExecCmd (&display, chatmanager_);

    return toret;
  }

  String                  Chat::GetUpHistory ()
  {
    if ((index_-- - 1) < 0)
    {
      index_ = history_.Count();
      if (index_ > 0)
        return (history_[--index_]);
      else
        return "";
    }

    return history_[index_];
  }

  String                  Chat::GetDownHistory ()
  {
    if ((index_++ + 1) > history_.Count ())
    {
      index_ = history_.Count ();
      if (index_ > 0)
        return (history_[index_++]);
      else
        return "";
    }

    return history_[index_];
  }

  String                  Chat::GetStringHistory ()
  {
    String stringtosend = "";
    stringtosend += "History :\r\n";
    for (size_t i = 0; i < history_.Count() - 1; i++)
      stringtosend += history_[i] + "\r\n";
    stringtosend += history_[history_.Count() - 1];
    return stringtosend;
  }

  BufferType              Chat::GetBufHistory ()
  {
    BufferType bufftosend;
    std::cout << history_.Count() << std::endl;
    bufftosend.Add("History :\r\n");
    for (size_t i = 0; i < history_.Count() - 1; i++)
      bufftosend.Add(history_[i] + "\r\n");
    bufftosend.Add(history_[history_.Count() - 1]);
    return bufftosend;
  }

  BufferType              Chat::GetHistory ()
  {
    return history_;
  }

  bool								    Chat::Check ()
  {
    return (buffer_.Count() > 0 && entry_[0] == '/');
  }
} // namespace yap
