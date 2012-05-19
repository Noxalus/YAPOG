#include "YAPOG/Game/Chat/Chat.hpp"
#include "YAPOG/Game/Chat/ChatCommand.hpp"

namespace yap
{
  Chat::Chat()
  {
    entry_ = "";
    index_ = 0;
    offset_ = 0;
  }

  Chat::Chat(String b)
  {
    SetBuf(b);
    index_ = 0;
    offset_ = 0;
  }

  Chat::~Chat ()
  {
  }

  Chat::BufferType			Chat::GetBuf()
  {
    return buffer_;
  }

  void								  Chat::SetBuf(String b)
  {
    entry_ = StringHelper::Trim(b);
    BufferType* tmp = new BufferType;
    String w;
    std::stringstream ss(entry_);

    while(ss >> w)
      tmp->Add(w);

    buffer_ = *tmp;
  }

  Chat::ChatManagerType	Chat::Parse()
  {
    ChatManagerType ret;
    ChatCommand cc;

    if (entry_.size() > 0)
    {
      /* Test Up arrow history */
      if (buffer_[0].compare("/up") == 0)
      {
        BufferType bufftosend;
        ret.Request_cmd = cc.GetCmd("echo");
        bufftosend.Add("UP : '" + GetUpHistory() + "'");
        ret.Request = bufftosend;
        std::cout << "index " << index_ << std::endl;
        return ret;
      }
      /* End Test */

      if (history_.Count() < HISTORYMAX)
        history_.Add(entry_);
      else
        history_[offset_++] = entry_;
      offset_ = offset_ == HISTORYMAX ? 0 : offset_;
      index_ = offset_;

      /* Test History */
      if (buffer_[0].compare("/history") == 0)
      {
        ret.Request_cmd = cc.GetCmd("echo");
        ret.Request = GetBufHistory();
        return ret;
      }
      /* End TEST */

      if (Check())
      {
        ret.Request_cmd = cc.GetCmd(buffer_[0].substr(1).c_str());
        if (buffer_.Count() > 1)
          ret.Request = buffer_;
      }
      else
      {
        ret.Request_cmd = cc.GetCmd("echo");
        ret.Request = buffer_;
      }
      // Send the request
      return ret;
    }
    else
    {
      ret.Request_cmd = cc.GetCmd("echo");
      ret.Request = *(new BufferType);
    }

    return ret;
  }

  String                Chat::GetUpHistory()
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

  Chat::BufferType      Chat::GetBufHistory()
  {
    BufferType bufftosend;
    bufftosend.Add("History :\r\n");
    for (size_t i = 0; i < history_.Count() - 1; i++)
      bufftosend.Add(history_[i] + "\r\n");
    bufftosend.Add(history_[history_.Count() - 1]);
    return bufftosend;
  }

  Chat::VStringType     Chat::GetHistory()
  {
    return history_;
  }

  bool								  Chat::Check()
  {
    return (buffer_.Count() > 0 && buffer_[0][0] == '/');
  }
} // namespace yap
