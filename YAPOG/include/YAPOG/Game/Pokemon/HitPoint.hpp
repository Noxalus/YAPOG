#ifndef YAPOG_HITPOINT_HPP
# define YAPOG_HITPOINT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/BaseStat.hpp"

namespace yap
{
  class YAPOG_LIB HitPoint : public BaseStat
  {
    public:
      HitPoint ();
      HitPoint (const UInt16& currentValue, const UInt16& ev, const UInt16& iv);

      UInt16 GetCurrentValue () const;
      float GetHPPercentage () const;

      void SetCurrentValue (const UInt16& value);

      void Restore ();
  private:
    UInt16 currentValue_;
    static const UInt16 INITIAL_CURRENT_VALUE;
  };
} // namespace yap

#endif // YAPOG_HITPOINT_HPP
