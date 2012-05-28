#include "YAPOG/System/RandomHelper.hpp"

#include "YAPOG/Graphics/Gui/GuiManager.hpp"

#include "GameScreen/BattleScreen.hpp"
#include "TestGame.hpp"
#include "Battle/WildBattle.hpp"
#include "Battle/BattleInterface.hpp"
#include "Pokemon/Pokemon.hpp"
#include "Pokemon/PokemonTeam.hpp"
#include "Battle/PokemonFighter.hpp"
#include "Battle/PokemonFighterTeam.hpp"

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
    p->LoadSprites ();

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

    PokemonTeam team;
    team.AddPokemon (new Pokemon (yap::ID (2), 42, false));
    team.AddPokemon (new Pokemon (yap::ID (16), 32, true));

    PokemonFighter wildPokemon (GeneratePokemon ());
    PokemonFighterTeam playerFighterTeam;
    playerFighterTeam.AddPokemon (new PokemonFighter (team.GetPokemon(0)));
    playerFighterTeam.AddPokemon (new PokemonFighter (team.GetPokemon(1)));

    /*
    team.GetPokemon (0)->PrintStats ();
    std::cout << "---------- Fighter ----------" << std::endl;
    playerFighterTeam.GetPokemon (0)->PrintBattleStats ();
    */

    battleInterface_ = new BattleInterface ();

    battle_ = new WildBattle (*battleInterface_);
    battle_->SetDrawablePlayerTeam (&playerFighterTeam);
    battle_->SetDrawableOpponent (&wildPokemon);
    battle_->Init ();

    guiManager_->AddChild (*battleInterface_);
  }

  const yap::ScreenType& BattleScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    battle_->Update (dt);
    battle_->Draw (context);

    return BaseScreen::HandleRun (dt, context);
  }

} // namespace ycl
