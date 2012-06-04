#include "YAPOG/Game/Pokemon/Pokemon.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"

#include "Pokemon/Pokemon.hpp"
#include "Pokemon/PokemonInfo.hpp"

namespace ycl
{
  Pokemon::Pokemon (const yap::ID& staticID)
    : yap::Pokemon (staticID)
  {
    Init ();
  }

  Pokemon::Pokemon (
    const yap::ID& staticID, 
    const yap::UInt16& level, 
    const bool& shiny)
    : yap::Pokemon (staticID, level, shiny)
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
    icon_ = new yap::Sprite (
      new yap::Texture (graphicPokemonInfo_->GetIcon ()));

    if (shiny_)
    {
      if (gender_ == yap::Gender::Female)
      {
        battleFront_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetShinyFemaleFront ()));

        battleBack_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetShinyFemaleBack ()));
      }
      else
      {
        battleFront_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetShinyMaleFront ()));

        battleBack_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetShinyMaleBack ()));
      }
    }
    else
    {
      if (gender_ == yap::Gender::Female)
      {
        battleFront_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetFemaleFront ()));

        battleBack_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetFemaleBack ()));
      }
      else
      {
        battleFront_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetMaleFront ()));

        battleBack_ = new yap::Sprite (
          new yap::Texture (graphicPokemonInfo_->GetMaleBack ()));
      }
    }
  }

  yap::ISprite& Pokemon::GetIcon () const
  {
    return *icon_;
  }

  yap::ISprite& Pokemon::GetBattleBack () const
  {
    return *battleBack_;
  }

  yap::ISprite& Pokemon::GetBattleFront () const
  {
    return *battleFront_;
  }

} // namespace ycl