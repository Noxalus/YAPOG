#ifndef YAPOG_POKEMON_HPP
# define YAPOG_POKEMON_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"
# include "YAPOG/Game/Pokemon/PokemonStatus.hpp"
# include "YAPOG/Game/Pokemon/PokemonStat.hpp"
# include "YAPOG/Game/Pokemon/PokemonType.hpp"
# include "YAPOG/Game/Pokemon/PokemonMove.hpp"
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

    Pokemon (
      const ID& uniqueID,
      const ID& staticID,
      const String& nickname,
      const PokemonStat& stats,
      const Gender& gender,
      const PokemonStatus& status,
      const bool shiny,
      const Int16& loyalty,
      const collection::Array<PokemonMove*>& moveSet,
      const ID& natureID,
      const uint& exp,
      const UInt8& boxNumber,
      const ID& boxIndex,
      const String& catchDate);

    /// Getters
    const ID& GetUniqueID () const;
    const ID& GetStaticID () const;
    const String& GetName () const;
    const String& GetNickname () const;
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
    const PokemonStatus& GetStatus () const;
    const yap::UInt8& GetBoxNumber () const;
    const yap::ID& GetBoxIndex () const;
    const yap::String& GetCatchDate () const;
    UInt16 GetCurrentHP () const;
    UInt16 GetMaxHP () const;
    const collection::Array<PokemonMove*>& GetMoves () const;
    const String& GetIconPath () const;

    ///

    bool LearnSkill (const ID& skillID);
    void ReplaceSkill (const ID& skillID, int index);

    /// @brief Restore all the hp of the Pokemon
    void RestoreHP ();
    void TakeDamage (int damage);

    void AddExperience (const Int32& value);

    void PrintStats ();

    static const int MAX_POKEMON_MOVE_NUMBER;
    static const ID DEFAULT_NATURE_ID;
    static const UInt32 DEFAULT_EXPERIENCE_AMOUNT;

  protected:
    ID uniqueID_;
    ID staticID_;
    String nickname_;
    PokemonStat stats_;
    PokemonType type_;
    Gender gender_;
    PokemonStatus status_;
    bool shiny_;
    Int16 loyalty_;
    collection::Array<PokemonMove*> moveSet_;
    PokemonInfo* pokemonInfo_;
    NatureInfo* nature_;
    PokemonExperience* exp_;
    UInt8 boxNumber_;
    ID boxIndex_;
    String catchDate_;

  private:
    void InitExperience ();
    void InitMoveSet ();
    void Reset ();
    void Evolve ();
    void SpecifyGender ();
  };
} // namespace yap

#endif // YAPOG_POKEMON_HPP

