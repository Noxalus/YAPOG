#include <iostream>
#include "YAPOG/Collection/Array.hpp"

using namespace yap;
using namespace yap::collection;
int main ()
{
  Array<int> intArr;
  intArr.Add (9);
  for (int i=0;i<10;++i)
    intArr.Add (intArr);

  std::cout << intArr.Count () << std::endl;
	getchar();
}
