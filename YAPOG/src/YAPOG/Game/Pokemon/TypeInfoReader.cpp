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
    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    typeInfo_.SetID (
      reader->ReadID (
      XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    typeInfo_.SetName (reader->ReadString (DEFAULT_XML_NAME_NODE_NAME));

    reader = reader->ChangeRoot (DEFAULT_XML_FACTORS_NODE_NAME);

    yap::XmlReaderCollection factorsReaders;
    reader->ReadNodes (DEFAULT_XML_TYPE_NODE_NAME, factorsReaders);
    for (auto& factorsReader : factorsReaders)
    {
      ID typeID = factorsReader->ReadID (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME));
      float effect = factorsReader->ReadFloat ();

      typeInfo_.AddTypeEffect (typeID, effect);
    }
  }
}
