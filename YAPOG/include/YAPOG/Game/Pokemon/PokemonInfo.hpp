#ifndef YAPOG_POKEMONINFO_HPP
# define YAPOG_POKEMONINFO_HPP

# include <iostream>
# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Game/Factory/IIDLoadable.hpp"
# include "YAPOG/Game/Pokemon/PokemonSkill.hpp"
# include "YAPOG/Game/Pokemon/ExperienceType.hpp"

namespace yap
{
  class YAPOG_LIB PokemonInfo : public IIDLoadable
  {
  public:
    PokemonInfo ();
    PokemonInfo (const ID& id);
    void InitMoveSet (
      collection::Array<PokemonSkill*>& moveSet,
      const UInt16& level);

    bool CanEvolve () const;

    /// @name ICloneable members.
    /// @{
    virtual PokemonInfo* Clone () const;
    /// @}

    /// @name Setters.
    /// @{
    void SetID (const ID& id);
    void SetName (const String& name);
    void SetDescription (const String& description);
    void SetSpecies (const String& species);
    void SetGenderProbability (const float& value);
    void SetHeight (const float& value);
    void SetWeight (const float& value);
    void SetExperience (const int& value);
    void SetExperienceType (const ExperienceType& value);
    void SetRarity (const int& value);
    void SetHitPoint (const int& value);
    void SetAttack (const int& value);
    void SetDefense (const int& value);
    void SetSpecialAttack (const int& value);
    void SetSpecialDefense (const int& value);
    void SetSpeed (const int& value);
    void SetHitPointEV (const int& value);
    void SetAttackEV (const int& value);
    void SetDefenseEV (const int& value);
    void SetSpecialAttackEV (const int& value);
    void SetSpecialDefenseEV (const int& value);
    void SetSpeedEV (const int& value);
    void SetType1 (const int& value);
    void SetType2 (const int& value);
    void AddBaseSkill (const UInt16 level, const ID& skillID);
    void SetEvolutionLevel (UInt16 value);
    void SetPokemonEvolutionID (const ID& value);

    void SetIconPath (const yap::String& value);

    void SetMaleFrontPath (const yap::String& value);
    void SetMaleBackPath (const yap::String& value);
    void SetShinyMaleFrontPath (const yap::String& value);
    void SetShinyMaleBackPath (const yap::String& value);

    void SetFemaleFrontPath (const yap::String& value);
    void SetFemaleBackPath (const yap::String& value);
    void SetShinyFemaleFrontPath (const yap::String& value);
    void SetShinyFemaleBackPath (const yap::String& value);
    /// @}

    /// @name Getters.
    /// @{
    const ID& GetID () const;
    const String& GetName () const;
    const String& GetDescription () const;
    const String& GetSpecies () const;
    const float& GetGenderProbability () const;
    const float& GetHeight () const;
    const float& GetWeight () const;
    const int& GetExperience () const;
    const ExperienceType& GetExperienceType () const;
    const int& GetRarity () const;
    const int& GetHitPoint () const;
    const int& GetAttack () const;
    const int& GetDefense () const;
    const int& GetSpecialAttack () const;
    const int& GetSpecialDefense () const;
    const int& GetSpeed () const;
    const int& GetHitPointEV () const;
    const int& GetAttackEV () const;
    const int& GetDefenseEV () const;
    const int& GetSpecialAttackEV () const;
    const int& GetSpecialDefenseEV () const;
    const int& GetSpeedEV () const;
    const int& GetType1 () const;
    const int& GetType2 () const;
    const collection::List<ID>* GetNewSkills (const UInt16& level) const;
    const UInt16& GetEvolutionLevel () const;
    const ID& GetPokemonEvolutionID () const;

    const yap::String& GetIconPath () const;

    const yap::String& GetMaleFrontPath () const;
    const yap::String& GetMaleBackPath () const;
    const yap::String& GetShinyMaleFrontPath () const;
    const yap::String& GetShinyMaleBackPath () const;

    const yap::String& GetFemaleFrontPath () const;
    const yap::String& GetFemaleBackPath () const;
    const yap::String& GetShinyFemaleFrontPath () const;
    const yap::String& GetShinyFemaleBackPath () const;
    /// @}

    void PrintBaseStats ();
    void PrintBaseSkills ();

    static const UInt16 MAX_MOVE_NUMBER;

  protected:
    PokemonInfo (const PokemonInfo& copy);

  private:

    ID pokedexID_;
    String name_;
    String description_;
    String species_;
    float genderProbability_;
    float height_;
    float weight_;
    int experience_;
    ExperienceType experienceType_;
    UInt16 evolutionLevel_;
    ID pokemonEvolutionID_;
    int rarity_;
    int baseHitPoint_;
    int baseAttack_;
    int baseDefense_;
    int baseSpecialAttack_;
    int baseSpecialDefense_;
    int baseSpeed_;
    int hitPointEV_;
    int attackEV_;
    int defenseEV_;
    int specialAttackEV_;
    int specialDefenseEV_;
    int speedEV_;
    int type1_;
    int type2_;
    collection::Map<UInt16, collection::List<ID>> baseSkills_;

    /// @name Graphic fields.
    /// @{
    yap::String iconPath_;

    /// @name Male Pokemon battle sprite strings.
    /// @{
    yap::String maleFrontPath_;
    yap::String maleBackPath_;
    yap::String shinyMaleFrontPath_;
    yap::String shinyMaleBackPath_;
    /// @}

    /// @name Female Pokemon battle sprite strings.
    /// @{
    yap::String femaleFrontPath_;
    yap::String femaleBackPath_;
    yap::String shinyFemaleFrontPath_;
    yap::String shinyFemaleBackPath_;
    /// @}
    
    /// @}

    static const int INITIAL_BASE_STATS_VALUE;
    static const int INITIAL_BASE_EV_VALUE;
  };
} // namespace yap

#endif // YAPOG_POKEMONINFO_HPP

