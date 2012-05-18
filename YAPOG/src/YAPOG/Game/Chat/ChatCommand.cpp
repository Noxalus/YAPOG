#include "YAPOG/Game/Chat/ChatCommand.hpp"
#include "YAPOG/Game/Chat/Chat.hpp"

namespace yap
{
	ChatCommand::ChatCommand()
	{
		sMC tabs [] =
		{
			{c_Help, "help"},
			{c_Trade, "trade"},
			{c_Echo, "echo"}
		};

		for (unsigned i = 0; i < NBCMDS; i++)
			tab_[i] = tabs[i];
	}

	yap::String							ChatCommand::Help(ChatCommand::t_buffer s)
	{
		yap::String ret = "";
		std::string nl = "\r\n";


		ret = "Command list: " + nl
			+ "/help\t\t: to display command list" + nl
			+ "/trade x\t: to trade with the player x";

		return ret;
	}

	yap::String							ChatCommand::Echo(ChatCommand::t_buffer b)
	{
		yap::String str = "";
    unsigned i = 0;

    if (b.at(i).compare("/echo") == 0)
      i++;

		if (b.size() > 0)
			str += b[i++];
		for (; i < b.size(); i++)
			str += " " + b[i];

		return str;
	}

	yap::String							ChatCommand::Unknown(ChatCommand::t_buffer s)
	{
		return ("Command " + s.at(0).substr(1) + " not exist.");
	}

	yap::String							ChatCommand::Trade(ChatCommand::t_buffer name)
	{
		if (name.size() > 2)
			return ("Unable to trade with so much people!!");
		if (name.size() < 2)
			return ("Unable to trade with nobody...");
		return ("Trying to trade with " + name.at(1) + ".");
	}

	ChatCommand::func					ChatCommand::GetCmd (const char *pString)
	{
		yap::String s(pString);
		eCmds c = c_Unknown;

		for (unsigned i = 0; i < NBCMDS; i++)
		{
			if (tab_[i].m_ptS.compare(pString) == 0)
			{
				c = tab_[i].m_Key;
				break;
			}
		}

		switch (c)
		{
		case yap::OPTChat::c_Help: return &ChatCommand::Help;
		case yap::OPTChat::c_Trade: return &ChatCommand::Trade;
		case yap::OPTChat::c_Echo: return &ChatCommand::Echo;
		default: return &ChatCommand::Unknown;
		}
	}

	yap::String						ChatCommand::ExecCmd(t_buffer b, sCM c)
	{
		return (this->*c.request_cmd)(b);
	}
} // namespace yap
