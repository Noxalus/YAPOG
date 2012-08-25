#ifndef YAPOG_MACROS_HPP
# define YAPOG_MACROS_HPP

# ifndef YAPOG_TRUE
#  define YAPOG_TRUE 1
# endif // YAPOG_TRUE

# ifndef YAPOG_FALSE
#  define YAPOG_FALSE 0
# endif // YAPOG_FALSE

/// Disallowing copy
# define DISALLOW_COPY(TYPE)                    \
  private:                                      \
  TYPE (const TYPE&);                           \
  TYPE& operator= (const TYPE&)

# define DISALLOW_ASSIGN(TYPE)                  \
  private:                                      \
  TYPE& operator= (const TYPE&)

# ifdef _WIN32
#  define YAPOG_WIN
# else
#  define YAPOG_LINUX
# endif // _MSC_VER

/// WIN32 dll export
# ifdef YAPOG_WIN
#  define YAPOG_LIB_EXPORT __declspec(dllexport)
#  define YAPOG_LIB_IMPORT __declspec(dllimport)
#  ifdef DLLEXPORT
#   define YAPOG_LIB YAPOG_LIB_EXPORT
#  else
#   define YAPOG_LIB YAPOG_LIB_IMPORT
#  endif  // DLLEXPORT
# else
#  define YAPOG_LIB
# endif // YAPOG_WIN

# ifdef YAPOG_WIN
#  pragma warning(disable : 4251)
#  pragma warning(disable : 4275)
# endif

# define YAPOG_MOVE_PREDICTION YAPOG_FALSE

// Temporary
#include <iostream>

#endif // YAPOG_MACROS_HPP
