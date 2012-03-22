#include <iostream>
#include <string>

#include "tmp/Client.hpp"
#include "YAPOG/Event/Event.hpp"
#include "YAPOG/Collection/Array.hpp"
#include "YAPOG/Collection/List.hpp"
#include "YAPOG/Vector2.hpp"
#include "YAPOG/World/Map/Physics/ICollidable.hpp"
#include "YAPOG/World/Map/IMap.hpp"
#include "YAPOG/System/IO/IWriter.hpp"
#include "YAPOG/Collection/Map.hpp"
#include "YAPOG/System/IO/Xml/XmlWriter.hpp"
#include "YAPOG/System/IO/IReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IOStream.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInputType.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInput.hpp"
#include "YAPOG/Graphics/Gui/GameInput/KeyboardGameInputEntry.hpp"
#include "YAPOG/Collection/Queue.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/Collection/PtrArray.hpp"
#include "YAPOG/Collection/PtrList.hpp"
#include "YAPOG/Collection/PtrQueue.hpp"
#include "YAPOG/Collection/PtrMap.hpp"
#include "YAPOG/Graphics/Gui/GameInput/MouseGameInputEntry.hpp"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <list>

using namespace std;
using namespace yap;
using namespace sf;
int main ()
{
  GameInputManager::Instance ().AddGameInput (
    new GameInput (
      GameInputType::Action,
      new KeyboardGameInputEntry (Key::Return)));

  GameInputManager::Instance ().AddGameInput (
    new GameInput (
      GameInputType::Misc,
      new MouseGameInputEntry (MouseButton::Left)));

  sf::RenderWindow window (sf::VideoMode (800, 600), "YAPOG");

  while (window.IsOpen ())
  {
    GuiEvent evt;

    GameInputManager::Instance ().BeginUpdate ();

    while (window.PollEvent (evt))
    {
      GameInputManager::Instance ().Update (evt);

      switch (evt.Type)
      {
        case sf::Event::Closed:
          window.Close ();
          break;

        case sf::Event::KeyPressed:
          switch (evt.Key.Code)
          {
            case sf::Keyboard::Escape:
              window.Close ();
              break;

            default:
              break;
          }
          break;

        default:
          break;
      }
    }

    GameInputManager::Instance ().EndUpdate ();

    if (GameInputManager::Instance ().GameInputIsActivated (
          GameInputType::Action))
      std::cout << "[Action]TRIGGERED" << std::endl;
    else if (GameInputManager::Instance ().GameInputIsActive (
               GameInputType::Action))
      std::cout << "[Action]ACTIVE" << std::endl;
    else if (GameInputManager::Instance ().GameInputIsDeactivated (
               GameInputType::Action))
      std::cout << "[Action]DEACTIVATED" << std::endl;

    if (GameInputManager::Instance ().GameInputIsActivated (
          GameInputType::Misc))
      std::cout << "[Misc]TRIGGERED" << std::endl;
    else if (GameInputManager::Instance ().GameInputIsActive (
               GameInputType::Misc))
      std::cout << "[Misc]ACTIVE" << std::endl;
    else if (GameInputManager::Instance ().GameInputIsDeactivated (
               GameInputType::Misc))
      std::cout << "[Misc]DEACTIVATED" << std::endl;

    window.Clear ();

    window.Display ();
  }
}
