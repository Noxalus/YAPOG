#ifndef YAPOG_SPECIALDEFENSE_HPP
# define YAPOG_SPECIALDEFENSE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/BaseStat.hpp"

namespace yap
{
  class YAPOG_LIB SpecialDefense : public BaseStat
  {
    DISALLOW_COPY (SpecialDefense);

    public:
      SpecialDefense ();
      SpecialDefense (UInt16 value);
  };
} // namespace yap

#endif // YAPOG_SPECIALDEFENSE_HPP