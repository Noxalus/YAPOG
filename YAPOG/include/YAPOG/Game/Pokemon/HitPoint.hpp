#ifndef YAPOG_HITPOINT_HPP
# define YAPOG_HITPOINT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/BaseStat.hpp"

namespace yap
{
  class YAPOG_LIB HitPoint : public BaseStat
  {
    DISALLOW_COPY (HitPoint);

    public:
      HitPoint ();
      HitPoint (UInt16 value);

      UInt16& GetCurrentValue ();
  private:
    UInt16 currentValue_;
  };
} // namespace yap

#endif // YAPOG_HITPOINT_HPP
