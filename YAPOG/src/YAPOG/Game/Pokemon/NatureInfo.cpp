#include "YAPOG/Game/Pokemon/NatureInfo.hpp"

namespace yap
{
  const float NatureInfo::INITIAL_FACTOR_VALUE = 1.f;

  NatureInfo::NatureInfo ()
    : staticID_ (0)
    , name_ ()
    , attackFactor_ (INITIAL_FACTOR_VALUE)
    , defenseFactor_ (INITIAL_FACTOR_VALUE)
    , specialAttackFactor_ (INITIAL_FACTOR_VALUE)
    , specialDefenseFactor_ (INITIAL_FACTOR_VALUE)
    , speedFactor_ (INITIAL_FACTOR_VALUE)
  {
  }

  NatureInfo::NatureInfo (const ID& id)
    : staticID_ (id)
    , name_ ()
    , attackFactor_ (INITIAL_FACTOR_VALUE)
    , defenseFactor_ (INITIAL_FACTOR_VALUE)
    , specialAttackFactor_ (INITIAL_FACTOR_VALUE)
    , specialDefenseFactor_ (INITIAL_FACTOR_VALUE)
    , speedFactor_ (INITIAL_FACTOR_VALUE)
  {
  }

  NatureInfo::NatureInfo (const NatureInfo& copy)
    : staticID_ (copy.staticID_)
    , name_ (copy.name_)
    , attackFactor_ (copy.attackFactor_)
    , defenseFactor_ (copy.defenseFactor_)
    , specialAttackFactor_ (copy.specialAttackFactor_)
    , specialDefenseFactor_ (copy.specialDefenseFactor_)
    , speedFactor_ (copy.speedFactor_)
  {
  }

  NatureInfo* NatureInfo::Clone () const
  {
    return new NatureInfo (*this);
  }

  const ID& NatureInfo::GetID () const
  {
    return staticID_;
  }

  const String& NatureInfo::GetName () const
  {
    return name_;
  }

  const float& NatureInfo::GetAttackFactor () const
  {
    return attackFactor_;
  }

  const float& NatureInfo::GetDefenseFactor () const
  {
    return defenseFactor_;
  }

  const float& NatureInfo::GetSpecialAttackFactor () const
  {
    return specialAttackFactor_;
  }

  const float& NatureInfo::GetSpecialDefenseFactor () const
  {
    return specialDefenseFactor_;
  }

  const float& NatureInfo::GetSpeedFactor () const
  {
    return speedFactor_;
  }

  /// Setters
  void NatureInfo::SetID (const ID& id)
  {
    staticID_ = id;
  }

  void NatureInfo::SetName (const String& name)
  {
    name_ = name;
  }

  void NatureInfo::SetAttackFactor (const float& factor)
  {
    attackFactor_ = factor;
  }

  void NatureInfo::SetDefenseFactor (const float& factor)
  {
    defenseFactor_ = factor;
  }

  void NatureInfo::SetSpecialAttackFactor (const float& factor)
  {
    specialAttackFactor_ = factor;
  }

  void NatureInfo::SetSpecialDefenseFactor (const float& factor)
  {
    specialDefenseFactor_ = factor;
  }

  void NatureInfo::SetSpeedFactor (const float& factor)
  {
    speedFactor_ = factor;
  }

} // namespace yap