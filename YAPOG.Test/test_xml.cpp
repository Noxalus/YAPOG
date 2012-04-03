#include <iostream>
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlWriter.hpp"

using namespace yap;
int main ()
{
  try
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

    OFStream output ("data/output.xml");
    XmlWriter xmlW (output, "map");
    xmlW.ChangeRoot ("map");
    xmlW.Write (yap::String ("sds"));
    xmlW.Write ("object1", String ());
    xmlW.ChangeRoot ("map.object1");
    xmlW.Write ("name", String ("key"));
    xmlW.ChangeRoot ("map");
    xmlW.Write ("object2", String ());
    xmlW.ChangeRoot ("map.object2");
    xmlW.Write ("name", String ("flask"));

    xmlW.Dump ();
  }
  catch (yap::Exception& ex)
  {
    ex.GetMessage (std::cout) << std::endl;
  }
}
