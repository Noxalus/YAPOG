#ifndef YAPOG_TRAINERBATTLE_HPP
# define YAPOG_TRAINERBATTLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Battle.hpp"
# include "YAPOG/Game/Pokemon/PokemonStat.hpp"
# include "YAPOG/Game/Pokemon/PokemonTeam.hpp"

namespace yap
{
  class YAPOG_LIB TrainerBattle : public Battle
  {
  public:
    TrainerBattle ();

    virtual void DisplayBeginMessage ();
  };
} // namespace yap

#endif // YAPOG_TRAINERBATTLE_HPP
