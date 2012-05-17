#ifndef YAPOG_DEFENSE_HPP
# define YAPOG_DEFENSE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/BaseStat.hpp"

namespace yap
{
  class YAPOG_LIB Defense : public BaseStat
  {
    public:
      Defense ();
      Defense (UInt16 value);
  };
} // namespace yap

#endif // YAPOG_DEFENSE_HPP
