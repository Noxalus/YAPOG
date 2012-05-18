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
	
	Chat::Chat(std::string b)
	{
		SetBuf(b);
    index_ = 0;
    offset_ = 0;
	}

  Chat::~Chat ()
  {
  }

	Chat::t_buffer						Chat::GetBuf()
	{
		return buffer_;
	}

	void								Chat::SetBuf(std::string b)
	{
		entry_ = b;
    t_buffer tmp;
		std::string w;
		std::stringstream ss(b);
		yap::String word = "";

		while(ss >> w)
			tmp.push_back(w);

    buffer_ = tmp;
	}

  void                  Chat::IncOff()
  {
    offset_++;
    if (offset_ == HISTORYMAX)
      offset_ = 0;
  }

	Chat::sCM							Chat::Parse()
	{
		sCM ret;
		ChatCommand cc;
    
    /* Test Up arrow history */
    if (buffer_.at(0).compare("/up") == 0)
    {
      t_buffer bufftosend;
			ret.request_cmd = cc.GetCmd("echo");
      bufftosend.push_back("UP : '" + GetUpHistory() + "'");
      ret.request = bufftosend;
      std::cout << "index " << index_ << std::endl;
      return ret;
    }
    /* End Test */
    
    if (history_.size() < HISTORYMAX)
      history_.push_back(entry_);
    else
      history_[offset_] = entry_;
    IncOff();
    
    /* Test History */
    if (buffer_.at(0).compare("/history") == 0)
    {
			ret.request_cmd = cc.GetCmd("echo");
      ret.request = GetBufHistory();
      return ret;
    }
    /* End TEST */

		if (Check() && buffer_.at(0).size() > 2)
		{
			ret.request_cmd = cc.GetCmd(buffer_.at(0).substr(1).c_str());
			if (buffer_.size() > 1)
				ret.request = buffer_;
		}
		else
		{
			ret.request_cmd = cc.GetCmd("echo");
			ret.request = buffer_;
		}
    index_ = offset_;

		// Send the request
		return ret;
	}

  yap::String         Chat::GetUpHistory()
  {
    if ((index_-- - 1) < 0)
    {
      if (offset_ > 0)
      {
        index_ = offset_;
        return (history_[--index_]);
      }
      else
      {
        index_ = 0;
        return "";
      }
    }

    return history_[index_];
  }
  
  Chat::t_buffer      Chat::GetBufHistory()
  {
    t_buffer bufftosend;
    bufftosend.push_back("History :\r\n");
    for (size_t i = 0; i < history_.size() - 1; i++)
      bufftosend.push_back(history_[i] + "\r\n");
    bufftosend.push_back(history_[offset_ - 1]);
    return bufftosend;
  }

  Chat::t_vs          Chat::GetHistory()
  {
    return history_;
  }

	bool								Chat::Check()
	{
		return (buffer_.size() > 0 && buffer_.at(0)[0] == '/');
	}
} // namespace yap
