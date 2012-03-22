#include "YAPOG/System/IO/Xml/XmlWriter.hpp"
#include "YAPOG/System/Error/InvalidMethodCallException.hpp"

namespace yap
{
  XmlWriter::XmlWriter (OStream& oStream, const String& rootName)
    : IWriter ()
    , data_ ()
    , oStream_ (oStream)
  {
    data_.Create (rootName);
  }

  XmlWriter::~XmlWriter ()
  {
  }

  void XmlWriter::ChangeRoot (const String& rootName)
  {
    data_.ChangeRoot (rootName);
  }

  void XmlWriter::Dump ()
  {
    data_.Dump (oStream_);
  }

  void XmlWriter::Write (const String& value)
  {
    throw InvalidMethodCallException ();
  }

  void XmlWriter::Write (const String& name, const String& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const int& value)
  {
    throw InvalidMethodCallException ();
  }

  void XmlWriter::Write (const String& name, const int& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const unsigned int& value)
  {
    throw InvalidMethodCallException ();
  }

  void XmlWriter::Write (const String& name, const unsigned int& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const float& value)
  {
    throw InvalidMethodCallException ();
  }

  void XmlWriter::Write (const String& name, const float& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const double& value)
  {
    throw InvalidMethodCallException ();
  }

  void XmlWriter::Write (const String& name, const double& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const long double& value)
  {
    throw InvalidMethodCallException ();
  }

  void XmlWriter::Write (const String& name, const long double& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const char& value)
  {
    throw InvalidMethodCallException ();
  }

  void XmlWriter::Write (const String& name, const char& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const unsigned char& value)
  {
    throw InvalidMethodCallException ();
  }

  void XmlWriter::Write (const String& name, const unsigned char& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const bool& value)
  {
    throw InvalidMethodCallException ();
  }

  void XmlWriter::Write (const String& name, const bool& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const long int& value)
  {
    throw InvalidMethodCallException ();
  }

  void XmlWriter::Write (const String& name, const long int& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const unsigned long int& value)
  {
    throw InvalidMethodCallException ();
  }

  void XmlWriter::Write (const String& name,
                         const unsigned long int& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const short int& value)
  {
    throw InvalidMethodCallException ();
  }

  void XmlWriter::Write (const String& name, const short int& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const unsigned short int& value)
  {
    throw InvalidMethodCallException ();
  }

  void XmlWriter::Write (const String& name, unsigned short int& value)
  {
    data_.Add (name, value);
  }
} // namespace yap
