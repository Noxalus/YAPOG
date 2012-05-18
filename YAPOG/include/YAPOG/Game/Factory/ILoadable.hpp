#ifndef YAPOG_ILOADABLE_HPP
# define YAPOG_ILOADABLE_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  /// @brief Interface for object that can be loaded from external resource.
  struct YAPOG_LIB ILoadable
  {
      virtual ~ILoadable () {}
  };
} // namespace yap

#endif // YAPOG_ILOADABLE_HPP
