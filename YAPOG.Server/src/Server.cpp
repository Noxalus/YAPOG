#include <iostream>

#include "Server/Server.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

int main ()
{
  try
  {
    yse::Server server;

    server.Init ();

    server.Launch ();
  }
  catch (const yap::Exception& ex)
  {
    ex.GetMessage (std::cout) << std::endl;
    getchar ();
  }
}
