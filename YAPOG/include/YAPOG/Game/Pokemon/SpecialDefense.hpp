#ifndef YAPOG_SPECIALDEFENSE_HPP
# define YAPOG_SPECIALDEFENSE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/BaseStat.hpp"

namespace yap
{
  class YAPOG_LIB SpecialDefense : public BaseStat
  {
    public:
      SpecialDefense ();
      SpecialDefense (const UInt16& ev, const UInt16& iv);
      SpecialDefense (const UInt16& iv);
  };
} // namespace yap

#endif // YAPOG_SPECIALDEFENSE_HPP