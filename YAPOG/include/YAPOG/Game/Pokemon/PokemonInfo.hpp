#ifndef YAPOG_POKEMONINFO_HPP
# define YAPOG_POKEMONINFO_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Game/Factory/ILoadable.hpp"

namespace yap
{
  class YAPOG_LIB PokemonInfo : public ILoadable
  {
  public:
    PokemonInfo (const ID& id);

    /// @name ICloneable members.
    /// @{
    virtual PokemonInfo* Clone () const;
    /// @}

    void SetID (const ID& id);
    void SetName (const String& name);
    void SetHitPoint (int value);
    void SetAttack (int value);

    ID& GetID ();
    String& GetName ();

  protected:
    PokemonInfo (const PokemonInfo& copy);

  private:
    ID pokedexID_;
    String name_;
    int baseHitPoint_;
    int baseAttack_;
    int baseDefense_;
    int baseSpeed_;
    int baseSpecialAttack_;
    int baseSpecialDefense_;
    int type1_;
    int type2_;
  };
} // namespace yap

#endif // YAPOG_POKEMONINFO_HPP

