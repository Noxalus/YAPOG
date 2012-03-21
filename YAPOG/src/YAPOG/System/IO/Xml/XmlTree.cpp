#include "YAPOG/System/IO/Xml/XmlTree.hpp"

namespace yap
{
  XmlTree::XmlTree ()
    : rootData_ ()
    , data_ (nullptr)
  {
  }

  void XmlTree::Create (const String& rootName)
  {
    data_ = &rootData_;

    Add (rootName, "");
  }

  void XmlTree::CreateFromStream (IStream& iStream, const String& rootName)
  {
    read_xml (iStream, rootData_);

    ChangeRoot (rootName);
  }

  void XmlTree::Dump (OStream& oStream)
  {
    boost::property_tree::xml_writer_settings<char> w (' ', 2);

    write_xml (oStream, rootData_, w);
  }

  void XmlTree::ChangeRoot (const String& rootName)
  {
    data_ = &rootData_.get_child (rootName);
  }
} /// namespace yap
