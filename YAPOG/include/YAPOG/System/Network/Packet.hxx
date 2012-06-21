#ifndef YAPOG_PACKET_HXX
# define YAPOG_PACKET_HXX

namespace yap
{
  template <typename T>
  inline void Packet::WriteData (const T& data)
  {
    packet_ << data;
  }

  template <typename T>
  inline T Packet::ReadData ()
  {
    T data;
    packet_ >> data;
    return data;
  }

  template <>
  inline void Packet::WriteData<String> (const String& data)
  {
    Write (static_cast<UInt64> (data.size ()));
    packet_ << data.c_str ();
  }

  template <>
  inline String Packet::ReadData<String> ()
  {
    UInt64 size = ReadUInt64 ();
    char* data = new char[size + 1];

    packet_ >> data;

    return String (data, size);
  }
} // namespace yap

#endif // YAPOG_PACKET_HXX
