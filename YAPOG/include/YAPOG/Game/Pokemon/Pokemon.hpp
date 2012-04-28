#ifndef YAPOG_POKEMON_HPP
# define YAPOG_POKEMON_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"
# include "YAPOG/Game/Pokemon/PokemonType.hpp"
# include "YAPOG/Game/Pokemon/Status.hpp"
# include "YAPOG/Game/Pokemon/PokemonStat.hpp"
# include "YAPOG/Game/Pokemon/PokemonSkill.hpp"
# include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
# include "YAPOG/Game/Pokemon/NatureInfo.hpp"
# include "YAPOG/Game/Pokemon/PokemonExperience.hpp"
# include "YAPOG/System/Path.hpp"

namespace yap
{
  class YAPOG_LIB Pokemon
  {
    DISALLOW_COPY (Pokemon);

    public:
      Pokemon (const ID& staticID);
      Pokemon (const ID& staticID, const UInt16& level, const bool& shiny);

      const String& GetName () const;
      float GetTypeEffectFactor (const TypeInfo& type) const;
      const UInt32& GetTotalExperience () const;
      const UInt32& GetExperienceToNextLevel () const;
      const UInt16& GetLevel () const;

      void AddExperience (const Int32& value);

      void PrintStats ();
    private:
     ID uniqueID_;
     ID staticID_;
     String nickname_;
     PokemonStat stats_;
     PokemonType type_;
     Status status_;
     Gender gender_;
     bool shiny_;
     Int16 loyalty_;
     PokemonSkill moveSet[4];
     PokemonInfo* pokemonInfo_;
     NatureInfo* nature_;
     PokemonExperience* exp_;

     static const UInt16 POKEMON_INITIAL_LEVEL;
  };
} // namespace yap

#endif // YAPOG_POKEMON_HPP

