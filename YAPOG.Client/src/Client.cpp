#include <iostream>

#include <boost/exception/all.hpp>

#include "YAPOG/System/Error/Exception.hpp"

#include "Game.hpp"
#include "Configuration/GameData.hpp"

int main ()
{
  try
  {

#ifndef YAPOG_WIN
    ycl::GameData::Init ("../Content/Configuration.xml");
# else
    ycl::GameData::Init ("../../Content/Configuration.xml");
#endif // YAPOG_WIN

    ycl::Game game ("YAPOG");

    game.Init ();

    game.Launch ();
  }
  catch (yap::Exception& ex)
  {
    ex.GetMessage (std::cout) << std::endl;
    getchar ();
  }
  catch (boost::exception& ex)
  {
    std::cout << boost::diagnostic_information (ex) << std::endl;
    getchar ();
  }
}
