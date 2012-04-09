#include <iostream>
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlWriter.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"

using namespace yap;
using namespace std;
int main ()
{
  try
  {
    IFStream input ("../Content/Map/test.xml");
    XmlReader xmlR (input, "Map");

    cout << "MAP" << endl;

    /// reading of "name" node from "Map" root node
    cout << "|--" << xmlR.ReadString ("name") << endl;
    cout << "|--" << xmlR.ReadString ("ID") << endl;
    /// reading of attribute "testattr" of "Map" node
    cout << "|--" << xmlR.ReadString (XmlHelper::GetAttrNodeName ("testattr"))
         << endl;

    cout << "|--OBJECTS" << endl;

    /// reading of all nodes whose name is "object"
    XmlReaderCollection objects;
    for (const auto& it : xmlR.ReadNodes ("object", objects))
    {
      cout << "|  |--" << it->ReadString ("ID") << endl;
    }

    cout << "----------" << endl;

#if false
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
#endif
  }
  catch (yap::Exception& ex)
  {
    ex.GetMessage (std::cout) << std::endl;
  }
}
