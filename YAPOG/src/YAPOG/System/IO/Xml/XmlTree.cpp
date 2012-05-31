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

  XmlTree::XmlTree (const XmlTree& copy)
    : rootData_ ()
    , data_ (copy.data_)
  {
  }

  void XmlTree::Create (const String& rootName)
  {
    data_ = &GetRootData ();

    Add (rootName, "");
  }

  void XmlTree::CreateFromStream (IStream& iStream, const String& rootName)
  {
    read_xml (iStream, GetRootData ());

    data_ = &GetRootData ();
  }

  void XmlTree::CreateFromXmlTree (const String& rootName, XmlTree& copy)
  {
    data_ = &copy.GetChild (rootName);
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

  XmlTreePtrType XmlTree::ChangeRoot (const String& rootName)
  {
    XmlTreePtrType xmlTreePtr (new XmlTree ());

    xmlTreePtr->CreateFromXmlTree (rootName, *this);

    return xmlTreePtr;
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

    YAPOG_THROW("Index out of bound: " + StringHelper::ToString (index));
  }

  XmlTree::DataType* XmlTree::GetRootRawData () const
  {
    return data_;
  }

  XmlTree::DataType& XmlTree::GetChild (const String& name)
  {
    return data_->get_child (name);
  }

  XmlTree::DataType& XmlTree::AbsoluteGetChild (const String& name)
  {
    return GetRootData ().get_child (name);
  }

  XmlTree::DataType& XmlTree::GetRootData ()
  {
    return rootData_;
  }

  const XmlTree::DataType& XmlTree::GetRootData () const
  {
    return rootData_;
  }
} // namespace yap
