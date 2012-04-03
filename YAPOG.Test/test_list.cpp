#include <iostream>
#include "YAPOG/Collection/List.hpp"

using namespace yap;
using namespace yap::collection;
int main ()
{
  List<int> intList;
  intList.Add (9);
  for (int i=0;i<23;++i)
    intList.Add (intList);

  std::cout << intList.Count () << std::endl;
}
