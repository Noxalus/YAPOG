#ifndef YAPOG_CLIENT_BATTLEPARAMETERS_HPP
# define YAPOG_CLIENT_BATTLEPARAMETERS_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/BattleParameters.hpp"

namespace ycl
{
  class BattleParameters : public yap::BattleParameters
  {
    DISALLOW_COPY (BattleParameters);

  public:
    BattleParameters ();
    virtual ~BattleParameters ();
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEPARAMETERS_HPP
