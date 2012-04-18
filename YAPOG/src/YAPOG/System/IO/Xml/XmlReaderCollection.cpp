#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"

namespace yap
{
  XmlReaderCollection::XmlReaderCollection ()
    : data_ ()
  {
  }

  XmlReaderCollection::~XmlReaderCollection ()
  {
  }

  void XmlReaderCollection::Add (const XmlReaderPtrType& data)
  {
    data_.Add (data);
  }

  XmlReaderCollection::ConstItType XmlReaderCollection::begin () const
  {
    return data_.Begin ();
  }

  XmlReaderCollection::ConstItType XmlReaderCollection::end () const
  {
    return data_.End ();
  }
} // namespace yap
