#ifndef YAPOG_POKEMONINFO_HPP
# define YAPOG_POKEMONINFO_HPP

# include <iostream>
# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Game/Factory/IIDLoadable.hpp"

namespace yap
{
  class YAPOG_LIB PokemonInfo : public IIDLoadable
  {
  public:
    PokemonInfo ();
    PokemonInfo (const ID& id);

    /// @name ICloneable members.
    /// @{
    virtual PokemonInfo* Clone () const;
    /// @}

    void SetID (const ID& id);
    void SetName (const String& name);
    void SetDescription (const String& description);
    void SetSpecies (const String& species);
    void SetHeight (const float& value);
    void SetWeight (const float& value);
    void SetExperience (const int& value);
    void SetRarity (const int& value);
    void SetHitPoint (const int& value);
    void SetAttack (const int& value);
    void SetDefense (const int& value);
    void SetSpecialAttack (const int& value);
    void SetSpecialDefense (const int& value);
    void SetSpeed (const int& value);
    void SetType1 (const int& value);
    void SetType2 (const int& value);

    const ID& GetID () const;
    const String& GetName () const;
    const String& GetDescription () const;
    const String& GetSpecies () const;
    const float& GetHeight () const;
    const float& GetWeight () const;
    const int& GetExperience () const;
    const int& GetRarity () const;
    const int& GetHitPoint () const;
    const int& GetAttack () const;
    const int& GetDefense () const;
    const int& GetSpecialAttack () const;
    const int& GetSpecialDefense () const;
    const int& GetSpeed () const;
    const int& GetType1 () const;
    const int& GetType2 () const;

    void PrintBaseStats ();

  protected:
    PokemonInfo (const PokemonInfo& copy);

  private:
    ID pokedexID_;
    String name_;
    String description_;
    String species_;
    float height_;
    float weight_;
    int experience_;
    int rarity_;
    int baseHitPoint_;
    int baseAttack_;
    int baseDefense_;
    int baseSpecialAttack_;
    int baseSpecialDefense_;
    int baseSpeed_;
    int type1_;
    int type2_;

    static const int INITIAL_BASE_STATS_VALUE;
  };
} // namespace yap

#endif // YAPOG_POKEMONINFO_HPP

