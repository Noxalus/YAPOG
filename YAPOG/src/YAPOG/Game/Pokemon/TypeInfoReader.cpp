#include "YAPOG/Game/Pokemon/TypeInfoReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"

namespace yap
{
  const String TypeInfoReader::DEFAULT_XML_ROOT_NODE_NAME = "Type";
  const String TypeInfoReader::DEFAULT_XML_ID_NODE_NAME = "id";
  const String TypeInfoReader::DEFAULT_XML_NAME_NODE_NAME = "name";
  const String TypeInfoReader::DEFAULT_XML_FACTORS_NODE_NAME = "factors";
  const String TypeInfoReader::DEFAULT_XML_TYPE_NODE_NAME = "type";

  TypeInfoReader::TypeInfoReader (TypeInfo& typeInfo)
    : typeInfo_ (typeInfo)
  {
  }

  TypeInfoReader::TypeInfoReader (
    TypeInfo& typeInfo, 
    const String& xmlRootNodeName)
    : typeInfo_ (typeInfo),
    xmlRootNodeName_ (xmlRootNodeName)
  {
  }

  TypeInfoReader::~TypeInfoReader ()
  {
  }

  void TypeInfoReader::Visit (XmlReader& visitable)
  {
    // <Type id="{id}">

    if (!visitable.TryChangeRoot (DEFAULT_XML_ROOT_NODE_NAME))
    {
      throw Exception (
        "Failed to read `" + DEFAULT_XML_ROOT_NODE_NAME + "' node.");
    }

    typeInfo_.SetID (
      visitable.ReadID (
      XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    // <name>

    typeInfo_.SetName (visitable.ReadString (DEFAULT_XML_NAME_NODE_NAME));

    // </name>

    // <factors>

    if (!visitable.TryChangeRoot (DEFAULT_XML_FACTORS_NODE_NAME))
    {
      throw Exception (
        "Failed to read `" + DEFAULT_XML_FACTORS_NODE_NAME + "' node.");
    }


    yap::XmlReaderCollection factorsReaders;
    visitable.ReadNodes (DEFAULT_XML_TYPE_NODE_NAME, factorsReaders);
    for (auto& factorsReader : factorsReaders)
    {
      ID typeID = factorsReader->ReadID (XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME));
      float effect = factorsReader->ReadFloat ();

      typeInfo_.AddTypeEffect (typeID, effect);
    }

    visitable.UpChangeRoot ();

    // </factors>

    visitable.UpChangeRoot ();

    // </Type>
  }
}