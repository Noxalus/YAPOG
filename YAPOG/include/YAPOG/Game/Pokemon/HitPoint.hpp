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

      const UInt16& GetCurrentValue () const;

      virtual void SetValue (const UInt16& value);
      void SetCurrentValue (const UInt16& value);
  private:
    UInt16 currentValue_;
    static const UInt16 INITIAL_CURRENT_VALUE;
  };
} // namespace yap

#endif // YAPOG_HITPOINT_HPP
