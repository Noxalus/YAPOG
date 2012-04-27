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
      BaseStat (const UInt16& value);
      BaseStat (const UInt16& value, const UInt16& iv, const UInt16& ev);

      UInt16 GetValue ();
  protected:
    UInt16 value_;
    UInt16 individualValue_;
    UInt16 effortValue_;

    static const UInt16 INITIAL_STAT_VALUE;
    static const UInt16 INITIAL_INDIVIDUAL_VALUE;
    static const UInt16 INITIAL_EFFORT_VALUE;
  };
} // namespace yap

#endif // YAPOG_BASESTAT_HPP