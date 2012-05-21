#include "YAPOG/Game/Battle/Battle.hpp"
#include "YAPOG/Game/Battle/BattleCore.hpp"
using namespace std;

namespace yap
{
  Battle::Battle (IBattleEntity& playerTeam, IBattleEntity& opponent)
    : playerTeam_ (playerTeam)
    , opponent_ (opponent)
    , turnCount_ (0)
    , battlePhaseManager_ ()
  {
  }

  void Battle::Init ()
  {
    battlePhaseManager_.SetBattle (this);
    HandleInit ();
  }

  void Battle::HandleInit ()
  {
  }

  void Battle::Update (const Time& dt)
  {
    HandleUpdate (dt);
    battlePhaseManager_.Update (dt);
    /*
    while (battlePhaseManager_.GetCurrentPhase () != 
      BattlePhaseState::EndBattle)
    {
      battlePhaseManager_.Update ();
    }

    /*
    BattleCore bc;

    DisplayBeginMessage ();

    cout
    << currentPokemon_.GetName ()
    <<  "! A l'attaque !"
    << endl << endl;

    while (true)
    {
    turnCount_++;

    cout << "[Tour " << turnCount_ << "]" << endl;
    cout << "Pokemon adverse: " << endl;
    currentOpponent_.PrintBattleStats ();
    //currentOpponent_.PrintStats ();
    cout << "Pokemon du joueur: " << endl;
    currentPokemon_.PrintBattleStats ();
    cout << endl
    << "Que doit faire "
    << currentPokemon_.GetName ()
    << " ?" << endl << endl
    << "[1]Attaque" << endl
    << "[2]Sac" << endl
    << "[3]Pokémon" << endl
    << "[4]Fuite" << endl << endl;

    int choice = 0;
    cin >> choice;
    getchar ();

    switch (choice)
    {
    case 1:
    DisplayMoves ();
    bc.ComputeDamage (
    *currentPokemon_.GetMoves ()[2],
    currentPokemon_,
    currentOpponent_);
    break;
    case 2:
    cout << "Le sac n'est pas encore fonctionnel !" << endl;
    break;
    case 3:
    DisplayTeam ();
    break;
    case 4:
    cout << "Fuite !" << endl;
    getchar ();
    std::exit (0);
    break;
    default:
    cout << "Error" << endl;
    break;
    }

    getchar ();
    }
    */
  }

  void Battle::AddPhase (
      const BattlePhaseState& battlePhaseState, 
      BattlePhase* battlePhase)
  {
    battlePhaseManager_.AddPhase (battlePhaseState, battlePhase);
  }

  void Battle::HandleUpdate (const Time& dt)
  {
  }

  void Battle::DisplayMoves ()
  {
    /*
    int i = 1;
    for (PokemonSkill* pk : currentPokemon_.GetMoves ())
    {
      cout << "[" << i << "]" << pk->GetName () << endl;
      i++;
    }
    */
  }

  void Battle::DisplayTeam ()
  {
    /*
    int i = 1;
    for (Pokemon* p : playerTeam_.GetTeam ())
    {
      if (p != nullptr)
        cout << "[" << i << "]" << p->GetName () << endl;
      i++;
    }
    */
  }
} // namespace yap
