#include "YAPOG/Game/Battle/WildBattle.hpp"
#include "YAPOG/Game/Pokemon/PokemonSkill.hpp"

using namespace std;

namespace yap
{
  WildBattle::WildBattle (
    PokemonTeam& playerTeam, 
    Pokemon* wildPokemon)
    : playerTeam_ (playerTeam)
    , currentPokemon_ (playerTeam.GetPokemon (0))
    , wildPokemon_ (wildPokemon)
    , turnCount_ (0)
  {
  }

  void WildBattle::Run ()
  {
    cout 
      << "Un " << wildPokemon_->GetName () 
      << " sauvage apparait !" 
      << endl
      << currentPokemon_->GetName () 
      <<  "! A l'attaque !" 
      << endl << endl;

    while (true)
    {
      turnCount_++;

      cout << "[Tour " << turnCount_ << "]" << endl;
      cout << "Pokemon sauvage: " << endl;
      wildPokemon_->PrintBattleStats ();
      cout << "Pokemon combattant: " << endl;
      currentPokemon_->PrintBattleStats ();
      cout << endl
        << "Que doit faire " 
        << currentPokemon_->GetName ()
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
  }

  void WildBattle::DisplayMoves ()
  {
    int i = 1;
    for (PokemonSkill* pk : currentPokemon_->GetMoves ())
    {
      cout << "[" << i << "]" << pk->GetName () << endl;
      i++;
    }
  }

  void WildBattle::DisplayTeam ()
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