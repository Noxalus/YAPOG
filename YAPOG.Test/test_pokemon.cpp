#include <iostream>
#include "YAPOG/Collection/Array.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfoReader.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/System/Path.hpp"
#include "YAPOG/Content/ContentManager.hpp"
#include "YAPOG/Game/Pokemon/Pokemon.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/Game/Pokemon/NatureInfoReader.hpp"
#include "YAPOG/Game/Pokemon/NatureInfo.hpp"
#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/Game/Pokemon/TypeInfoReader.hpp"
#include "YAPOG/Game/Pokemon/TypeInfo.hpp"
#include "YAPOG/Game/Pokemon/SkillInfoReader.hpp"
#include "YAPOG/Game/Pokemon/SkillInfo.hpp"
#include "YAPOG/System/IO/IWriter.hpp"
#include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
#include "boost/exception/all.hpp"
#include "YAPOG/Game/Battle/WildBattle.hpp"

using namespace yap;
using namespace std;

int main ()
{
  try
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

    getchar ();
  }
  catch (Exception& ex)
  {
    ex.GetMessage (cout) << endl;
    getchar ();
  }
  catch (boost::exception const&  ex)
  {
    cout << boost::diagnostic_information(ex);
    getchar ();
  }
}
