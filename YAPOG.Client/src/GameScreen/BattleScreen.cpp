#include "YAPOG/System/RandomHelper.hpp"

#include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
#include "YAPOG/Game/Battle/PokemonFighter.hpp"
#include "YAPOG/Game/Battle/PokemonFighterTeam.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"

#include "GameScreen/BattleScreen.hpp"
#include "TestGame.hpp"
#include "Battle/WildBattle.hpp"
#include "Battle/BattleInterface.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  const yap::ScreenType BattleScreen::DEFAULT_NAME = "Battle";

  Pokemon* GeneratePokemon ()
  {
    yap::ID staticID = yap::ID (yap::RandomHelper::GetNext (1, 4));

    if (staticID == yap::ID (4))
      staticID = yap::ID (16);

    int level = yap::RandomHelper::GetNext (1, 100);

    Pokemon* p = new Pokemon (staticID, level, false);

    return p;
  }

  BattleScreen::BattleScreen ()
    : BaseScreen (DEFAULT_NAME)
    , battleInterface_ (nullptr)
  {
  }

  BattleScreen::~BattleScreen ()
  {
  }

  void BattleScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();

    yap::PokemonTeam team;
    team.AddPokemon (new yap::Pokemon (yap::ID (2), 42, false));
    team.AddPokemon (new yap::Pokemon (yap::ID (16), 32, true));

    yap::PokemonFighter wildPokemon (GeneratePokemon ());
    yap::PokemonFighterTeam playerFighterTeam (team);

    team.GetPokemon (0)->PrintStats ();
    std::cout << "---------- Fighter ----------" << std::endl;
    playerFighterTeam.GetPokemon (0)->PrintBattleStats ();

    battle_ = new WildBattle (playerFighterTeam, wildPokemon);
    battle_->Init ();

    /*
    battleInterface_ = new BattleInterface ();
    
    guiManager_->AddChild (*battleInterface_);
    */
  }

  const yap::ScreenType& BattleScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    return BaseScreen::HandleRun (dt, context);
  }

} // namespace ycl
