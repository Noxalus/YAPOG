#include <iostream>
#include "YAPOG/IO/Xml/XmlReader.hpp"

using namespace yap;
int main ()
{
  IFStream input ("data/input.xml");
  XmlReader xmlR (input, "map");

  std::cout << xmlR.ReadString ("object1.name") << std::endl;
  std::cout << xmlR.ReadString ("object2.name") << std::endl;
  std::cout << xmlR.ReadString ("object1.effect") << std::endl;
  std::cout << xmlR.ReadString ("object2.effect") << std::endl;
  std::cout << xmlR.ReadInt ("object1.weight") << std::endl;
  std::cout << xmlR.ReadInt ("object2.weight") << std::endl;

  std::cout << "-------------------------------" << std::endl;

  xmlR.ChangeRoot ("map.object1");
  std::cout << xmlR.ReadString ("name") << std::endl;

  std::cout << "-------------------------------" << std::endl;

  xmlR.ChangeRoot ("map");
  std::cout << xmlR.ReadString ("object2.name") << std::endl;
}
