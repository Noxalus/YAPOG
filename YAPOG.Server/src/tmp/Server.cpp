#include <iostream>

#include "tmp/Server.hpp"
#include "YAPOG/tmp/HelloWorld.hpp"

int main ()
{
  HelloWorld ();
  std::cout << "[from server]"
            << std::endl;
}
