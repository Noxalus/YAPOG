#ifndef YAPOG_BASESTAT_HPP
# define YAPOG_BASESTAT_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class YAPOG_LIB BaseStat
  {
    public:
      BaseStat ();
      int GetValue ();
  protected:
    int value_;
  };
} // namespace yap

#endif // YAPOG_BASESTAT_HPP