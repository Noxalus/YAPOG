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

static Pokemon* GeneratePokemon ()
{
  ID staticID = ID (RandomHelper::GetNext (1, 4));

  if (staticID == ID (4))
    staticID = ID (16);

  int level = RandomHelper::GetNext (1, 100);

  return new Pokemon (staticID, level, false);
}

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

    PokemonTeam team;
    team.AddPokemon (new Pokemon (ID (2), 42, false));
    team.AddPokemon (new Pokemon (ID (16), 32, true));

    WildBattle wildBattle (team, GeneratePokemon ());
    wildBattle.Run ();

    /*
    // Create the types table
    TypeInfo types[17];

    for (int i = 0; i < 17; i++)
    {
      types[i] = *ObjectFactory::Instance ().
        Create<TypeInfo> ("TypeInfo",  ID (i + 1));
    }

    OFStream file ("type.html");

    file << "<table style=\"text-align: center;\"><tr><th>Types</th>";
    for (int i = 0; i < 17; i++)
      file << "<th>" << types[i].GetName () << "</th>";
    file << "</tr><tr>";

    for (int i = 0; i < 17; i++)
    {
      file << "<tr><td>" << types[i].GetName () << "</td>";
      for (int j = 0; j < 17; j++)
      {
        if (types[i].GetTypeEffect (types[j].GetID ()) == 0)
          file << "<td style=\"background-color: Red; color: White;\">";
        else if (types[i].GetTypeEffect (types[j].GetID ()) == 0.5)
          file << "<td style=\"background-color: Grey; color: White;\">";
        else if (types[i].GetTypeEffect (types[j].GetID ()) == 2)
          file << "<td style=\"background-color: Green; color: White;\">";
        else
          file << "<td>";

        file << types[i].GetTypeEffect (types[j].GetID ()) << "</td>";
      }
      file << "</tr>";
    }

    file << "</table>";

    file << "<table style=\"text-align: center;\"><tr><th>Types</th>";
    for (int i = 0; i < 17; i++)
      file << "<th>" << types[i].GetName () << "</th>";

    file << "</tr><tr>"
      << "<td>" << team.GetPokemon (0)->GetName () << "</td>";

    for (int i = 0; i < 17; i++)
    {
      if (team.GetPokemon (0)->GetTypeEffectFactor (types[i]) == 0)
        file << "<td style=\"background-color: Red; color: White;\">";
      else if (team.GetPokemon (0)->GetTypeEffectFactor (types[i]) == 0.5)
        file << "<td style=\"background-color: Grey; color: White;\">";
      else if (team.GetPokemon (0)->GetTypeEffectFactor (types[i]) == 2)
        file << "<td style=\"background-color: Green; color: White;\">";
      else
        file << "<td>";

      file << team.GetPokemon (0)->GetTypeEffectFactor (types[i]) << "</td>";
    }

    file << "</tr></table>";
    */
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
