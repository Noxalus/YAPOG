#ifndef YAPOG_LESSCOMPARATOR_HPP
# define YAPOG_LESSCOMPARATOR_HPP

# include <algorithm>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IComparator.hpp"

namespace yap
{
  template <typename T>
  class LessComparator : public std::less<T>
                       , public IComparator<T>
  {
      DISALLOW_COPY(LessComparator);

    public:

      LessComparator ();
      virtual ~LessComparator ();

      bool operator() (const T& left, const T& right) const;

      /// @name IComparator members.
      /// @{
      virtual int Compare (const T& left, const T& right) const;
      /// @}

    protected:

      virtual int HandleCompare (const T& left, const T& right) const = 0;
  };
} // namespace yap

# include "YAPOG/System/LessComparator.hxx"

#endif // YAPOG_LESSCOMPARATOR_HPP
