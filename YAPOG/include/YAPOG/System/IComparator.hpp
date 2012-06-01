#ifndef YAPOG_ICOMPARATOR_HPP
# define YAPOG_ICOMPARATOR_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  template <typename T>
  struct IComparator
  {
      virtual ~IComparator () { }

      virtual int Compare (const T& left, const T& right) const = 0;
  };
} // namespace yap

#endif // YAPOG_ICOMPARATOR_HPP
