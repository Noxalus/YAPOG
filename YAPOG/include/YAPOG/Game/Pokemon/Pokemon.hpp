#ifndef YAPOG_POKEMON_HPP
# define YAPOG_POKEMON_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"
# include "YAPOG/Game/Pokemon/Type.hpp"
# include "YAPOG/Game/Pokemon/Status.hpp"
# include "YAPOG/Game/Pokemon/Skill.hpp"
# include "YAPOG/Game/Pokemon/HitPoint.hpp"
# include "YAPOG/Game/Pokemon/Attack.hpp"
# include "YAPOG/Game/Pokemon/Defense.hpp"
# include "YAPOG/Game/Pokemon/SpecialAttack.hpp"
# include "YAPOG/Game/Pokemon/SpecialDefense.hpp"
# include "YAPOG/Game/Pokemon/Speed.hpp"

namespace yap
{
  class YAPOG_LIB Pokemon
  {
    public:
      Pokemon ();
    private:
     ID uniqueId_;
     ID pokedexId_;
     String name_;
     String nickname_;
     int level_;
     int exp_;
     HitPoint hp_;
     Attack atk_;
     Defense dfe_;
     Speed spd_;
     SpecialAttack ats_;
     SpecialDefense dfs_;
     Type type1_;
     Type type2_;
     Status status_;
     Gender gender_;
     bool shiny_;
     Int16 loyalty_;
     Skill moveSet[4];
  };
} // namespace yap

#endif // YAPOG_POKEMON_HPP

