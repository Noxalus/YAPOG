#include <iostream>
#include "YAPOG/Collection/Map.hpp"

using namespace yap;
int main ()
{
  Map<int, double> v;
  v.Add (9, 666.d);
  for (int i=0;i<10;++i)
  {
    v.Add (v);
    std::cout << v[9] << std::endl;
  }

  std::cout << v.Count () << std::endl;
}