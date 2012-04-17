 #include <SFML/Audio.hpp>
 #include <SFML/Graphics.hpp>
 
 int main()
 {
     // Create the main window
     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
 
     // Load a music to play
     sf::Music music;
     if (!music.openFromFile("wild_pokemon_battle_short.ogg"))
         return EXIT_FAILURE;

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
 
         // Clear screen
         window.clear();
 
         // Update the window
         window.display();
     }
 
     return EXIT_SUCCESS;
 }