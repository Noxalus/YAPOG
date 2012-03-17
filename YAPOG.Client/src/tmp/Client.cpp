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
#include "YAPOG/Misc/State.hpp"
#include "YAPOG/IO/IWriter.hpp"
#include "YAPOG/Collection/Map.hpp"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <list>

struct Perso
{
    yap::Event<const Perso&, const sf::Vector2f&> OnMove;

    Perso (std::string name) : _name (name) {}

    void Move (const sf::Vector2f& offset)
    {
      _position += offset;

      OnMove (*this, offset);
    }

    const std::string& GetName () const { return _name; }

  private:
    sf::Vector2f _position;
    std::string _name;
};

void perso_OnMove (const Perso& p, const sf::Vector2f& offset)
{
  std::cout << p.GetName ()
            << " is moved by the offset: ( "
            << offset.x
            << ", "
            << offset.y
            << " )."
            << std::endl;
}

int main ()
{
  yap::State<std::string> stt ("toto");
  std::string str ("toto");

  std::cout << (stt == str ? "true" : "false");
  std::cout << (str == stt ? "true" : "false");

  stt = str;

  stt = std::string ("tata");

  yap::Map<yap::String, int> map1;
  map1.Add ("toto", 3);

  map1.Add (map1);

  if (map1.Contains ("toto"))
//    return 1;
    ;

  map1.Clear ();
  if (map1.IsEmpty ())
    return 2;

  yap::List<yap::State<std::string>> states;
  states.Add (std::string ("titi"));

  yap::Array<yap::State<std::string>> states2;
  states.Add (std::string ("titi"));

  yap::List<yap::State<yap::String>> states3 (states);

  sf::Clock c;
  while (c.GetElapsedTime ().AsSeconds () < 0)
  {
    sf::Sleep (sf::Seconds (1.f));
    std::cout << "waiting..." << std::endl;
  }

  HelloWorld ();
  std::cout << "[from client]"
            << std::endl;

  Perso p ("Toto");
  Perso p2 ("Titi");

  p.OnMove += perso_OnMove;
  p2.OnMove += perso_OnMove;

  p.Move (sf::Vector2f (42.f, 3.f));
  p2.Move (sf::Vector2f (333.f, 666.f));

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
    sf::Event evt;

    while (window.PollEvent (evt))
    {
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

    window.Clear ();

    window.Draw (s);

    for (int i=0;i<COUNT; ++i)
    {
      spr = &sprs[i];
      window.Draw (*spr);

      spr->SetPosition (spr->GetPosition ()
                           + sf::Vector2f (i*i * 0.08f, 0.0f));
    }

    window.Display ();
  }

  p.Move (sf::Vector2f ());
}
