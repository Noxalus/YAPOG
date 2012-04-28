#include "YAPOG/Game/Pokemon/Pokemon.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfoReader.hpp"

namespace yap
{
  const Path Pokemon::POKEMON_XML_PATH = Path ("Pokemon/Pokemon");
  const UInt16 Pokemon::POKEMON_INITIAL_LEVEL = 1;

  Pokemon::Pokemon (const ID& staticID)
    : staticID_ (staticID)
  {
    ObjectFactory::Instance ().RegisterLoader
      ("PokemonInfo",
      new XmlObjectIDLoader<PokemonInfo, PokemonInfoReader>
      (Pokemon::POKEMON_XML_PATH, "PokemonInfo"));

    pokeInfo_ = ObjectFactory::Instance ().
      Create<PokemonInfo> ("PokemonInfo",  staticID);

    level_ = Pokemon::POKEMON_INITIAL_LEVEL;

    stats_.ComputeStats (*pokeInfo_, level_);
  }

  Pokemon::Pokemon (const ID& staticID, const UInt16& level, const bool& shiny)
    : staticID_ (staticID_)
    , level_ (level)
    , shiny_ (shiny)
  {
    pokeInfo_ = yap::ObjectFactory::Instance ().
      Create<PokemonInfo> ("PokemonInfo",  staticID);

    stats_.ComputeStats (*pokeInfo_, level_);
  }

  void Pokemon::PrintStats ()
  {
    //pokeInfo_->PrintBaseStats ();

    std::cout
      << "---------------------------------------------" << std::endl
      << "              Current Statistics" << std::endl
      << "---------------------------------------------" << std::endl
      << "Level: " << level_ << std::endl
      << "Current HP: " << stats_.GetHitPoint ().GetCurrentValue () << std::endl
      << "Max HP: " << stats_.GetHitPoint ().GetValue () << std::endl
      << "Attack: " << stats_.GetAttack ().GetValue () << std::endl
      << "Defense: " << stats_.GetDefense ().GetValue () << std::endl
      << "Special Attack: " << stats_.GetSpecialAttack ().GetValue () << std::endl
      << "Special Defense: " << stats_.GetSpecialDefense ().GetValue () << std::endl
      << "Speed: " << stats_.GetSpeed ().GetValue () << std::endl;
  }
}
