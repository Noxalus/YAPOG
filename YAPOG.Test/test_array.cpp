#include <iostream>
#include "YAPOG/Collection/Array.hpp"

using namespace yap;
int main ()
{
  Array<int> intArr;
  intArr.Add (9);
  for (int i=0;i<29;++i)
    intArr.Add (intArr);

  std::cout << intArr.Count () << std::endl;
}
