#ifndef YAPOG_CLIENT_POKEMONFIGHTER_HPP
# define YAPOG_CLIENT_POKEMONFIGHTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/Battle/PokemonFighter.hpp"

# include "Battle/IDrawableBattleEntity.hpp"

namespace ycl
{
  class Pokemon;

  class PokemonFighter 
    : public yap::PokemonFighter
    , public virtual IDrawableBattleEntity
  {
    DISALLOW_COPY (PokemonFighter);

  public:
    PokemonFighter (Pokemon* originalPokemon);
    virtual ~PokemonFighter ();

    /// @name IDrawableBattleEntity members
    /// @{
    virtual yap::ISprite& GetFrontSprite ();
    virtual yap::ISprite& GetBackSprite ();
    /// @}

  private:
    Pokemon* originalPokemon_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONFIGHTER_HPP
