#include "YAPOG/Game/Battle/Battle.hpp"
#include "YAPOG/Game/Battle/BattleCore.hpp"
using namespace std;

namespace yap
{
  Battle::Battle (PokemonTeam& playerTeam)
    : playerTeam_ (playerTeam)
    , currentOpponent_ (nullptr)
    , currentPokemon_ (playerTeam.GetPokemon (0))
    , turnCount_ (0)
  {
  }

    void Battle::Run ()
  {
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
    }
  }

  void Battle::DisplayMoves ()
  {
    int i = 1;
    for (PokemonSkill* pk : currentPokemon_.GetMoves ())
    {
      cout << "[" << i << "]" << pk->GetName () << endl;
      i++;
    }
  }

  void Battle::DisplayTeam ()
  {
    int i = 1;
    for (Pokemon* p : playerTeam_.GetTeam ())
    {
      if (p != nullptr)
        cout << "[" << i << "]" << p->GetName () << endl;
      i++;
    }
  }
} // namespace yap
