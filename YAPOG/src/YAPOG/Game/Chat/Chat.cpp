#include "YAPOG/Game/Chat/Chat.hpp"

namespace yap
{
  Chat::Chat()
  {
    entry_ = "";
    index_ = 0;
    offset_ = 0;
    chatmanager_ = new ChatManager();
  }

  Chat::Chat(String b)
  {
    SetBuf(b);
    index_ = 0;
    offset_ = 0;
    chatmanager_ = new ChatManager();
  }

  Chat::~Chat ()
  {
  }

  void								    Chat::SetBuf(String b)
  {
    BufferType* tmp = new BufferType;
    entry_ = b;
    String w;
    std::stringstream ss(entry_);

    while(ss >> w)
      tmp->Add(w);

    buffer_ = *tmp;
  }

  bool                    Chat::ChangeChan(ChatDisplayer& displayer)
  {
    if (buffer_.Count() > 0 && Check())
    {
      String cmd = buffer_[0].substr(1);

      if (StringHelper::CompareString(cmd, String ("ChangeChan")) == 0)
      {
        if (buffer_.Count() == 1)
          entry_ = "Chan number is missing.";
        if (buffer_.Count() > 2)
          entry_ = "Too much argument.";
        if (buffer_.Count() == 2)
        {
          String chanNb = buffer_[1];

          if (StringFilter::IsNumeric(chanNb))
          {
            std::istringstream buf(chanNb);
            UInt32 tmp = 0;
            buf >> tmp;
            if (tmp >= 0 && tmp < displayer.GetChanNb())
            {
              chatmanager_->ChanNb = tmp;
              std::cout << "Channel changed to channel number : "
                        << chatmanager_->ChanNb << std::endl;
              return true;
            }
            else
              entry_ = tmp + " is not an chan number.";
          }
          else
            entry_ = "Bad argument.";
        }
      }
      else
      {
        String chanNb = cmd;
          
        if (StringFilter::IsNumeric(chanNb))
        {
          std::istringstream buf(chanNb);
          UInt32 tmp = 0;
          buf >> tmp;
          if (tmp >= 0 && tmp < displayer.GetChanNb())
          {
            chatmanager_->ChanNb = tmp;
            std::cout << "Channel changed to channel number : "
                      << chatmanager_->ChanNb << std::endl;
            entry_ = entry_.substr(2 + chanNb.size());
            SetBuf(entry_);
          }
          else
            entry_ = tmp + " is not an chan number.";
        }
      }
    }
    return false;
  }

  void                    Chat::IncOff()
  {
    if (history_.Count() < HISTORYMAX)
      history_.Add(entry_);
    else
      history_[offset_++] = entry_;
    offset_ = offset_ == HISTORYMAX ? 0 : offset_;
    index_ = offset_;
  }

  ChatManagerType*	      Chat::Parse()
  {
    ChatCommand cc;

    if (buffer_.Count() == 0)
    {
      chatmanager_->RequestCmd = cc.GetCmd("echo");
      chatmanager_->Request.Add(entry_);
      IncOff();
      return chatmanager_;
    }
    /* Test Up arrow history */
    if (Check() && StringHelper::CompareString(buffer_[0], String ("/up")) == 0)
    {
      chatmanager_->RequestCmd = cc.GetCmd("echo");
      chatmanager_->Request.Add("UP : '" + GetUpHistory() + "'");
      std::cout << "index " << index_ << std::endl;

      return chatmanager_;
    }
    /* End Test */
    
    IncOff();

    /* Test History */
    if (Check() && StringHelper::CompareString(buffer_[0], String ("/history")) == 0)
    {
      chatmanager_->RequestCmd = cc.GetCmd("echo");
      chatmanager_->Request.Add(GetStringHistory());

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

  String                  Chat::GetUpHistory()
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

  String                  Chat::GetStringHistory()
  {
    String stringtosend = "";
    stringtosend += "History :\r\n";
    for (size_t i = 0; i < history_.Count() - 1; i++)
      stringtosend += history_[i] + "\r\n";
    stringtosend += history_[history_.Count() - 1];
    return stringtosend;
  }

  BufferType              Chat::GetBufHistory()
  {
    BufferType bufftosend;
    std::cout << history_.Count() << std::endl;
    bufftosend.Add("History :\r\n");
    for (size_t i = 0; i < history_.Count() - 1; i++)
      bufftosend.Add(history_[i] + "\r\n");
    bufftosend.Add(history_[history_.Count() - 1]);
    return bufftosend;
  }

  BufferType              Chat::GetHistory()
  {
    return history_;
  }

  bool								    Chat::Check()
  {
    return (buffer_.Count() > 0 && entry_[0] == '/');
  }
} // namespace yap
