#include "YAPOG/Game/Chat/OPTChat.hpp"
#include "YAPOG/Game/Chat/Chat.hpp"
#include "YAPOG/Game/Chat/ChatDisplayer.hpp"

int main()
{
	yap::ChatDisplayer displayer;
	std::string line;
	yap::Chat mychat;
	while (true)
	{
		std::getline(std::cin, line);
		if (line.compare("exit") == 0)
			break;
    mychat.SetBuf(line);
		displayer.Display(mychat.GetBuf(), mychat.Parse());
	}

	return EXIT_SUCCESS;
}