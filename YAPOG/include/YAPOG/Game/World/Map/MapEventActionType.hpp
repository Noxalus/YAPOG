#ifndef YAPOG_MAPEVENTACTIONTYPE_HPP
# define YAPOG_MAPEVENTACTIONTYPE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  enum class MapEventActionType : UInt8
  {
    Enter,
    In,
    Leave
  };
} // namespace yap

#endif // YAPOG_MAPEVENTACTIONTYPE_HPP
