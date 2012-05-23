#ifndef YAPOG_CLIENT_BATTLE_HPP
# define YAPOG_CLIENT_BATTLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Battle.hpp"

namespace ycl
{
  class Battle : public yap::Battle
  {
  public:
    Battle (yap::IBattleEntity& playerTeam, yap::IBattleEntity& opponent);
    virtual ~Battle ();
  };
} // namespace ycl

#endif // YAPOG_CLIENT_WILDBATTLE_HPP
