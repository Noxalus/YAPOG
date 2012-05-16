#include "YAPOG/Game/Chat/Chat.hpp"

namespace yap
{
	Chat::Chat()
	{
		entry_ = "";
	}

	yap::String							Chat::help(yap::String s)
	{
		yap::String ret = "";
		std::string nl = "\r\n";


		ret = "Command list: " + nl
			+ "/help\t\t: to display command list" + nl
			+ "/trade x\t: to trade with the player x";

		return ret;
	}

	yap::String							Chat::unknown(yap::String s)
	{
		return "Unknown command";
	}

	yap::String							Chat::trade(yap::String name)
	{
		return ("you wanna trade with " + name);
	}

	Chat::E_Cmds						Chat::getCmd (const char *pString)
	{
		struct
		{
			E_Cmds   m_key;
			yap::String  m_pString;
		}

		tab[] = 
		{
			{c_Help, "help"},
			{c_Trade, "trade"},
		};

		yap::String s(pString);

		for (size_t i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
		{
			if (0 == yap::StringHelper::compare_string(s, tab[i].m_pString))
				return tab [i].m_key;
		}

		return c_Unknown;
	}

	yap::String						Chat::execcmd()
	{
		yap::String ret = "";

		if (buffer_.at(0).size() < 1)
			ret = unknown();
		else
		{
			switch (getCmd(buffer_.at(0).substr(1).c_str()))
			{
			case c_Help:
				ret = help();
				break;
			case c_Trade:
				if (buffer_.size() == 2)
					ret = trade(buffer_.at(1));
				else
					ret = "A player's name is missing.";
				break;
			default:
				ret = unknown();
				break;
			}
		}

		return ret;
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
		Chat::s_CM ret;

		if (check())
		{
			ret.cmd = 1;
			ret.request_cmd = getCmd();
		}
		else
		{
			ret.cmd = 0;
			ret.request = entry_;
		}

		// Send the request
		return ret;
	}

	bool								Chat::check()
	{
		if (buffer_.size() > 0)
		{
			if (buffer_.at(0)[0] == '/')
				return true;
		}

		return false;
	}
} // namespace yap
