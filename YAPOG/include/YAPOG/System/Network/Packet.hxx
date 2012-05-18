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
} // namespace yap

#endif // YAPOG_PACKET_HXX
