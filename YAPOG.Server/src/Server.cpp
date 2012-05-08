#include <iostream>

#include "Server.hpp"
#include "YAPOG/System/Error/Exception.hpp"

int main ()
{
  try
  {
    yse::Server server;
  }
  catch (yap::Exception& ex)
  {
    ex.GetMessage (std::cout) << std::endl;
    getchar ();
  }
}

namespace yse
{

} // namespace yse
