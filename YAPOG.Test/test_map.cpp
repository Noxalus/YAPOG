#include <iostream>
#include "YAPOG/Collection/Map.hpp"

using namespace yap;
using namespace yap::collection;
int main ()
{
  Map<int, double> v;
  v.Add (9, 666);
  for (int i=0;i<10;++i)
  {
    v.Add (v);
    std::cout << v[9] << std::endl;
  }

  std::cout << v.Count () << std::endl;

  v[20] = 3.0;
  std::cout << 2 + v[20] << std::endl;
}
