#include "YAPOG/Game/Pokemon/Pokemon.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/Pokemon/PokemonMoveSet.hpp"

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
  {
    Init ();
  }

  Pokemon::Pokemon (
    const yap::ID& uniqueID,
    const yap::ID& staticID,
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
  {
    Init ();
  }

  Pokemon::~Pokemon ()
  {
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

} // namespace ycl