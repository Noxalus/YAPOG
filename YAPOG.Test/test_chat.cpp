#include "YAPOG/Game/Chat/ChatHeader.hpp"
#include "YAPOG/Game/Chat/Chat.hpp"
#include "YAPOG/Game/Chat/ChatDisplayer.hpp"

int main()
{
	yap::ChatDisplayer displayer;
	std::string line = "";
	yap::Chat mychat;
	while (true)
	{
    while (line.compare("") == 0)
		  std::getline(std::cin, line);
		if (line.compare("exit") == 0)
			break;
    mychat.SetBuf(line);
    mychat.Parse();
    mychat.Exec(displayer);
		displayer.Display();
    line = "";
	}

	return EXIT_SUCCESS;
}