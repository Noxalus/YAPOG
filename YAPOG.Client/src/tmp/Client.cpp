#include <iostream>

#include "tmp/Client.hpp"
#include "YAPOG/tmp/HelloWorld.hpp"

int main ()
{
  HelloWorld ();
  std::cout << "[from client]"
            << std::endl;
}
