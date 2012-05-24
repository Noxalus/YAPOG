#include "YAPOG/Game/Pokemon/Pokemon.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  Pokemon::Pokemon (const yap::ID& staticID)
    : yap::Pokemon (staticID)
  {
  }

  Pokemon::Pokemon (
    const yap::ID& staticID, 
    const yap::UInt16& level, 
    const bool& shiny)
    : yap::Pokemon (staticID, level, shiny)
  {
  }

  Pokemon::~Pokemon ()
  {
  }

  void Pokemon::LoadSprites ()
  {
    icon_ = new yap::Sprite (
      new yap::Texture ("Pokemon/Icons/" + 
      yap::StringHelper::ToString (staticID_.GetValue ()) + ".png"));

    if (gender_ == yap::Gender::Female)
    {
      battleFront_ = new yap::Sprite (
        new yap::Texture ("Pokemon/Front_Female/" + 
        yap::StringHelper::ToString (staticID_.GetValue ()) + ".png"));

      battleBack_ = new yap::Sprite (
        new yap::Texture ("Pokemon/Back_Female/" + 
        yap::StringHelper::ToString (staticID_.GetValue ()) + ".png"));
    }
    else
    {
      battleFront_ = new yap::Sprite (
        new yap::Texture ("Pokemon/Front_Male/" + 
        yap::StringHelper::ToString (staticID_.GetValue ()) + ".png"));

      battleBack_ = new yap::Sprite (
        new yap::Texture ("Pokemon/Back_Male/" + 
        yap::StringHelper::ToString (staticID_.GetValue ()) + ".png"));
    }
  }

} // namespace ycl