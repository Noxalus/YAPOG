#include "YAPOG/Game/Chat/ChatCommand.hpp"
#include "YAPOG/Game/Chat/Chat.hpp"

namespace yap
{
	ChatCommand::ChatCommand()
	{
		sMC tabs [] =
		{
			{MyCmds::c_Help, "help"},
			{MyCmds::c_Trade, "trade"},
			{MyCmds::c_Echo, "echo"}
		};

		for (unsigned i = 0; i < NBCMDS; i++)
			tab_[i] = tabs[i];
	}

	String							ChatCommand::Help(ChatCommand::BufferType s)
	{
		String ret = "";
		String nl = "\r\n";


		ret = "Command list: " + nl
			+ "/help\t\t: to display command list" + nl
			+ "/trade x\t: to trade with the player x";

		return ret;
	}

	String							ChatCommand::Echo(ChatCommand::BufferType b)
	{
		String str = "";
    UInt32 i = 0;

    if (b[i].compare("/echo") == 0)
      i++;

		if (b.Count() > 0)
			str += b[i++];
		for (; i < b.Count(); i++)
			str += " " + b[i];

		return str;
	}

	String							ChatCommand::Unknown(ChatCommand::BufferType s)
	{
		return ("Command " + s[0].substr(1) + " not exist.");
	}

	String							ChatCommand::Trade(ChatCommand::BufferType name)
	{
		if (name.Count() > 2)
			return ("Unable to trade with so much people!!");
		if (name.Count() < 2)
			return ("Unable to trade with nobody...");
		return ("Trying to trade with " + name[1] + ".");
	}

	ChatCommand::func					ChatCommand::GetCmd (const char *pString)
	{
		String s(pString);
		MyCmds c = MyCmds::c_Unknown;

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
    case yap::OPTChat::MyCmds::c_Help: return &ChatCommand::Help;
    case yap::OPTChat::MyCmds::c_Trade: return &ChatCommand::Trade;
		case yap::OPTChat::MyCmds::c_Echo: return &ChatCommand::Echo;
		default: return &ChatCommand::Unknown;
		}
	}

	String						ChatCommand::ExecCmd(BufferType b, ChatManagerType c)
	{
    return (this->*c.Request_cmd)(c.Request);
	}
} // namespace yap
