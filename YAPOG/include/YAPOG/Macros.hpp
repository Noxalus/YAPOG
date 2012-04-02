#ifndef YAPOG_MACROS_HPP
# define YAPOG_MACROS_HPP

namespace yap
{
/// Disallowing copy
# define DISALLOW_COPY(TYPE)                    \
  private:                                      \
  TYPE (const TYPE&);                           \
  TYPE& operator= (const TYPE&)

/// WIN32 dll export
# if defined (_WIN32)
#  define YAPOG_LIB __declspec (dllexport)
# else
#  define YAPOG_LIB
# endif // _WIN32
} // namespace yap

#endif // YAPOG_MACROS_HPP
