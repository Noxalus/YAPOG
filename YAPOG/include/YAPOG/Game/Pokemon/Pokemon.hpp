#ifndef YAPOG_POKEMON_HPP
# define YAPOG_POKEMON_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"
# include "YAPOG/Game/Pokemon/Status.hpp"
# include "YAPOG/Game/Pokemon/PokemonStat.hpp"
# include "YAPOG/Game/Pokemon/PokemonType.hpp"
# include "YAPOG/Game/Pokemon/PokemonSkill.hpp"
# include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
# include "YAPOG/Game/Pokemon/PokemonExperience.hpp"
# include "YAPOG/Game/Pokemon/NatureInfo.hpp"
# include "YAPOG/System/Path.hpp"

namespace yap
{
  class YAPOG_LIB Pokemon
  {
    DISALLOW_COPY (Pokemon);

  public:
    Pokemon (const ID& staticID);
    Pokemon (
      const ID& staticID, 
      const UInt16& level, 
      const bool& shiny);

    /// Getters
    const ID& GetUniqueID () const;
    const ID& GetStaticID () const;
    const String& GetName () const;
    const TypeInfo& GetType1 () const;
    const TypeInfo& GetType2 () const;
    float GetTypeEffectFactor (const TypeInfo& type) const;
    const uint& GetTotalExperience () const;
    const uint& GetExperienceToNextLevel () const;
    const UInt16& GetLevel () const;
    const bool GetShiny () const;
    const Int16& GetLoyalty () const;
    const yap::ID& GetNature () const;
    const PokemonStat& GetStats () const;
    const Gender& GetGender () const;
    UInt16 GetCurrentHP () const;
    UInt16 GetMaxHP () const;
    const collection::Array<PokemonSkill*>& GetMoves () const;
    const String& GetIconPath () const;

    /// Setters
    void SetUniqueID (const ID& value);
    void SetExperience (const UInt32& value);
    void SetGender (const UInt8& value);
    void SetNickname (const String& value);
    void SetLevel (const UInt16& value);
    void SetShiny (bool value);
    void SetLoyalty (int value);
    void SetNature (const ID& value);

    bool LearnSkill (const ID& skillID);
    void ReplaceSkill (const ID& skillID, int index);

    /// @brief Restore all the hp of the Pokemon
    void RestoreHP ();
    void TakeDamage (int damage);

    void AddExperience (const Int32& value);

    void PrintStats ();

    static const int MAX_POKEMON_MOVE_NUMBER;

  protected:
    ID uniqueID_;
    ID staticID_;
    String nickname_;
    PokemonStat stats_;
    UInt16 level_;
    PokemonType type_;
    Gender gender_;
    Status status_;
    bool shiny_;
    Int16 loyalty_;
    collection::Array<PokemonSkill*> moveSet_;
    PokemonInfo* pokemonInfo_;
    NatureInfo* nature_;
    PokemonExperience* exp_;
  private:
    void Init ();
    void InitExperience ();
    void InitMoveSet ();
    void Reset ();
    void Evolve ();
    void SpecifyGender ();
  };
} // namespace yap

#endif // YAPOG_POKEMON_HPP

