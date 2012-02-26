#include <iostream>

#include "tmp/Client.hpp"
#include "tmp/HelloWorld.hpp"

int main ()
{
  HelloWorld ();
  std::cout << "[from client]"
            << std::endl;
}
