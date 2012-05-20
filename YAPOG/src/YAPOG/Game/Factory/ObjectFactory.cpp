#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/Game/Factory/IObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/IObjectLoader.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  const UInt64 ObjectFactory::INITIAL_ID = 0;
  UInt64 ObjectFactory::currentID_ = INITIAL_ID;

  ObjectFactory::ObjectFactory ()
    : objectIDLoaders_ ()
    , objectLoaders_ ()
    , types_ ()
    , ids_ ()
  {
  }

  ObjectFactory::~ObjectFactory ()
  {
    for (const auto& it : objectIDLoaders_)
      delete it.second;

    for (const auto& it : objectLoaders_)
      delete it.second;
  }

  ObjectFactory& ObjectFactory::Instance ()
  {
    static ObjectFactory instance;

    return instance;
  }

  void ObjectFactory::RegisterLoader (
    const String& typeName,
    IObjectIDLoader* loader)
  {
    if (ContainsLoader (typeName))
      throw Exception (
        "Loader `" + typeName + "' already added to the factory.");

    objectIDLoaders_.Add (typeName, loader);

    AddType (ID (currentID_++), typeName);
  }

  void ObjectFactory::RegisterLoader (
    const String& typeName,
    IObjectLoader* loader)
  {
    if (ContainsLoader (typeName))
      throw Exception (
        "Loader `" + typeName + "' already added to the factory.");

    objectLoaders_.Add (typeName, loader);

    AddType (ID (currentID_++), typeName);
  }

  void ObjectFactory::AddType (const ID& id, const String& type)
  {
    if (!types_.Contains (id))
    {
      types_.Add (id, type);
      ids_.Add (type, id);
    }
    else
    {
      types_[id] = type;
      ids_[type] = id;
    }
  }

  const String& ObjectFactory::GetType (const ID& id) const
  {
    if (!types_.Contains (id))
      YAPOG_THROW(
        "No type for ID `" +
        StringHelper::ToString (id.GetValue ())
        + "'.");

    return types_[id];
  }

  const ID& ObjectFactory::GetID (const String& type) const
  {
    if (!ids_.Contains (type))
      YAPOG_THROW("No ID for type `" + type + "'.");

    return ids_[type];
  }

  const collection::Map<ID, String>& ObjectFactory::GetTypes () const
  {
    return types_;
  }

  bool ObjectFactory::ContainsLoader (const String& typeName) const
  {
    return
      objectLoaders_.Contains (typeName) ||
      objectIDLoaders_.Contains (typeName);
  }
} // namespace yap
