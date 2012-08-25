#ifndef YAPOG_CLIENT_POKEMON_HPP
# define YAPOG_CLIENT_POKEMON_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/Pokemon.hpp"

namespace yap
{
  class ISprite;
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
    virtual ~Pokemon ();

    /// Getters
    yap::ISprite& GetIcon () const;
    yap::ISprite& GetGenderIcon () const;
    yap::ISprite& GetBattleBack () const;
    yap::ISprite& GetBattleFront () const;

  private:
    void Init ();
    void LoadSprites ();

    yap::ISprite* icon_;
    yap::ISprite* genderIcon_;
    yap::ISprite* battleBack_;
    yap::ISprite* battleFront_;

    PokemonInfo* graphicPokemonInfo_;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMON_HPP

