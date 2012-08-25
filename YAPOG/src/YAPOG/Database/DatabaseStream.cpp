#include "YAPOG/Database/DatabaseStream.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/IO/IReaderVisitor.hpp"
#include "YAPOG/System/IO/IReaderConstVisitor.hpp"
#include "YAPOG/System/IO/IWriterVisitor.hpp"
#include "YAPOG/System/IO/IWriterConstVisitor.hpp"
#include "YAPOG/System/IO/IReaderVisitor.hpp"
#include "YAPOG/System/IO/IReaderConstVisitor.hpp"

namespace yap
{
  DatabaseStream::DatabaseStream 
    (const yap::String& query, 
    pgs::pg_cnx& databaseConnection)
    : pgStream_ (query, databaseConnection)
  {
  }

  void DatabaseStream::Accept (IWriterVisitor& visitor)
  {
    visitor.Visit (*this);
  }

  void DatabaseStream::Accept (IWriterConstVisitor& visitor) const
  {
    visitor.Visit (*this);
  }

  void DatabaseStream::Accept (IReaderVisitor& visitor)
  {
    visitor.Visit (*this);
  }

  void DatabaseStream::Accept (IReaderConstVisitor& visitor) const
  {
    visitor.Visit (*this);
  }

  void DatabaseStream::Write (const String& value)
  {
    WriteData (value);
  }

  void DatabaseStream::Write (const String& name, const String& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const String&)");
  }

  void DatabaseStream::Write (const bool& value)
  {
    WriteData (value);
  }

  void DatabaseStream::Write (const String& name, const bool& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const bool&)");
  }

  void DatabaseStream::Write (const char& value)
  {
    yap::String s;
    s += value;

    WriteData (s);
  }

  void DatabaseStream::Write (const String& name, const char& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const char&)");
  }

  void DatabaseStream::Write (const uchar& value)
  {
    WriteData (value);
  }

  void DatabaseStream::Write (const String& name, const uchar& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const uchar&)");
  }

  void DatabaseStream::Write (const Int16& value)
  {
    WriteData (value);
  }

  void DatabaseStream::Write (const String& name, const Int16& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const Int16&)");
  }

  void DatabaseStream::Write (const UInt16& value)
  {
    WriteData (value);
  }

  void DatabaseStream::Write (const String& name, const UInt16& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const UInt16&)");
  }

  void DatabaseStream::Write (const int& value)
  {
    WriteData (value);
  }

  void DatabaseStream::Write (const String& name, const int& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const int&)");
  }

  void DatabaseStream::Write (const uint& value)
  {
    WriteData (value);
  }

  void DatabaseStream::Write (const String& name, const uint& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const uint&)");
  }

  void DatabaseStream::Write (const Int64& value)
  {
    WriteData<Int32> (value);
  }

  void DatabaseStream::Write (const String& name, const Int64& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const Int64&)");
  }

  void DatabaseStream::Write (const UInt64& value)
  {
    WriteData<UInt32> (value);
  }

  void DatabaseStream::Write (const String& name, const UInt64& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const UInt64&)");
  }

  void DatabaseStream::Write (const float& value)
  {
    WriteData<double> (value);
  }

  void DatabaseStream::Write (const String& name, const float& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const float&)");
  }

  void DatabaseStream::Write (const double& value)
  {
    WriteData (value);
  }

  void DatabaseStream::Write (const String& name, const double& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const double&)");
  }

  void DatabaseStream::Write (const Vector2& value)
  {
    Write ("(" + 
      StringHelper::ToString (value.x) + "," + 
      StringHelper::ToString (value.y) + ")");
  }

  void DatabaseStream::Write (const String& name, const Vector2& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const Vector2&)");
  }

  void DatabaseStream::Write (const ID& value)
  {
    Write (value.GetValue ());
  }

  void DatabaseStream::Write (const String& name, const ID& value)
  {
    YAPOG_THROW(
      "DatabaseStream::Write (const String&, const ID&)");
  }

  String DatabaseStream::ReadString ()
  {
    return ReadData<String> ();
  }

  String DatabaseStream::ReadString (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadString (const String&)'");
  }

  bool DatabaseStream::ReadBool ()
  {
    return ReadData<bool> ();
  }

  bool DatabaseStream::ReadBool (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadBool (const String&)'");
  }

  char DatabaseStream::ReadChar ()
  {
    return ReadData<yap::String> ()[0];
  }

  char DatabaseStream::ReadChar (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadChar (const String&)'");
  }

  uchar DatabaseStream::ReadUChar ()
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadUChar ()'");
  }

  uchar DatabaseStream::ReadUChar (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadUChar (const String&)'");
  }

  Int16 DatabaseStream::ReadInt16 ()
  {
    return ReadData<Int16> ();
  }

  Int16 DatabaseStream::ReadInt16 (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadInt16 (const String&)'");
  }

  UInt16 DatabaseStream::ReadUInt16 ()
  {
    return ReadData<UInt16> ();
  }

  UInt16 DatabaseStream::ReadUInt16 (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadUInt16 (const String&)'");
  }

  int DatabaseStream::ReadInt ()
  {
    return ReadData<int> ();
  }

  int DatabaseStream::ReadInt (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadInt (const String&)'");
  }

  uint DatabaseStream::ReadUInt ()
  {
    return ReadData<uint> ();
  }

  uint DatabaseStream::ReadUInt (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadUInt (const String&)'");
  }

  Int64 DatabaseStream::ReadInt64 ()
  {
    return ReadData<Int32> ();
  }

  Int64 DatabaseStream::ReadInt64 (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadInt64 (const String&)'");
  }

  UInt64 DatabaseStream::ReadUInt64 ()
  {
    return ReadData<UInt32> ();
  }

  UInt64 DatabaseStream::ReadUInt64 (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadUInt64 (const String&)'");
  }

  float DatabaseStream::ReadFloat ()
  {
    return ReadData<double> ();
  }

  float DatabaseStream::ReadFloat (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadFloat (const String&)'");
  }

  double DatabaseStream::ReadDouble ()
  {
    return ReadData<double> ();
  }

  double DatabaseStream::ReadDouble (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadDouble (const String&)'");
  }

  Vector2 DatabaseStream::ReadVector2 ()
  {
    yap::collection::Array<yap::String> result;

    yap::StringHelper::Split (ReadString (), "(,)", result); 

    return yap::Vector2 (
      yap::StringHelper::Parse<float> (result[1]), 
      yap::StringHelper::Parse<float> (result[2]));
  }

  Vector2 DatabaseStream::ReadVector2 (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadVector2 (const String&)'");
  }

  ID DatabaseStream::ReadID ()
  {
    return ID (ReadUInt64 ());
  }

  ID DatabaseStream::ReadID (const String& name)
  {
    YAPOG_THROW(
      "Invalid method call: `DatabaseStream::ReadID (const String&)'");
  }

  /// pg_stream methods
  int DatabaseStream::EndOfStream ()
  {
    return pgStream_.eos ();
  }

  int DatabaseStream::AffectedRows () const
  {
    return pgStream_.affected_rows ();
  }

  bool DatabaseStream::ReturnValueIsEmpty () const
  {
    return pgStream_.val_is_null ();
  }

} // namespace yap