#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Battle/BattleMoveInfoMenu.hpp"

namespace ycl
{
  BattleMoveInfoMenu::BattleMoveInfoMenu ()
    : BaseBattleWidget ()
    , pp_ ()
    , type_ ()
  {
    yap::WidgetBackground* menuBck = 
      new yap::WidgetBackground (
      "WindowSkins/BasicSkin/Global/WindowBackgroundTexture.png", true);

    yap::Texture* t = new yap::Texture ();
    t->LoadFromFile ("WindowSkins/BasicSkin/Global/TopBorder.png");
    yap::Texture* tr = new yap::Texture ();
    tr->LoadFromFile ("WindowSkins/BasicSkin/Global/TopRightCorner.png");
    yap::Texture* r = new yap::Texture ();
    r->LoadFromFile ("WindowSkins/BasicSkin/Global/RightBorder.png");
    yap::Texture* br = new yap::Texture ();
    br->LoadFromFile  ("WindowSkins/BasicSkin/Global/BottomRightCorner.png");
    yap::Texture* b = new yap::Texture ();
    b->LoadFromFile ("WindowSkins/BasicSkin/Global/BottomBorder.png");
    yap::Texture* bl = new yap::Texture ();
    bl->LoadFromFile ("WindowSkins/BasicSkin/Global/BottomLeftCorner.png");
    yap::Texture* l = new yap::Texture ();
    l->LoadFromFile ("WindowSkins/BasicSkin/Global/LeftBorder.png");
    yap::Texture* tl = new yap::Texture ();
    tl->LoadFromFile ("WindowSkins/BasicSkin/Global/TopLeftCorner.png");

    yap::WidgetBorder* menuBorder =
      new yap::WidgetBorder (*t, *tr, *r, *br, *b, *bl, *l, *tl, true);

    this->SetSize (yap::Vector2 (231, 129));

    type_.SetPicture ("Pictures/Types/0.png");

    pp_.Move (yap::Vector2 (85, 20));
    type_.Move (yap::Vector2 (70, 70));

    this->AddChild (pp_);
    this->AddChild (type_);

    SetBackground (*menuBck);
    SetBorder (*menuBorder);
  }

  BattleMoveInfoMenu::~BattleMoveInfoMenu ()
  {
  }

  /// Setters.
  void BattleMoveInfoMenu::SetPPLabel (const yap::String& value)
  {
    pp_.SetText (value);
  }

  void BattleMoveInfoMenu::SetPP (const yap::PokemonSkill& skill)
  {
    pp_.SetText (
      yap::StringHelper::ToString (skill.GetCurrentPP ()) +
      "/" + 
      yap::StringHelper::ToString (skill.GetMaxPP ()));
  }

  void BattleMoveInfoMenu::SetType (const yap::TypeInfo& type)
  {
    type_.Show (true);

    type_.SetPicture ("Pictures/Types/" + 
      yap::StringHelper::ToString (type.GetID ().GetValue ())
      + ".png");
  }

  void BattleMoveInfoMenu::HideType ()
  {
    type_.Show (false);
  }

} // namespace yap
