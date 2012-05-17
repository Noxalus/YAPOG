#include "YAPOG/Game/Chat/ChatCommand.hpp"
#include "YAPOG/Game/Chat/Chat.hpp"

namespace yap
{
	ChatCommand::ChatCommand()
	{
		s_MC tabs [] =
		{
			{c_Help, "help"},
			{c_Trade, "trade"},
			{c_Echo, "echo"}
		};

		for (unsigned i = 0; i < NBCMDS; i++)
			tab[i] = tabs[i];
	}

	yap::String							ChatCommand::help(ChatCommand::t_buffer s)
	{
		yap::String ret = "";
		std::string nl = "\r\n";


		ret = "Command list: " + nl
			+ "/help\t\t: to display command list" + nl
			+ "/trade x\t: to trade with the player x";

		return ret;
	}

	yap::String							ChatCommand::echo(ChatCommand::t_buffer b)
	{
		yap::String str = "";

		if (b.size() > 0)
			str += b[0];
		for (unsigned i = 1; i < b.size(); i++)
			str += " " + b[i];

		return str;
	}

	yap::String							ChatCommand::unknown(ChatCommand::t_buffer s)
	{
		return ("Command " + s.at(0).substr(1) + " not exist.");
	}

	yap::String							ChatCommand::trade(ChatCommand::t_buffer name)
	{
		if (name.size() > 2)
			return ("Unable to trade with so much people!!");
		if (name.size() < 2)
			return ("Unable to trade with nobody...");
		return ("Trying to trade with " + name.at(1) + ".");
	}

	ChatCommand::func					ChatCommand::getCmd (const char *pString)
	{
		yap::String s(pString);
		e_Cmds c = c_Unknown;

		for (unsigned i = 0; i < NBCMDS; i++)
		{
			if (tab[i].m_ptS.compare(pString) == 0)
			{
				c = tab[i].m_Key;
				break;
			}
		}

		switch (c)
		{
		case yap::OPTChat::c_Help: return &ChatCommand::help;
		case yap::OPTChat::c_Trade: return &ChatCommand::trade;
		case yap::OPTChat::c_Echo: return &ChatCommand::echo;
		default: return &ChatCommand::unknown;
		}
	}

	yap::String						ChatCommand::execcmd(t_buffer b, s_CM c)
	{
		return (this->*c.request_cmd)(b);
	}
} // namespace yap
