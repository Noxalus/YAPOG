#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/Error/InvalidMethodCallException.hpp"

namespace yap
{
  XmlReader::XmlReader (IStream& iStream, const String& rootName)
    : IReader ()
    , data_ ()
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

  String XmlReader::ReadString ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadString ()");
  }

  String XmlReader::ReadString (const String& name)
  {
    return data_.Get<String> (name);
  }

  int XmlReader::ReadInt ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadInt ()");
  }

  int XmlReader::ReadInt (const String& name)
  {
    return data_.Get<int> (name);
  }

  unsigned int XmlReader::ReadUnsignedInt ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadUnsignedInt ()");
  }

  unsigned int XmlReader::ReadUnsignedInt (const String& name)
  {
    return data_.Get<unsigned int> (name);
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

  long double XmlReader::ReadLongDouble ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadLongDouble ()");
  }

  long double XmlReader::ReadLongDouble (const String& name)
  {
    return data_.Get<long double> (name);
  }

  char XmlReader::ReadChar ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadChar ()");
  }

  char XmlReader::ReadChar (const String& name)
  {
    return data_.Get<char> (name);
  }

  unsigned char XmlReader::ReadUnsignedChar ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadUnsignedChar ()");
  }

  unsigned char XmlReader::ReadUnsignedChar (const String& name)
  {
    return data_.Get<unsigned char> (name);
  }

  bool XmlReader::ReadBool ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadBool ()");
  }

  bool XmlReader::ReadBool (const String& name)
  {
    return data_.Get<bool> (name);
  }

  long int XmlReader::ReadLongInt ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadLongInt ()");
  }

  long int XmlReader::ReadLongInt (const String& name)
  {
    return data_.Get<long int> (name);
  }

  unsigned long int XmlReader::ReadUnsignedLongInt ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadUnsignedLongInt ()");
  }

  unsigned long int XmlReader::ReadUnsignedLongInt (const String& name)
  {
    return data_.Get<unsigned long int> (name);
  }

  short int XmlReader::ReadShortInt ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadShortInt ()");
  }

  short int XmlReader::ReadShortInt (const String& name)
  {
    return data_.Get<short int> (name);
  }

  unsigned short int XmlReader::ReadUnsignedShortInt ()
  {
    throw InvalidMethodCallException ("XmlReader::ReadUnsignedShortInt ()");
  }

  unsigned short int XmlReader::ReadUnsignedShortInt (const String& name)
  {
    return data_.Get<unsigned short int> (name);
  }
} // namespace yap
