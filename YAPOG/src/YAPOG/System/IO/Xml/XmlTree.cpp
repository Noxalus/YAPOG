#include <boost/optional.hpp>

#include "YAPOG/System/IO/Xml/XmlTree.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  XmlTree::XmlTree ()
    : rootData_ ()
    , data_ (nullptr)
    , rootDataPtr_ (nullptr)
    , currentAbsoluteRootName_ ()
    , currentRelativeRootName_ ()
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

    AbsoluteChangeRoot (rootName);
  }

  void XmlTree::CreateFromXmlTree (XmlTree& copy)
  {
    CreateFromRawData ("", copy, copy.data_);
  }

  void XmlTree::CreateFromRawData (
    const String& rootName,
    XmlTree& rootSource,
    DataType* data)
  {
    rootDataPtr_ = &rootSource.GetRootData ();
    data_ = data;

    SetAbsoluteRootName (rootSource.currentAbsoluteRootName_);
    AppendRootNodeName (rootName);
  }

  void XmlTree::Dump (OStream& oStream)
  {
    boost::property_tree::xml_writer_settings<char> w (' ', 2);

    write_xml (oStream, rootData_, w);
  }

  void XmlTree::AbsoluteChangeRoot (const String& rootName)
  {
    SetAbsoluteRootName (rootName);

    data_ = &GetRootData ().get_child (rootName);
  }

  void XmlTree::UpChangeRoot ()
  {
    AbsoluteChangeRoot (
      currentAbsoluteRootName_.substr (
        0,
        currentAbsoluteRootName_.find_last_of ('.')));
  }

  void XmlTree::DownChangeRoot (const String& rootName)
  {
    AppendRootNodeName (rootName);

    data_ = &data_->get_child (rootName);
  }

  bool XmlTree::TryChangeRoot (const String& rootName)
  {
    if (currentRelativeRootName_ == rootName)
      return true;

    if (!NodeExists (rootName))
      return false;

    DownChangeRoot (rootName);

    return true;
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

  void XmlTree::SetAbsoluteRootName (const String& rootName)
  {
    currentAbsoluteRootName_ = rootName;

    UpdateRelativeRootName ();
  }

  void XmlTree::AppendRootNodeName (const String& nodeName)
  {
    if (nodeName.empty ())
      return;

    SetAbsoluteRootName (
      currentAbsoluteRootName_ +
      (currentAbsoluteRootName_.empty () ? "" : ".") +
      nodeName);
  }

  void XmlTree::UpdateRelativeRootName ()
  {
    size_t lastPointIndex = currentAbsoluteRootName_.find_last_of ('.');
    if (lastPointIndex == String::npos)
    {
      currentRelativeRootName_ = currentAbsoluteRootName_;
      return;
    }

    currentRelativeRootName_ = currentAbsoluteRootName_.substr (
      lastPointIndex + 1);
  }

  XmlTree::DataType& XmlTree::GetRootData ()
  {
    return rootDataPtr_ == nullptr ? rootData_ : *rootDataPtr_;
  }

  const XmlTree::DataType& XmlTree::GetRootData () const
  {
    return rootDataPtr_ == nullptr ? rootData_ : *rootDataPtr_;
  }
} // namespace yap
