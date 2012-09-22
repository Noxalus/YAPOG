#ifndef YAPOG_CLIENT_POKEMON_HPP
# define YAPOG_CLIENT_POKEMON_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/Pokemon.hpp"

namespace yap
{
  struct ISprite;
  class PokemonMoveSet;
}

namespace ycl
{
  class PokemonInfo;

  class Pokemon : public yap::Pokemon
  {
    DISALLOW_COPY (Pokemon);

  public:
    Pokemon (const yap::ID& staticID);

    Pokemon (
      const yap::ID& staticID, 
      const yap::UInt16& level, 
      const bool& shiny);

    Pokemon (
      const yap::ID& uniqueID,
      const yap::ID& staticID,
      const yap::String& trainerName,
      const yap::String& nickname,
      const yap::PokemonStat& stats,
      const yap::Gender& gender,
      const yap::PokemonStatus& status,
      const bool shiny,
      const yap::Int16& loyalty,
      const yap::PokemonMoveSet& moveSet,
      const yap::ID& natureID,
      const yap::uint& exp,
      const yap::UInt8& boxNumber,
      const yap::ID& boxIndex,
      const yap::String& catchDate);

    Pokemon (
      const yap::ID& staticID,
      const yap::PokemonStat& stats,
      const yap::Gender& gender,
      const bool shiny,
      const yap::PokemonMoveSet& moveSet,
      const yap::ID& natureID,
      const yap::uint& exp);

    virtual ~Pokemon ();

    /// Getters
    yap::ISprite& GetIcon () const;
    yap::ISprite& GetGenderIcon () const;
    yap::ISprite& GetBattleBack () const;
    yap::ISprite& GetBattleFront () const;
    yap::ISprite& GetType1Icon () const;
    yap::ISprite& GetType2Icon () const;

    void PlayCry ();

  private:
    void Init ();
    void LoadSprites ();

    yap::ISprite* icon_;
    yap::ISprite* genderIcon_;
    yap::ISprite* battleBack_;
    yap::ISprite* battleFront_;
    yap::ISprite* type1Icon_;
    yap::ISprite* type2Icon_;

    PokemonInfo* graphicPokemonInfo_;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMON_HPP

