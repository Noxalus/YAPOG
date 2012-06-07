#ifndef YAPOG_CLIENT_POKEMONBATTLEINFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONBATTLEINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"

# include "Battle/BattleInfoWidget.hpp"

namespace ycl
{
  class PokemonBattleInfoWidget : public BattleInfoWidget
  {
    DISALLOW_COPY (PokemonBattleInfoWidget);

  public:
    PokemonBattleInfoWidget ();
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONBATTLEINFOWIDGET_HPP
