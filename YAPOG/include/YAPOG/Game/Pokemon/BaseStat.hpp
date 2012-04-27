#ifndef YAPOG_BASESTAT_HPP
# define YAPOG_BASESTAT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class YAPOG_LIB BaseStat
  {
    DISALLOW_COPY (BaseStat);

    public:
      BaseStat ();
      BaseStat (UInt16 value);

      UInt16 GetValue ();
  protected:
    UInt16 value_;
    UInt16 individualValue_;
    UInt16 effortValue_;

    static const UInt16 INITIAL_STAT_VALUE;
  };
} // namespace yap

#endif // YAPOG_BASESTAT_HPP