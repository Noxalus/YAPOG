#ifndef YAPOG_BATTLE_HPP
# define YAPOG_BATTLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/PokemonStat.hpp"
# include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
# include "YAPOG/Game/Battle/PokemonFighter.hpp"

namespace yap
{
  class YAPOG_LIB Battle
  {
  public:
    Battle (PokemonTeam& playerTeam);

    void Init ();
    void Run ();
    void DisplayMoves ();
    void DisplayTeam ();
    virtual void DisplayBeginMessage () = 0;

  protected:
    PokemonTeam& playerTeam_;
    PokemonFighter currentOpponent_;
    PokemonFighter currentPokemon_;
    int turnCount_;
  };
} // namespace yap

#endif // YAPOG_BATTLE_HPP
