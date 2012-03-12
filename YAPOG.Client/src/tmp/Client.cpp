#include <iostream>

#include "tmp/Client.hpp"
#include "YAPOG/tmp/HelloWorld.hpp"
#include "YAPOG/Event/Event.hpp"
#include "YAPOG/Collection/Array.hpp"
#include "YAPOG/Vector2.hpp"
#include "YAPOG/World/Map/Physics/ICollidable.hpp"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <list>

//template <typename T>
//using totot = std::list<T>;

enum class Toto : unsigned int
{
    A, B, C
};

typedef std::shared_ptr<int> PTR;

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
  yap::Array<int> arr;
  arr.Add (42);
  arr.Add (666);
  for (const int& i : arr)
    std::cout << i << std::endl;

  yap::Array<int> arr2;
  arr2.Add (3);
  arr2.Add (arr);

  for (const int& i : arr2)
    std::cout << i << std::endl;

  if (!arr2.IsEmpty ())
    std::cout << "count: " << arr2.Count () << std::endl;

  arr2.Clear ();

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
