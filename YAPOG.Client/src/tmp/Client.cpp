#include <iostream>
#include <string>

#include "tmp/Client.hpp"
#include "YAPOG/tmp/HelloWorld.hpp"
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

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <list>

using namespace std;
using namespace yap;
using namespace sf;
int main ()
{
  Queue<shared_ptr<Clock>> qi;

  shared_ptr<Clock> spc (new Clock ());
  qi.Enqueue (spc);

//  sf::Sleep (sf::Seconds (1.f));

  shared_ptr<Clock> cl;
  std::cout << qi.Dequeue (cl)->GetElapsedTime ().AsSeconds () << std::endl;

  KeyboardGameInputEntry::PtrType inputE (
    new KeyboardGameInputEntry (Key::Return));

  GameInput* inpt = new GameInput (GameInputType::Action,
                                  inputE);

  sf::Clock c;
  while (c.GetElapsedTime ().AsSeconds () < 0)
  {
    sf::Sleep (sf::Seconds (1.f));
    std::cout << "waiting..." << std::endl;
  }

  HelloWorld ();
  std::cout << "[from client]"
            << std::endl;

  sf::Image i;
  i.Create (32, 32, sf::Color::Red);
  sf::Texture t;
  t.LoadFromImage (i);
  sf::Sprite s (t);

  sf::Texture img;

  sf::RenderWindow window (sf::VideoMode (800, 600), "YAPOG");

  if (!img.LoadFromFile ("../../boo.jpg"))
    return 1;

  const int COUNT = 1;
  yap::Array<sf::Sprite> sprs;
  for (int i=0;i<COUNT;++i)
  {
    sf::Sprite spr (img);
    spr.SetPosition (sf::Vector2f (i * 200.f, 0.f));
    spr.SetScale (sf::Vector2f (0.1f, 0.1f));
    sprs.Add (sf::Sprite (img));

    std::cout << "sprs count is: " << sprs.Count () << std::endl;
  }

  sf::Sprite* spr = nullptr;

  while (window.IsOpen ())
  {
    GuiEvent evt;

    inpt->BeginUpdate ();

    while (window.PollEvent (evt))
    {
      inpt->Update (evt);

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

        case GuiEventType::KeyReleased:
          std::cout << "released..." << std::endl;
          break;

        default:
          break;
      }
    }

    inpt->EndUpdate ();

    if (inpt->IsTriggered ())
      std::cout << "TRIGGERED" << std::endl;
    else if (inpt->IsActive ())
      std::cout << "ACTIVE" << std::endl;

    window.Clear ();

//    window.Draw (s);

    for (int i=0;i<COUNT; ++i)
    {
      spr = &sprs[i];
//      window.Draw (*spr);

      spr->SetPosition (spr->GetPosition ()
                           + sf::Vector2f (i*i * 0.08f, 0.0f));
    }

    window.Display ();
  }
}
