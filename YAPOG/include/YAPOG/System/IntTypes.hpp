#ifndef YAPOG_TYPES_HPP
# define YAPOG_TYPES_HPP

namespace yap
{
  typedef signed char Int8;
  typedef unsigned char UInt8;
  typedef UInt8 uchar;

  typedef signed short Int16;
  typedef unsigned short UInt16;

  typedef signed int Int32;
  typedef unsigned int UInt32;
  typedef UInt32 uint;

# if defined (_MSC_VER)
  typedef signed __int64 Int64;
  typedef unsigned __int64 UInt64;
# else
  typedef signed long long Int64;
  typedef unsigned long long UInt64;
# endif // _MSC_VER
} // namespace yap

#endif // YAPOG_TYPES_HPP
