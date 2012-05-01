# include "YAPOG/Game/Pokemon/TypeInfo.hpp"

namespace yap
{
  const float TypeInfo::DEFAULT_FACTOR_EFFECT_VALUE = 1.f;

  TypeInfo::TypeInfo ()
    : staticID_ (0)
    , name_ ()
    , typeEffect_ ()
  {
  }

  TypeInfo::TypeInfo (const ID& id)
    : staticID_ (id)
    , name_ ()
    , typeEffect_ ()
  {
  }

  TypeInfo::TypeInfo (const TypeInfo& copy)
    : staticID_ (copy.staticID_)
    , name_ (copy.name_)
    , typeEffect_ (copy.typeEffect_)
  {
  }

  TypeInfo* TypeInfo::Clone () const
  {
    return new TypeInfo (*this);
  }

  /// Getters
  const ID& TypeInfo::GetID () const
  {
    return staticID_;
  }

  const String& TypeInfo::GetName () const
  {
    return name_;
  }

  const float& TypeInfo::GetTypeEffect (const ID& typeID) const
  {
    if (typeEffect_.Contains (typeID))
      return typeEffect_[typeID];
    else
      return DEFAULT_FACTOR_EFFECT_VALUE;
  }

  /// Setters
  void TypeInfo::SetID (const ID& id)
  {
    staticID_ = id;
  }

  void TypeInfo::SetName (const String& name)
  {
    name_ = name;
  }

  void TypeInfo::AddTypeEffect (const ID& typeID, const float& effect)
  {
    typeEffect_.Add (typeID, effect);
  }

} // namespace yap
