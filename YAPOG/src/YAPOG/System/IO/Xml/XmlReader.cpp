#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/Error/InvalidMethodCallException.hpp"
#include "YAPOG/System/IO/IReaderVisitor.hpp"
#include "YAPOG/System/IO/IReaderConstVisitor.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"

namespace yap
{
  XmlReader::XmlReader (IStream& iStream, const String& rootName)
    : data_ ()
  {
    data_.CreateFromStream (iStream, rootName);
  }

  XmlReader::~XmlReader ()
  {
  }

  void XmlReader::ChangeRoot (const String& rootName)
  {
    data_.ChangeRoot (rootName);
  }

  XmlReaderCollection& XmlReader::ReadNodes (
    const String& name,
    XmlReaderCollection& xmlReaderCollection)
  {
    for (auto& it : *data_.GetRootRawData ())
    {
      if (it.first != name)
        continue;

      XmlTree data;
      data.CreateFromRawData (&it.second);
      xmlReaderCollection.Add (XmlReaderPtrType (new XmlReader (data)));
    }

    return xmlReaderCollection;
  }

  void XmlReader::Accept (IReaderVisitor& visitor)
  {
    visitor.Visit (*this);
  }

  void XmlReader::Accept (IReaderConstVisitor& visitor) const
  {
    visitor.Visit (*this);
  }

  String XmlReader::ReadString ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadString ()");
  }

  String XmlReader::ReadString (const String& name)
  {
    return data_.Get<String> (name);
  }

  bool XmlReader::ReadBool ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadBool ()");
  }

  bool XmlReader::ReadBool (const String& name)
  {
    return data_.Get<bool> (name);
  }

  char XmlReader::ReadChar ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadChar ()");
  }

  char XmlReader::ReadChar (const String& name)
  {
    return data_.Get<char> (name);
  }

  uchar XmlReader::ReadUChar ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadUChar ()");
  }

  uchar XmlReader::ReadUChar (const String& name)
  {
    return data_.Get<uchar> (name);
  }

  Int16 XmlReader::ReadInt16 ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadInt16 ()");
  }

  Int16 XmlReader::ReadInt16 (const String& name)
  {
    return data_.Get<Int16> (name);
  }

  UInt16 XmlReader::ReadUInt16 ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadUInt16 ()");
  }

  UInt16 XmlReader::ReadUInt16 (const String& name)
  {
    return data_.Get<UInt16> (name);
  }

  int XmlReader::ReadInt ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadInt ()");
  }

  int XmlReader::ReadInt (const String& name)
  {
    return data_.Get<int> (name);
  }

  uint XmlReader::ReadUInt ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadUInt ()");
  }

  uint XmlReader::ReadUInt (const String& name)
  {
    return data_.Get<uint> (name);
  }

  Int64 XmlReader::ReadInt64 ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadInt64 ()");
  }

  Int64 XmlReader::ReadInt64 (const String& name)
  {
    return data_.Get<Int64> (name);
  }

  UInt64 XmlReader::ReadUInt64 ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadUInt64 ()");
  }

  UInt64 XmlReader::ReadUInt64 (const String& name)
  {
    return data_.Get<UInt64> (name);
  }

  float XmlReader::ReadFloat ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadFloat ()");
  }

  float XmlReader::ReadFloat (const String& name)
  {
    return data_.Get<float> (name);
  }

  double XmlReader::ReadDouble ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadDouble ()");
  }

  double XmlReader::ReadDouble (const String& name)
  {
    return data_.Get<double> (name);
  }

  Vector2 XmlReader::ReadVector2 ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadVector2 ()");
  }

  Vector2 XmlReader::ReadVector2 (const String& name)
  {
    /// @todo
    return ReadVector2 ();
  }

  XmlReader::XmlReader (const XmlTree& data)
    : data_ ()
  {
    data_.CreateFromXmlTree (data);
  }
} // namespace yap
