#include <iostream>

#include "Game.hpp"
#include "YAPOG/System/Error/Exception.hpp"

int main ()
{
  try
  {
    ycl::Game game ("YAPOG");

    game.Init ();

    game.Launch ();
  }
  catch (yap::Exception& ex)
  {
    ex.GetMessage (std::cout) << std::endl;
    getchar ();
  }

  getchar ();
}
