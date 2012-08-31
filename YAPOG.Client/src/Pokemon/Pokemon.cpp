#include "YAPOG/Game/Pokemon/Pokemon.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/Pokemon/PokemonMoveSet.hpp"
#include "YAPOG/Audio/AudioManager.hpp"

#include "Pokemon/Pokemon.hpp"
#include "Pokemon/PokemonInfo.hpp"

namespace ycl
{
  Pokemon::Pokemon (const yap::ID& staticID)
    : yap::Pokemon (staticID)
    , icon_ (nullptr)
    , genderIcon_ (nullptr)
    , battleBack_ (nullptr)
    , battleFront_ (nullptr)
    , type1Icon_ (nullptr)
    , type2Icon_ (nullptr)
  {
    Init ();
  }

  Pokemon::Pokemon (
    const yap::ID& staticID, 
    const yap::UInt16& level, 
    const bool& shiny)
    : yap::Pokemon (staticID, level, shiny)
    , icon_ (nullptr)
    , genderIcon_ (nullptr)
    , battleBack_ (nullptr)
    , battleFront_ (nullptr)
    , type1Icon_ (nullptr)
    , type2Icon_ (nullptr)
  {
    Init ();
  }

  Pokemon::Pokemon (
    const yap::ID& uniqueID,
    const yap::ID& staticID,
    const yap::String& trainerName,
    const yap::String& nickname,
    const yap::PokemonStat& stats,
    const yap::Gender& gender,
    const yap::PokemonStatus& status,
    const bool shiny,
    const yap::Int16& loyalty,
    const yap::PokemonMoveSet& moveSet,
    const yap::ID& natureID,
    const yap::uint& exp,
    const yap::UInt8& boxNumber,
    const yap::ID& boxIndex,
    const yap::String& catchDate)
    : yap::Pokemon (
    uniqueID,
    staticID,
    trainerName,
    nickname,
    stats,
    gender,
    status,
    shiny,
    loyalty,
    moveSet,
    natureID,
    exp,
    boxNumber,
    boxIndex,
    catchDate)
    , icon_ (nullptr)
    , genderIcon_ (nullptr)
    , battleBack_ (nullptr)
    , battleFront_ (nullptr)
    , type1Icon_ (nullptr)
    , type2Icon_ (nullptr)
  {
    Init ();
  }

  Pokemon::~Pokemon ()
  {
  }

  void Pokemon::PlayCry ()
  {
    yap::AudioManager::Instance ().PlaySound ("Cries/" + 
      yap::StringHelper::ToString (staticID_.GetValue ())
      + ".wav");
  }

  void Pokemon::Init ()
  {
    graphicPokemonInfo_ = yap::ObjectFactory::Instance ().
      Create<PokemonInfo> ("PokemonInfo", staticID_);

    LoadSprites ();
  }

  void Pokemon::LoadSprites ()
  {
    icon_ = new yap::Sprite (graphicPokemonInfo_->GetIconPath ());

    type1Icon_ = new yap::Sprite (
      "Pictures/Types/" +
      yap::StringHelper::ToString (
      GetType1 ().GetID ().GetValue ()) + ".png");

    type2Icon_ = new yap::Sprite (
      "Pictures/Types/" +
      yap::StringHelper::ToString (
      GetType2 ().GetID ().GetValue ()) + ".png");

    if (gender_ == yap::Gender::Female)
    {
      genderIcon_ = new yap::Sprite ("Pictures/Battle/FemaleIcon.png");

      if (shiny_)
      {
        battleFront_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetShinyFemaleFrontPath ()));

        battleBack_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetShinyFemaleBackPath ()));
      }
      else
      {
        battleFront_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetFemaleFrontPath ()));

        battleBack_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetFemaleBackPath ()));
      }
    }
    else
    {
      genderIcon_ = new yap::Sprite ("Pictures/Battle/MaleIcon.png");

      if (shiny_)
      {
        battleFront_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetShinyMaleFrontPath ()));

        battleBack_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetShinyMaleBackPath ()));
      }
      else
      {
        battleFront_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetMaleFrontPath ()));

        battleBack_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetMaleBackPath ()));
      }
    }
  }

  // Getters
  yap::ISprite& Pokemon::GetIcon () const
  { return *icon_; }
  yap::ISprite& Pokemon::GetGenderIcon () const
  { return *genderIcon_; }
  yap::ISprite& Pokemon::GetBattleBack () const
  { return *battleBack_; }
  yap::ISprite& Pokemon::GetBattleFront () const
  { return *battleFront_; }
  yap::ISprite& Pokemon::GetType1Icon () const
  { return *type1Icon_; }
  yap::ISprite& Pokemon::GetType2Icon () const
  { return *type2Icon_; }

} // namespace ycl