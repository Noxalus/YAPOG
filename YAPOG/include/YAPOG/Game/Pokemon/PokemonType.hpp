#ifndef YAPOG_POKEMONTYPE_HPP
# define YAPOG_POKEMONTYPE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/TypeInfo.hpp"

namespace yap
{
  class YAPOG_LIB PokemonType
  {
    public:
      PokemonType ();
      PokemonType (const ID& type1, const ID& type2);

      /// Getters
      const TypeInfo& GetType1 () const;
      const TypeInfo& GetType2 () const;

      /// Setters
      void SetType1 (const ID& typeID);
      void SetType2 (const ID& typeID);

  private:
    TypeInfo* type1_;
    TypeInfo* type2_;

    static const ID DEFAULT_TYPE_ID;
  };
} // namespace yap

#endif // YAPOG_POKEMONTYPE_HPP
