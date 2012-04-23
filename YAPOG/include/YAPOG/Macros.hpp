#ifndef YAPOG_MACROS_HPP
# define YAPOG_MACROS_HPP

/// Disallowing copy
# define DISALLOW_COPY(TYPE)                    \
  private:                                      \
  TYPE (const TYPE&);                           \
  TYPE& operator= (const TYPE&)

# define DISALLOW_ASSIGN(TYPE)                  \
  private:                                      \
  TYPE& operator= (const TYPE&)

/// WIN32 dll export
# if defined (_WIN32)
#  define YAPOG_LIB __declspec (dllexport)
# else
#  define YAPOG_LIB
# endif // _WIN32

#endif // YAPOG_MACROS_HPP
