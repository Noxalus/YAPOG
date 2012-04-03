#include <iostream>

#include "TestGame.hpp"
#include "YAPOG/System/Error/Exception.hpp"

int main ()
{
  try
  {
    TestGame game ("YAPOG");
    game.Init ();
    game.Launch ();
  }
  catch (yap::Exception& ex)
  {
    ex.GetMessage (std::cout) << std::endl;
  }
}
