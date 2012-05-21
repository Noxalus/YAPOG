#include <iostream>
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/Path.hpp"
#include "YAPOG/Content/ContentManager.hpp"
#include "YAPOG/Game/Pokemon/Pokemon.hpp"
#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfoReader.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Game/Pokemon/NatureInfoReader.hpp"
#include "YAPOG/Game/Pokemon/NatureInfo.hpp"
#include "YAPOG/Game/Pokemon/TypeInfoReader.hpp"
#include "YAPOG/Game/Pokemon/TypeInfo.hpp"
#include "YAPOG/Game/Pokemon/SkillInfoReader.hpp"
#include "YAPOG/Game/Pokemon/SkillInfo.hpp"
#include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
#include "YAPOG/Game/Battle/WildBattle.hpp"

using namespace yap;
using namespace yap::collection;

Pokemon* GeneratePokemon ()
{
  ID staticID = ID (RandomHelper::GetNext (1, 4));

  if (staticID == ID (4))
    staticID = ID (16);

  int level = RandomHelper::GetNext (1, 100);

  Pokemon* p = new Pokemon (staticID, level, false);

  return p;
}

int main ()
{
  RandomHelper::Init (time (nullptr));
  Path ContentDirectory ("../../Content");
  ContentManager::Instance ().Init (ContentDirectory);

  ObjectFactory::Instance ().RegisterLoader 
    ("PokemonInfo",
    new XmlObjectIDLoader<PokemonInfo, PokemonInfoReader>
    (Path ("Pokemon/Pokemon"), "PokemonInfo"));

  ObjectFactory::Instance ().RegisterLoader 
    ("NatureInfo",
    new XmlObjectIDLoader<NatureInfo, NatureInfoReader>
    (Path ("Pokemon/Nature"), "Nature"));

  ObjectFactory::Instance ().RegisterLoader 
    ("TypeInfo",
    new XmlObjectIDLoader<TypeInfo, TypeInfoReader>
    (Path ("Pokemon/Types"), "Type"));

  ObjectFactory::Instance ().RegisterLoader 
    ("SkillInfo",
    new XmlObjectIDLoader<SkillInfo, SkillInfoReader>
    (Path ("Pokemon/Skills"), "Skill"));

  PokemonTeam team;
  team.AddPokemon (new Pokemon (ID (2), 42, false));
  team.AddPokemon (new Pokemon (ID (16), 32, true));

  try 
  {
    /*
    WildBattle wildBattle (team, *GeneratePokemon ());
    wildBattle.Run ();
    */

    getchar ();
  }
  catch (const yap::Exception& e)
  {
    e.GetMessage (std::cerr) << std::endl;
    getchar ();
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what () << std::endl;
    getchar ();
  }
}
