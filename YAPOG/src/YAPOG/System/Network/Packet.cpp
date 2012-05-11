#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/IO/IReaderVisitor.hpp"
#include "YAPOG/System/IO/IReaderConstVisitor.hpp"
#include "YAPOG/System/IO/IWriterVisitor.hpp"
#include "YAPOG/System/IO/IWriterConstVisitor.hpp"
#include "YAPOG/System/IO/IReaderVisitor.hpp"
#include "YAPOG/System/IO/IReaderConstVisitor.hpp"
#include "YAPOG/System/Network/ClientSocket.hpp"

namespace yap
{
  const PacketType Packet::DEFAULT_TYPE = PacketType::None;

  Packet::Packet ()
    : type_ (DEFAULT_TYPE)
    , packet_ ()
  {
  }

  Packet::~Packet ()
  {
  }

  void Packet::CreateFromType (PacketType type)
  {
    type_ = type;

    Write (type_);
  }

  bool Packet::CreateFromSocket (ClientSocket& socket)
  {
    if (!socket.Receive (*this))
      return false;

    type_ = ReadPacketType ();

    return true;
  }

  const PacketType& Packet::GetType () const
  {
    return type_;
  }

  sf::Packet& Packet::GetInnerPacket ()
  {
    return packet_;
  }

  void Packet::Write (PacketType packetType)
  {
    Write (static_cast<Int16> (packetType));
  }

  PacketType Packet::ReadPacketType ()
  {
    return static_cast<PacketType> (ReadInt16 ());
  }

  void Packet::Accept (IWriterVisitor& visitor)
  {
    visitor.Visit (*this);
  }

  void Packet::Accept (IWriterConstVisitor& visitor) const
  {
    visitor.Visit (*this);
  }

  void Packet::Accept (IReaderVisitor& visitor)
  {
    visitor.Visit (*this);
  }

  void Packet::Accept (IReaderConstVisitor& visitor) const
  {
    visitor.Visit (*this);
  }

  void Packet::Write (const String& value)
  {
    WriteData (value);
  }

  void Packet::Write (const String& name, const String& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const String&)");
  }

  void Packet::Write (const bool& value)
  {
    WriteData (value);
  }

  void Packet::Write (const String& name, const bool& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const bool&)");
  }

  void Packet::Write (const char& value)
  {
    WriteData (value);
  }

  void Packet::Write (const String& name, const char& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const char&)");
  }

  void Packet::Write (const uchar& value)
  {
    WriteData (value);
  }

  void Packet::Write (const String& name, const uchar& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const uchar&)");
  }

  void Packet::Write (const Int16& value)
  {
    WriteData (value);
  }

  void Packet::Write (const String& name, const Int16& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const Int16&)");
  }

  void Packet::Write (const UInt16& value)
  {
    WriteData (value);
  }

  void Packet::Write (const String& name, const UInt16& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const UInt16&)");
  }

  void Packet::Write (const int& value)
  {
    WriteData (value);
  }

  void Packet::Write (const String& name, const int& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const int&)");
  }

  void Packet::Write (const uint& value)
  {
    WriteData (value);
  }

  void Packet::Write (const String& name, const uint& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const uint&)");
  }

  void Packet::Write (const Int64& value)
  {
    WriteData<Int32> (value);
  }

  void Packet::Write (const String& name, const Int64& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const Int64&)");
  }

  void Packet::Write (const UInt64& value)
  {
    WriteData<UInt32> (value);
  }

  void Packet::Write (const String& name, const UInt64& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const UInt64&)");
  }

  void Packet::Write (const float& value)
  {
    WriteData (value);
  }

  void Packet::Write (const String& name, const float& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const float&)");
  }

  void Packet::Write (const double& value)
  {
    WriteData (value);
  }

  void Packet::Write (const String& name, const double& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const double&)");
  }

  void Packet::Write (const Vector2& value)
  {
    Write (value.x);
    Write (value.y);
  }

  void Packet::Write (const String& name, const Vector2& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const Vector2&)");
  }

  void Packet::Write (const ID& value)
  {
    Write (value.GetValue ());
  }

  void Packet::Write (const String& name, const ID& value)
  {
    YAPOG_THROW("Packet::Write (const String&, const ID&)");
  }

  String Packet::ReadString ()
  {
    return ReadData<String> ();
  }

  String Packet::ReadString (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadString (const String&)'");
  }

  bool Packet::ReadBool ()
  {
    return ReadData<bool> ();
  }

  bool Packet::ReadBool (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadBool (const String&)'");
  }

  char Packet::ReadChar ()
  {
    return ReadData<Int8> ();
  }

  char Packet::ReadChar (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadChar (const String&)'");
  }

  uchar Packet::ReadUChar ()
  {
    return ReadData<uchar> ();
  }

  uchar Packet::ReadUChar (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadUChar (const String&)'");
  }

  Int16 Packet::ReadInt16 ()
  {
    return ReadData<Int16> ();
  }

  Int16 Packet::ReadInt16 (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadInt16 (const String&)'");
  }

  UInt16 Packet::ReadUInt16 ()
  {
    return ReadData<UInt16> ();
  }

  UInt16 Packet::ReadUInt16 (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadUInt16 (const String&)'");
  }

  int Packet::ReadInt ()
  {
    return ReadData<int> ();
  }

  int Packet::ReadInt (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadInt (const String&)'");
  }

  uint Packet::ReadUInt ()
  {
    return ReadData<uint> ();
  }

  uint Packet::ReadUInt (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadUInt (const String&)'");
  }

  Int64 Packet::ReadInt64 ()
  {
    return ReadData<Int32> ();
  }

  Int64 Packet::ReadInt64 (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadInt64 (const String&)'");
  }

  UInt64 Packet::ReadUInt64 ()
  {
    return ReadData<UInt32> ();
  }

  UInt64 Packet::ReadUInt64 (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadUInt64 (const String&)'");
  }

  float Packet::ReadFloat ()
  {
    return ReadData<float> ();
  }

  float Packet::ReadFloat (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadFloat (const String&)'");
  }

  double Packet::ReadDouble ()
  {
    return ReadData<double> ();
  }

  double Packet::ReadDouble (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadDouble (const String&)'");
  }

  Vector2 Packet::ReadVector2 ()
  {
    return Vector2 (ReadFloat (), ReadFloat ());
  }

  Vector2 Packet::ReadVector2 (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadVector2 (const String&)'");
  }

  ID Packet::ReadID ()
  {
    return ID (ReadUInt64 ());
  }

  ID Packet::ReadID (const String& name)
  {
    YAPOG_THROW("Invalid method call: `Packet::ReadID (const String&)'");
  }
} // namespace yap
