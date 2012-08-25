#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/Pokemon/PokemonMove.hpp"

namespace yap
{
  const ID PokemonMove::DEFAULT_STATIC_ID (1);
  const UInt16 PokemonMove::DEFAULT_PP_VALUE = 0;
  const UInt16 PokemonMove::DEFAULT_MAX_PP_VALUE = 0;

  PokemonMove::PokemonMove ()
    : staticID_ (DEFAULT_STATIC_ID) 
    , currentPP_ (DEFAULT_PP_VALUE)
    , maxPP_ (DEFAULT_MAX_PP_VALUE)
  {
    skillInfo_ = new SkillInfo ();
  }

  PokemonMove::PokemonMove (const ID& skillID)
    :  staticID_ (skillID) 
    , currentPP_ (DEFAULT_PP_VALUE)
    , maxPP_ (DEFAULT_MAX_PP_VALUE)
  {
    SetSkillInfo (skillID);
  }

  // Getters
  const ID& PokemonMove::GetStaticID () const
  {
    return staticID_;
  }

  const String& PokemonMove::GetName () const
  {
    if (skillInfo_ == nullptr)
      YAPOG_THROW("This skill's base informations doesn't exist !");

    return skillInfo_->GetName ();
  }

  const UInt16& PokemonMove::GetPower () const
  {
    if (skillInfo_ == nullptr)
      YAPOG_THROW("This skill's base informations doesn't exist !");

    return skillInfo_->GetPower ();
  }

  const UInt16& PokemonMove::GetCurrentPP () const
  {
    return currentPP_;
  }

  const UInt16& PokemonMove::GetMaxPP () const
  {
    return maxPP_;
  }

  const UInt16& PokemonMove::GetLimitPPMax () const
  {
    if (skillInfo_ == nullptr)
      YAPOG_THROW("This skill's base informations doesn't exist !");

    return skillInfo_->GetMaxPP ();
  }

  void PokemonMove::SetSkillInfo (const ID& skillID)
  {
    skillInfo_ = ObjectFactory::Instance ().
      Create<SkillInfo> ("SkillInfo",  ID (skillID));

    maxPP_ = skillInfo_->GetPP ();
    Refill ();
  }

  void PokemonMove::Refill ()
  {
    currentPP_ = maxPP_;
  }

  void PokemonMove::Use ()
  {
    if (currentPP_ > 0)
      currentPP_--;
  }

  void PokemonMove::AddPP (int value)
  {
    maxPP_ += value;

    if (maxPP_ > GetLimitPPMax ())
      maxPP_ = GetLimitPPMax ();
  }

  void PokemonMove::RaiseToMaxPP ()
  {
    maxPP_ = GetLimitPPMax ();
  }

  const TypeInfo& PokemonMove::GetType () const
  {
    return skillInfo_->GetType ();
  }

  const UInt16& PokemonMove::GetCategory () const
  {
    return skillInfo_->GetCategory ();
  }
}