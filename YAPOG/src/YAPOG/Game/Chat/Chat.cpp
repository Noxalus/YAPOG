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
		setbuf(b);
	}

	Chat::t_buffer						Chat::getbuf()
	{
		return buffer_;
	}

	void								Chat::setbuf(std::string b)
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

	Chat::s_CM							Chat::parse()
	{
		s_CM ret;
		ChatCommand cc;

		if (check() && buffer_.at(0).size() > 2)
		{
			ret.request_cmd = cc.getCmd(buffer_.at(0).substr(1).c_str());
			if (buffer_.size() > 1)
				ret.request = buffer_;
		}
		else
		{
			ret.request_cmd = cc.getCmd("echo");
			ret.request = buffer_;
		}

		// Send the request
		return ret;
	}

	bool								Chat::check()
	{
		return (buffer_.size() > 0 && buffer_.at(0)[0] == '/');
	}
} // namespace yap
