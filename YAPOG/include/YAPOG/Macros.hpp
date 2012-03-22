#ifndef YAPOG_MACROS_HPP
# define YAPOG_MACROS_HPP

# include <memory>

namespace yap
{
/// Disallowing copy
# define DISALLOW_COPY(TYPE)         \
  TYPE (const TYPE&) = delete;                  \
  TYPE& operator= (const TYPE&) = delete

/// WIN32 dll export
# if defined (_WIN32)
#  define YAPOG_LIB __declspec (dllexport)
# else
#  define YAPOG_LIB
# endif

/// Pointer type
  namespace
  {
# define PTR_TYPE_NAME                          \
    PtrType
# define PTR_TYPE(TYPE)                         \
    std::shared_ptr<TYPE>
  } // namespace
# define DECLARE_PTR_TYPE(TYPE)                 \
  typedef PTR_TYPE(TYPE) PTR_TYPE_NAME
} // namespace yap

#endif // YAPOG_MACROS_HPP
