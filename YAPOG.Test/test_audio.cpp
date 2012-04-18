#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a music to play
	sf::Music music;
	if (!music.openFromFile("trainer_battle.ogg"))
	{
		getchar();
		return EXIT_FAILURE;
	}

	//music.setPlayingOffset(sf::Time(sf::seconds(37.f)));

	music.setPlayingOffset(sf::Time(sf::seconds(89.75f)));
	// Play the music
	music.play();

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		std::cout << music.getPlayingOffset().asSeconds() << std::endl;

		
		if (music.getPlayingOffset() >= sf::Time(sf::seconds(90.5f)))
		{
			music.setPlayingOffset(sf::Time(sf::seconds(12.75f)));
		}
		
		// Clear screen
		window.clear();

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}