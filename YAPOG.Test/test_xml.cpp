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
	/*
    /// reading of all nodes whose name is "object"
    XmlReaderCollection objects;
    for (const auto& it : xmlR.ReadNodes ("object", objects))
    {
      cout << "|  |--" << it->ReadString ("ID") << endl;
      }*/
  }
  catch (yap::Exception& ex)
  {
    ex.GetMessage (std::cout) << std::endl;
  }

}
