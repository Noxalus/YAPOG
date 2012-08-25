#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Game/Pokemon/Pokemon.hpp"

namespace yap
{
  const int PokemonInfo::INITIAL_BASE_STATS_VALUE = 0;
  const int PokemonInfo::INITIAL_BASE_EV_VALUE = 0;
  const UInt16 PokemonInfo::MAX_MOVE_NUMBER = 4;

  PokemonInfo::PokemonInfo ()
    : pokedexID_ (ID (0))
    , name_ ("")
    , description_ ("")
    , species_ ("")
    , genderProbability_ (0.f)
    , height_ (0.f)
    , weight_ (0.f)
    , experience_ (0)
    , experienceType_ ()
    , evolutionLevel_ (0)
    , pokemonEvolutionID_ (ID (0))
    , rarity_ (255)
    , baseHitPoint_ (PokemonInfo::INITIAL_BASE_STATS_VALUE)
    , baseAttack_ (PokemonInfo::INITIAL_BASE_STATS_VALUE)
    , baseDefense_ (PokemonInfo::INITIAL_BASE_STATS_VALUE)
    , baseSpecialAttack_ (PokemonInfo::INITIAL_BASE_STATS_VALUE)
    , baseSpecialDefense_ (PokemonInfo::INITIAL_BASE_STATS_VALUE)
    , baseSpeed_ (PokemonInfo::INITIAL_BASE_STATS_VALUE)
    , hitPointEV_ (PokemonInfo::INITIAL_BASE_EV_VALUE)
    , attackEV_ (PokemonInfo::INITIAL_BASE_EV_VALUE)
    , defenseEV_ (PokemonInfo::INITIAL_BASE_EV_VALUE)
    , specialAttackEV_ (PokemonInfo::INITIAL_BASE_EV_VALUE)
    , specialDefenseEV_ (PokemonInfo::INITIAL_BASE_EV_VALUE)
    , speedEV_ (PokemonInfo::INITIAL_BASE_EV_VALUE)
    , type1_ (0)
    , type2_ (0)
    , baseSkills_ ()
    , iconPath_ ("")
    , maleFrontPath_ ("")
    , maleBackPath_ ("")
    , shinyMaleFrontPath_ ("")
    , shinyMaleBackPath_ ("")
    , femaleFrontPath_ ("")
    , femaleBackPath_ ("")
    , shinyFemaleFrontPath_ ("")
    , shinyFemaleBackPath_ ("")
  {
  }

  PokemonInfo::PokemonInfo (const ID& id)
    : pokedexID_ (id)
    , name_ ("")
    , description_ ("")
    , species_ ("")
    , genderProbability_ (0.f)
    , height_ (0.f)
    , weight_ (0.f)
    , experience_ (0)
    , experienceType_ ()
    , evolutionLevel_ (0)
    , pokemonEvolutionID_ (ID (0))
    , rarity_ (255)
    , baseHitPoint_ (PokemonInfo::INITIAL_BASE_STATS_VALUE)
    , baseAttack_ (PokemonInfo::INITIAL_BASE_STATS_VALUE)
    , baseDefense_ (PokemonInfo::INITIAL_BASE_STATS_VALUE)
    , baseSpecialAttack_ (PokemonInfo::INITIAL_BASE_STATS_VALUE)
    , baseSpecialDefense_ (PokemonInfo::INITIAL_BASE_STATS_VALUE)
    , baseSpeed_ (PokemonInfo::INITIAL_BASE_STATS_VALUE)
    , hitPointEV_ (PokemonInfo::INITIAL_BASE_EV_VALUE)
    , attackEV_ (PokemonInfo::INITIAL_BASE_EV_VALUE)
    , defenseEV_ (PokemonInfo::INITIAL_BASE_EV_VALUE)
    , specialAttackEV_ (PokemonInfo::INITIAL_BASE_EV_VALUE)
    , specialDefenseEV_ (PokemonInfo::INITIAL_BASE_EV_VALUE)
    , speedEV_ (PokemonInfo::INITIAL_BASE_EV_VALUE)
    , type1_ (0)
    , type2_ (0)
    , baseSkills_ ()
    , iconPath_ ("")
    , maleFrontPath_ ("")
    , maleBackPath_ ("")
    , shinyMaleFrontPath_ ("")
    , shinyMaleBackPath_ ("")
    , femaleFrontPath_ ("")
    , femaleBackPath_ ("")
    , shinyFemaleFrontPath_ ("")
    , shinyFemaleBackPath_ ("")
  {
  }

  PokemonInfo::PokemonInfo (const PokemonInfo& copy)
    : pokedexID_ (copy.pokedexID_)
    , name_ (copy.name_)
    , description_ (copy.description_)
    , species_ (copy.species_)
    , genderProbability_ (copy.genderProbability_)
    , height_ (copy.height_)
    , weight_ (copy.weight_)
    , experience_ (copy.experience_)
    , experienceType_ (copy.experienceType_)
    , evolutionLevel_ (copy.evolutionLevel_)
    , pokemonEvolutionID_ (copy.pokemonEvolutionID_)
    , rarity_ (copy.rarity_)
    , baseHitPoint_ (copy.baseHitPoint_)
    , baseAttack_ (copy.baseAttack_)
    , baseDefense_ (copy.baseDefense_)
    , baseSpecialAttack_ (copy.baseSpecialAttack_)
    , baseSpecialDefense_ (copy.baseSpecialDefense_)
    , baseSpeed_ (copy.baseSpeed_)
    , hitPointEV_ (copy.hitPointEV_)
    , attackEV_ (copy.attackEV_)
    , defenseEV_ (copy.defenseEV_)
    , specialAttackEV_ (copy.specialAttackEV_)
    , specialDefenseEV_ (copy.specialDefenseEV_)
    , speedEV_ (copy.speedEV_)
    , type1_ (copy.type1_)
    , type2_ (copy.type2_)
    , baseSkills_ (copy.baseSkills_)
    , iconPath_ (copy.iconPath_)
    , maleFrontPath_ (copy.maleFrontPath_)
    , maleBackPath_ (copy.maleBackPath_)
    , shinyMaleFrontPath_ (copy.shinyMaleFrontPath_)
    , shinyMaleBackPath_ (copy.shinyMaleBackPath_)
    , femaleFrontPath_ (copy.femaleFrontPath_)
    , femaleBackPath_ (copy.femaleBackPath_)
    , shinyFemaleFrontPath_ (copy.shinyFemaleFrontPath_)
    , shinyFemaleBackPath_ (copy.shinyFemaleBackPath_)
  {
  }

  PokemonInfo* PokemonInfo::Clone () const
  {
    return new PokemonInfo (*this);
  }

  void PokemonInfo::InitMoveSet (
    collection::Array<PokemonSkill*>& moveSet,
    const UInt16& level)
  {
    int i = level;
    int skillNumber = 0;
    while (i >= 1 && skillNumber < Pokemon::MAX_POKEMON_MOVE_NUMBER)
    {
      if (baseSkills_.Contains (i))
      {
        for (const ID& skillID : baseSkills_[i])
        {
          moveSet[skillNumber] = new PokemonSkill (skillID);

          if (skillNumber < Pokemon::MAX_POKEMON_MOVE_NUMBER - 1)
            skillNumber++;
        }
      }

      i--;
    }
  }

  /// Getters

  const ID& PokemonInfo::GetID () const
  {
    return pokedexID_;
  }

  const String& PokemonInfo::GetName () const
  {
    return name_;
  }

  const String& PokemonInfo::GetDescription () const
  {
    return description_;
  }

  const String& PokemonInfo::GetSpecies () const
  {
    return species_;
  }

  const float& PokemonInfo::GetGenderProbability () const
  {
    return genderProbability_;
  }

  const float& PokemonInfo::GetHeight () const
  {
    return height_;
  }

  const float& PokemonInfo::GetWeight () const
  {
    return weight_;
  }

  const int& PokemonInfo::GetExperience () const
  {
    return experience_;
  }

  const ExperienceType& PokemonInfo::GetExperienceType () const
  {
    return experienceType_;
  }

  const int& PokemonInfo::GetRarity () const
  {
    return rarity_;
  }

  const int& PokemonInfo::GetHitPoint () const
  {
    return baseHitPoint_;
  }

  const int& PokemonInfo::GetAttack () const
  {
    return baseAttack_;
  }

  const int& PokemonInfo::GetDefense () const
  {
    return baseDefense_;
  }

  const int& PokemonInfo::GetSpecialAttack () const
  {
    return baseSpecialAttack_;
  }

  const int& PokemonInfo::GetSpecialDefense () const
  {
    return baseSpecialDefense_;
  }

  const int& PokemonInfo::GetSpeed () const
  {
    return baseSpeed_;
  }

  const int& PokemonInfo::GetType1 () const
  {
    return type1_;
  }

  const int& PokemonInfo::GetType2 () const
  {
    return type2_;
  }

  const collection::List<ID>* PokemonInfo::GetNewSkills (
    const UInt16& level) const
  {
    if (baseSkills_.Contains (level))
      return &baseSkills_[level];
    else
      return nullptr;
  }

  const int& PokemonInfo::GetHitPointEV () const
  {
    return hitPointEV_;
  }

  const int& PokemonInfo::GetAttackEV () const
  {
    return attackEV_;
  }

  const int& PokemonInfo::GetDefenseEV () const
  {
    return defenseEV_;
  }

  const int& PokemonInfo::GetSpecialAttackEV () const
  {
    return specialAttackEV_;
  }

  const int& PokemonInfo::GetSpecialDefenseEV () const
  {
    return specialDefenseEV_;
  }

  const int& PokemonInfo::GetSpeedEV () const
  {
    return speedEV_;
  }

  bool PokemonInfo::CanEvolve () const
  {
    return evolutionLevel_ > 0;
  }

  const UInt16& PokemonInfo::GetEvolutionLevel () const
  {
    return evolutionLevel_;
  }
  const ID& PokemonInfo::GetPokemonEvolutionID () const
  {
    return pokemonEvolutionID_;
  }

    const yap::String& PokemonInfo::GetIconPath () const
  { return iconPath_; }

  const yap::String& PokemonInfo::GetMaleFrontPath () const
  { return maleFrontPath_; }
  const yap::String& PokemonInfo::GetMaleBackPath () const
  { return maleBackPath_; }
  const yap::String& PokemonInfo::GetShinyMaleFrontPath () const
  { return shinyMaleFrontPath_; }
  const yap::String& PokemonInfo::GetShinyMaleBackPath () const
  { return shinyMaleBackPath_; }

  const yap::String& PokemonInfo::GetFemaleFrontPath () const
  { return femaleFrontPath_; }
  const yap::String& PokemonInfo::GetFemaleBackPath () const
  { return femaleBackPath_; }
  const yap::String& PokemonInfo::GetShinyFemaleFrontPath () const
  { return shinyFemaleFrontPath_; }
  const yap::String& PokemonInfo::GetShinyFemaleBackPath () const
  { return shinyFemaleBackPath_; }

  /// Setters.

  void PokemonInfo::SetID (const ID& id)
  {
    pokedexID_ = id;
  }

  void PokemonInfo::SetName (const String& name)
  {
    name_ = name;
  }

  void PokemonInfo::SetDescription (const String& description)
  {
    description_ = description;
  }

  void PokemonInfo::SetSpecies (const String& species)
  {
    species_ = species;
  }

  void PokemonInfo::SetGenderProbability (const float& value)
  {
    genderProbability_ = value;
  }

  void PokemonInfo::SetHeight (const float& value)
  {
    height_ = value;
  }

  void PokemonInfo::SetWeight (const float& value)
  {
    weight_ = value;
  }

  void PokemonInfo::SetExperience (const int& value)
  {
    experience_ = value;
  }

  void PokemonInfo::SetExperienceType (const ExperienceType& value)
  {
    experienceType_ = value;
  }

  void PokemonInfo::SetRarity (const int& value)
  {
    rarity_ = value;
  }

  void PokemonInfo::SetHitPoint (const int& value)
  {
    baseHitPoint_ = value;
  }

  void PokemonInfo::SetAttack (const int& value)
  {
    baseAttack_ = value;
  }

  void PokemonInfo::SetDefense (const int& value)
  {
    baseDefense_ = value;
  }

  void PokemonInfo::SetSpecialAttack (const int& value)
  {
    baseSpecialAttack_ = value;
  }

  void PokemonInfo::SetSpecialDefense (const int& value)
  {
    baseSpecialDefense_ = value;
  }

  void PokemonInfo::SetSpeed (const int& value)
  {
    baseSpeed_ = value;
  }

  void PokemonInfo::SetType1 (const int& value)
  {
    type1_ = value;
  }

  void PokemonInfo::SetType2 (const int& value)
  {
    type2_ = value;
  }

  void PokemonInfo::AddBaseSkill (const UInt16 level, const ID& skillID)
  {
    if (baseSkills_.Contains (level))
      baseSkills_[level].Add (skillID);
    else
    {
      collection::List<ID> skillList;
      skillList.Add (skillID);
      baseSkills_.Add (level, skillList);
    }
  }

  void PokemonInfo::SetHitPointEV (const int& value)
  {
    hitPointEV_ = value;
  }

  void PokemonInfo::SetAttackEV (const int& value)
  {
    attackEV_ = value;
  }

  void PokemonInfo::SetDefenseEV (const int& value)
  {
    defenseEV_ = value;
  }
  void PokemonInfo::SetSpecialAttackEV (const int& value)
  {
    specialAttackEV_ = value;
  }

  void PokemonInfo::SetSpecialDefenseEV (const int& value)
  {
    specialDefenseEV_ = value;
  }

  void PokemonInfo::SetSpeedEV (const int& value)
  {
    speedEV_ = value;
  }

  void PokemonInfo::SetEvolutionLevel (UInt16 value)
  {
    evolutionLevel_ = value;
  }

  void PokemonInfo::SetPokemonEvolutionID (const ID& value)
  {
    pokemonEvolutionID_ = value;
  }

  void PokemonInfo::SetIconPath (const yap::String& value)
  { iconPath_ = value; }

  void PokemonInfo::SetMaleFrontPath (const yap::String& value)
  { maleFrontPath_ = value; }
  void PokemonInfo::SetMaleBackPath (const yap::String& value)
  { maleBackPath_ = value; }
  void PokemonInfo::SetShinyMaleFrontPath (const yap::String& value)
  { shinyMaleFrontPath_ = value; }
  void PokemonInfo::SetShinyMaleBackPath (const yap::String& value)
  { shinyMaleBackPath_ = value; }

  void PokemonInfo::SetFemaleFrontPath (const yap::String& value)
  { femaleFrontPath_ = value; }
  void PokemonInfo::SetFemaleBackPath (const yap::String& value)
  { femaleBackPath_ = value; }
  void PokemonInfo::SetShinyFemaleFrontPath (const yap::String& value)
  { shinyFemaleFrontPath_ = value; }
  void PokemonInfo::SetShinyFemaleBackPath (const yap::String& value)
  { shinyFemaleBackPath_ = value; }

  void PokemonInfo::PrintBaseStats ()
  {
    std::cout << "PokemonInfo Data: " << std::endl
      << "ID: " << pokedexID_.GetValue () << std::endl
      << "Name: " << name_ << std::endl
      << "Description: " << description_ << std::endl
      << "Species: " << species_ << std::endl
      << "Height: " << height_ << std::endl
      << "Weight: " << weight_ << std::endl
      << "Rarity: " << rarity_ << std::endl
      << "Experience: " << experience_ << std::endl
      << "---------------------------------------------" << std::endl
      << "              Base stats" << std::endl
      << "---------------------------------------------" << std::endl
      <<  "HP: " << baseHitPoint_ << std::endl
      <<  "Attack: " << baseAttack_ << std::endl
      <<  "Defense: " << baseDefense_ << std::endl
      <<  "Special Attack: " << baseSpecialAttack_ << std::endl
      <<  "Special Defense: " << baseSpecialDefense_ << std::endl
      <<  "Speed: " << baseSpeed_ << std::endl
      << "---------------------------------------------" << std::endl;
  }

  void PokemonInfo::PrintBaseSkills ()
  {
    for (const auto& skill : baseSkills_)
    {
      std::cout << skill.first << " => ";

      for (const ID& skillID : skill.second)
        std::cout << skillID.GetValue () << " ";

      std::cout << std::endl;
    }
  }
}
