#ifndef YAPOG_ILOADABLE_HPP
# define YAPOG_ILOADABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/ICloneable.hpp"

namespace yap
{
  /// @brief Interface for object that can be loaded from external resource.
  struct YAPOG_LIB ILoadable : public ICloneable
  {
      virtual ~ILoadable () {}
  };
} // namespace yap

#endif // YAPOG_ILOADABLE_HPP