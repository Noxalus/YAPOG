#ifndef YAPOG_WILDBATTLE_HPP
# define YAPOG_WILDBATTLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/PokemonStat.hpp"
# include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
# include "YAPOG/Game/Pokemon/Pokemon.hpp"

namespace yap
{
  class YAPOG_LIB WildBattle
  {
  public:
    WildBattle (PokemonTeam& playerTeam, 
      Pokemon* wildPokemon);

    void Run ();
    void DisplayMoves ();
    void DisplayTeam ();

  private:
    PokemonTeam& playerTeam_;
    Pokemon* wildPokemon_;
    Pokemon* currentPokemon_;
    int turnCount_;
  };
} // namespace yap

#endif // YAPOG_WILDBATTLE_HPP
