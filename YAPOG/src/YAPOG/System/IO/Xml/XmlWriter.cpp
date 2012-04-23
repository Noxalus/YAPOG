#include "YAPOG/System/IO/Xml/XmlWriter.hpp"
#include "YAPOG/System/Error/InvalidMethodCallException.hpp"
#include "YAPOG/System/IO/IWriterVisitor.hpp"
#include "YAPOG/System/IO/IWriterConstVisitor.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  XmlWriter::XmlWriter (OStream& oStream, const String& rootName)
    : data_ ()
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

  void XmlWriter::Accept (IWriterVisitor& visitor)
  {
    visitor.Visit (*this);
  }

  void XmlWriter::Accept (IWriterConstVisitor& visitor) const
  {
    visitor.Visit (*this);
  }

  void XmlWriter::Write (const String& value)
  {
    throw InvalidMethodCallException ("XmlWriter::Write (const String&)");
  }

  void XmlWriter::Write (const String& name, const String& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const bool& value)
  {
    throw InvalidMethodCallException ("XmlWriter::Write (const bool&)");
  }

  void XmlWriter::Write (const String& name, const bool& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const char& value)
  {
    throw InvalidMethodCallException ("XmlWriter::Write (const char&)");
  }

  void XmlWriter::Write (const String& name, const char& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const uchar& value)
  {
    throw InvalidMethodCallException ("XmlWriter::Write (const uchar&)");
  }

  void XmlWriter::Write (const String& name, const uchar& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const Int16& value)
  {
    throw InvalidMethodCallException ("XmlWriter::Write (const Int16&)");
  }

  void XmlWriter::Write (const String& name, const Int16& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const UInt16& value)
  {
    throw InvalidMethodCallException ("XmlWriter::Write (const UInt16&)");
  }

  void XmlWriter::Write (const String& name, const UInt16& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const int& value)
  {
    throw InvalidMethodCallException ("XmlWriter::Write (const int&)");
  }

  void XmlWriter::Write (const String& name, const int& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const uint& value)
  {
    throw InvalidMethodCallException ("XmlWriter::Write (const uint&)");
  }

  void XmlWriter::Write (const String& name, const uint& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const Int64& value)
  {
    throw InvalidMethodCallException ("XmlWriter::Write (const Int64&)");
  }

  void XmlWriter::Write (const String& name, const Int64& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const UInt64& value)
  {
    throw InvalidMethodCallException ("XmlWriter::Write (const UInt64&)");
  }

  void XmlWriter::Write (const String& name, const UInt64& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const float& value)
  {
    throw InvalidMethodCallException ("XmlWriter::Write (const float&)");
  }

  void XmlWriter::Write (const String& name, const float& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const double& value)
  {
    throw InvalidMethodCallException ("XmlWriter::Write (const double&)");
  }

  void XmlWriter::Write (const String& name, const double& value)
  {
    data_.Add (name, value);
  }

  void XmlWriter::Write (const Vector2& value)
  {
    throw InvalidMethodCallException ("XmlWriter::Write (const Vector2&)");
  }

  void XmlWriter::Write (const String& name, const Vector2& value)
  {
    String data =
      StringHelper::ToString (value.x) +
      "," +
      StringHelper::ToString (value.y);

    Write (name, data);
  }
} // namespace yap
