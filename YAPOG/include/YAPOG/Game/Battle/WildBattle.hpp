#ifndef YAPOG_WILDBATTLE_HPP
# define YAPOG_WILDBATTLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Battle.hpp"
# include "YAPOG/Game/Pokemon/PokemonStat.hpp"
# include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
# include "YAPOG/Game/Pokemon/Pokemon.hpp"

namespace yap
{
  class YAPOG_LIB WildBattle : public Battle
  {
  public:
    WildBattle (PokemonTeam& playerTeam, 
      Pokemon* wildPokemon);

    virtual void DisplayBeginMessage ();

  private:
    Pokemon* wildPokemon_;
  };
} // namespace yap

#endif // YAPOG_WILDBATTLE_HPP
