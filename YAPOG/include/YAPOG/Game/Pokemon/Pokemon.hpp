#ifndef YAPOG_POKEMON_HPP
# define YAPOG_POKEMON_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"
# include "YAPOG/Game/Pokemon/Type.hpp"
# include "YAPOG/Game/Pokemon/Status.hpp"
# include "YAPOG/Game/Pokemon/Skill.hpp"

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
     int hp_;
     int max_hp_;
     int atk_;
     int dfe_;
     int spd_;
     int ats_;
     int dfs_;
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

