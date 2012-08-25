#ifndef YAPOG_DATABASESTREAM_HXX
# define YAPOG_DATABASESTREAM_HXX

# include "YAPOG/System/Error/DatabaseException.hpp"

namespace yap
{
  template <typename T>
  inline void DatabaseStream::WriteData (const T& data)
  {
    try
    {
      pgStream_ << data;
    }
    catch (pgs::pg_excpt& e)
    {
      throw DatabaseException (e.full_error_txt ());
    }
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
