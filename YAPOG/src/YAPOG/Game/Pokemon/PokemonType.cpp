#include "YAPOG/Game/Pokemon/PokemonType.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"

namespace yap
{
  const ID PokemonType::DEFAULT_TYPE_ID (100);

  PokemonType::PokemonType ()
  {
    SetType1 (DEFAULT_TYPE_ID);
    SetType2 (DEFAULT_TYPE_ID);
  }

  PokemonType::PokemonType (const ID& type1, const ID& type2)
  {
    SetType1 (type1);
    SetType2 (type2);
  }

  /// Getters
  const TypeInfo& PokemonType::GetType1 () const
  {
    return *type1_;
  }

  const TypeInfo& PokemonType::GetType2 () const
  {
    return *type2_;
  }

  /// Setters
  void PokemonType::SetType1 (const ID& typeID)
  {
    type1_ = ObjectFactory::Instance ().
      Create<TypeInfo> ("TypeInfo",  ID (typeID));
  }

  void PokemonType::SetType2 (const ID& typeID)
  {
    type2_ = ObjectFactory::Instance ().
      Create<TypeInfo> ("TypeInfo",  ID (typeID));
  }
}