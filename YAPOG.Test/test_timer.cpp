#include <iostream>
#include <SFML/System.hpp>
#include "YAPOG/System/Time/Timer.hpp"
#include "YAPOG/System/Time/UpdateableTimer.hpp"
using namespace yap;
using namespace sf;
using namespace std;
int main ()
{
  Timer timer;
  UpdateableTimer utimer;

  Clock refClock;

  int count = 10;
  while (count-- > 0)
  {
    yap::Time dt = yap::Time (refClock.restart ());

    utimer.Update (yap::Time (dt.GetValue () / 2.f));

    if (count == 0)
      break;

    sf::sleep (sf::seconds (0.2f));
  }

  cout << timer.GetCurrentTime ().GetValue () << std::endl;
  cout << utimer.GetCurrentTime ().GetValue () << std::endl;
  getchar();
}
