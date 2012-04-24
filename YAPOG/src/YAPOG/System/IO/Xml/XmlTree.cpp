#include <boost/optional.hpp>

#include "YAPOG/System/IO/Xml/XmlTree.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

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

  void XmlTree::CreateFromXmlTree (const XmlTree& copy)
  {
    CreateFromRawData (copy.data_);
  }

  void XmlTree::CreateFromRawData (DataType* data)
  {
    data_ = data;
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

  bool XmlTree::NodeExists (const String& name) const
  {
    boost::optional<DataType&> targetNode =
      data_->get_child_optional (name);

    return targetNode;
  }

  const String& XmlTree::GetNode (int index) const
  {
    for (const DataType::value_type& node : *data_)
    {
      if (index-- == 0)
        return node.first;
    }

    throw Exception ("Index out of bound: " + StringHelper::ToString (index));
  }

  XmlTree::DataType* XmlTree::GetRootRawData () const
  {
    return data_;
  }
} // namespace yap
