#ifndef YAPOG_IIDLOADABLE_HPP
# define YAPOG_IIDLOADABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/ICloneable.hpp"

namespace yap
{
  /// @brief Interface for object that can be loaded from external resource
  /// by an ID.
  struct YAPOG_LIB IIDLoadable : public ICloneable
  {
      virtual ~IIDLoadable () {}
  };
} // namespace yap

#endif // YAPOG_IIDLOADABLE_HPP
