#include "YAPOG/Game/Pokemon/Pokemon.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfoReader.hpp"

namespace yap
{
  const Path Pokemon::POKEMON_XML_PATH = Path ("Pokemon/Pokemon");

  Pokemon::Pokemon (const ID& staticID)
    : staticID_ (staticID)
  {
    ObjectFactory::Instance ().RegisterLoader
      ("PokemonInfo",
      new XmlObjectIDLoader<PokemonInfo, PokemonInfoReader>
      (Pokemon::POKEMON_XML_PATH, "PokemonInfo"));

    pokeInfo_ = ObjectFactory::Instance ().
      Create<PokemonInfo> ("PokemonInfo",  staticID);
  }

  void Pokemon::PrintStats ()
  {
    std::cout << "COUCOU" << std::endl;
    pokeInfo_->PrintBaseStats ();

    std::cout
      << "---------------------------------------------" << std::endl
      << "              Current Statistics" << std::endl
      << "---------------------------------------------" << std::endl
      << "Current HP: " << stats_.GetHitPoint ().GetCurrentValue () << std::endl
      << "Max HP: " << stats_.GetHitPoint ().GetValue () << std::endl
      << "Attack: " << stats_.GetAttack ().GetValue () << std::endl
      << "Defense: " << stats_.GetDefense ().GetValue () << std::endl
      << "Special Attack: " << stats_.GetSpecialAttack ().GetValue () << std::endl
      << "Special Defense: " << stats_.GetSpecialDefense ().GetValue () << std::endl
      << "Speed: " << stats_.GetSpeed ().GetValue () << std::endl;
  }
}
