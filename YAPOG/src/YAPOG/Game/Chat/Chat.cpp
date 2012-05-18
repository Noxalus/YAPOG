#include "YAPOG/Game/Chat/Chat.hpp"
#include "YAPOG/Game/Chat/ChatCommand.hpp"

namespace yap
{
	Chat::Chat()
	{
		entry_ = "";
	}
	
	Chat::Chat(std::string b)
	{
		SetBuf(b);
	}

	Chat::t_buffer						Chat::GetBuf()
	{
		return buffer_;
	}

	void								Chat::SetBuf(std::string b)
	{
		entry_ = b;
		std::string w;
		std::stringstream ss(b);
		yap::String word = "";

		while(ss >> w)
		{
			buffer_.push_back(w);
		}
	}

	Chat::sCM							Chat::Parse()
	{
		sCM ret;
		ChatCommand cc;

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

		// Send the request
		return ret;
	}

	bool								Chat::Check()
	{
		return (buffer_.size() > 0 && buffer_.at(0)[0] == '/');
	}
} // namespace yap
