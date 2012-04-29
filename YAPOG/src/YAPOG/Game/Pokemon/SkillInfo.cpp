# include "YAPOG/Game/Pokemon/SkillInfo.hpp"

namespace yap
{
  const ID SkillInfo::DEFAULT_ID (0);
  const String SkillInfo::DEFAULT_NAME = "-";
  const String SkillInfo::DEFAULT_DESCRIPTION = "-";
  const UInt16 SkillInfo::DEFAULT_POWER = 0;
  const UInt16 SkillInfo::DEFAULT_PP = 0;
  const UInt16 SkillInfo::DEFAULT_MAX_PP = 0;
  const UInt16 SkillInfo::DEFAULT_ACCURACY = 0;
  const UInt16 SkillInfo::DEFAULT_TYPE = 0;
  const UInt16 SkillInfo::DEFAULT_CATEGORY = 0;
  const UInt16 SkillInfo::DEFAULT_TARGET = 0;
  const UInt16 SkillInfo::DEFAULT_EFFECT = 0;
  const UInt16 SkillInfo::DEFAULT_USE = 0;
  const UInt16 SkillInfo::DEFAULT_PRIORITY = 0;

  SkillInfo::SkillInfo ()
    : staticID_ (DEFAULT_ID)
    , name_ (DEFAULT_NAME)
    , description_ (DEFAULT_DESCRIPTION)
    , power_ (DEFAULT_POWER)
    , pp_ (DEFAULT_PP)
    , maxPP_ (DEFAULT_MAX_PP)
    , accuracy_ (DEFAULT_ACCURACY)
    , type_ (DEFAULT_TYPE)
    , category_ (DEFAULT_CATEGORY)
    , target_ (DEFAULT_TARGET)
    , effect_ (DEFAULT_EFFECT)
    , use_ (DEFAULT_USE)
    , priority_ (DEFAULT_PRIORITY)
  {
  }

  SkillInfo::SkillInfo (const ID& id)
    : staticID_ (id)
    , name_ (DEFAULT_NAME)
    , description_ (DEFAULT_DESCRIPTION)
    , power_ (DEFAULT_POWER)
    , pp_ (DEFAULT_PP)
    , maxPP_ (DEFAULT_MAX_PP)
    , accuracy_ (DEFAULT_ACCURACY)
    , type_ (DEFAULT_TYPE)
    , category_ (DEFAULT_CATEGORY)
    , target_ (DEFAULT_TARGET)
    , effect_ (DEFAULT_EFFECT)
    , use_ (DEFAULT_USE)
    , priority_ (DEFAULT_PRIORITY)
  {
  }

  SkillInfo::SkillInfo (const SkillInfo& copy)
    : staticID_ (copy.staticID_)
    , name_ (copy.name_)
    , description_ (copy.description_)
    , power_ (copy.power_)
    , pp_ (copy.pp_)
    , maxPP_ (copy.maxPP_)
    , accuracy_ (copy.accuracy_)
    , type_ (copy.type_)
    , category_ (copy.category_)
    , target_ (copy.target_)
    , effect_ (copy.effect_)
    , use_ (copy.use_)
    , priority_ (copy.priority_)
  {
  }

  /// @name ICloneable members.
  /// @{
  SkillInfo* SkillInfo::Clone () const
  {
    return new SkillInfo (*this);
  }
  /// @}

  /// Getters
  const ID& SkillInfo::GetID () const
  {
    return staticID_;
  }

  const String& SkillInfo::GetName () const
  {
    return name_;
  }

  const String& SkillInfo::GetDescription () const 
  {
    return description_;
  }

  const UInt16& SkillInfo::GetPower () const
  {
    return power_;
  }

  const UInt16& SkillInfo::GetPP () const 
  {
    return pp_;
  }

  const UInt16& SkillInfo::GetMaxPP () const 
  {
    return maxPP_;
  }

  const UInt16& SkillInfo::GetAccuracy () const
  {
    return accuracy_;
  }

  const UInt16& SkillInfo::GetType () const
  {
    return type_;
  }

  const UInt16& SkillInfo::GetCategory () const 
  {
    return category_;
  }

  const UInt16& SkillInfo::GetTarget () const
  {
    return target_;
  }

  const UInt16& SkillInfo::GetEffect () const
  {
    return effect_;
  }

  const UInt16& SkillInfo::GetUse () const
  {
    return use_;
  }

  const UInt16& SkillInfo::GetPriority () const
  {
    return priority_;
  }

  /// Setters
  void SkillInfo::SetID (const ID& id)
  {
    staticID_ = id;
  }

  void SkillInfo::SetName (const String& name)
  {
    name_ = name;
  }

  void SkillInfo::SetDescription (const String& description)
  {
    description_ = description; 
  }

  void SkillInfo::SetPower (const UInt16& value)
  {
    power_ = value; 
  }

  void  SkillInfo::SetPP (const UInt16& value)
  {
    pp_ = value; 
  }

  void  SkillInfo::SetMaxPP (const UInt16& value)
  {
    maxPP_ = value; 
  }

  void  SkillInfo::SetAccuracy (const UInt16& value)
  {
    accuracy_ = value; 
  }

  void  SkillInfo::SetType (const UInt16& value)
  {
    type_ = value; 
  }

  void  SkillInfo::SetCategory (const UInt16& value)
  {
    category_ = value; 
  }

  void  SkillInfo::SetTarget (const UInt16& value)
  {
    target_ = value; 
  }

  void  SkillInfo::SetEffect (const UInt16& value)
  {
    effect_ = value; 
  }

  void  SkillInfo::SetUse (const UInt16& value)
  {
    use_ = value; 
  }

  void  SkillInfo::SetPriority (const UInt16& value)
  {
    priority_ = value;
  }

} // namespace yap
