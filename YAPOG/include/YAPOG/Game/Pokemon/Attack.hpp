#ifndef YAPOG_ATTACK_HPP
# define YAPOG_ATTACK_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/BaseStat.hpp"

namespace yap
{
  class YAPOG_LIB Attack : public BaseStat
  {
    DISALLOW_COPY (Attack);

  public:
    Attack ();
    Attack (UInt16 value);
  };
} // namespace yap

#endif // YAPOG_ATTACK_HPP
