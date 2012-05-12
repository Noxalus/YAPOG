#ifndef YAPOG_DATABASESTREAM_HXX
# define YAPOG_DATABASESTREAM_HXX

namespace yap
{
  template <typename T>
  inline void DatabaseStream::WriteData (const T& data)
  {
    pgStream_ << data;
  }

  template <typename T>
  inline T DatabaseStream::ReadData ()
  {
    T data;
    pgStream_ >> data;
    return data;
  }
} // namespace yap

#endif // YAPOG_DATABASESTREAM_HXX
