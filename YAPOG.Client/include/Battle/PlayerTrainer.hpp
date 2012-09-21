#ifndef YAPOG_CLIENT_PLAYERTRAINER_HPP
# define YAPOG_CLIENT_PLAYERTRAINER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/Battle/PlayerTrainer.hpp"

# include "Battle/BattleParameters.hpp"

namespace yap
{
  class Pokedex;
}

namespace ycl
{
  class BattleInterface;
  //class PokemonFighterTeam;
  class PokemonTeam;

  class PlayerTrainer : public yap::PlayerTrainer
  {
  public:
    PlayerTrainer ();
    virtual ~PlayerTrainer ();

    /// @name Getters.
    /// @{
    //PokemonFighterTeam& GetTeam ();
    PokemonTeam& GetTeam ();
    yap::UInt32 GetPokemonCaughtCount () const;
    BattleParameters& GetBattleParameters () const;
    /// @}

    /// @name Setters.
    /// @{
    //void SetTeam (PokemonFighterTeam* value);
    void SetTeam (PokemonTeam* value);
    void SetPokedex (yap::Pokedex* value);
    void SetBattleParameters (BattleParameters* value);
    /// @}

  private:
    //PokemonFighterTeam* team_;
    PokemonTeam* team_;
    yap::Pokedex* pokedex_;
    BattleParameters* battleParameters_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_PLAYERTRAINER_HPP
