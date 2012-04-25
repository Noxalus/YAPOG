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
  private:
    int currentHP_;
  };
} // namespace yap

#endif // YAPOG_HITPOINT_HPP
