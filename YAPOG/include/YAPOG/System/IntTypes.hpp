#ifndef YAPOG_TYPES_HPP
# define YAPOG_TYPES_HPP

namespace yap
{
# if defined (_WIN32)
  typedef __int16 Int16;
  typedef unsigned __int16 UInt16;

  typedef __int32 Int32;
  typedef unsigned __int32 UInt32;

  typedef __int64 Int64;
  typedef unsigned __int64 UInt64;
# else
  typedef short int Int16;
  typedef unsigned short int UInt16;

  typedef int Int32;
  typedef unsigned int UInt32;

  typedef long long Int64;
  typedef unsigned long long UInt64;
# endif // _WIN32

  typedef UInt32 uint;
  typedef unsigned char uchar;
} // namespace yap

#endif // YAPOG_TYPES_HPP
