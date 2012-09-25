#include "YAPOG/Graphics/Gui/Label.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Gui/PokemonInfoBox.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  const yap::String PokemonInfoBox::
    DEFAULT_ICON_FILE = "Pokemon/Icons/0.png";
  const yap::String PokemonInfoBox::
    DEFAULT_GENDER_FILE = "Pictures/Battle/MaleIcon.png";

  PokemonInfoBox::PokemonInfoBox (const Pokemon& pokemon, bool isMainPokemon)
    : initialized_ (false)
    , pokemon_ (pokemon) 
    , isMainPokemon_ (isMainPokemon)
    , isSelected_ (false)
    , normalBackground_ (nullptr)
    , selectedBackground_ (nullptr)
    , name_ (nullptr)
    , level_ (nullptr)
    , hpLabel_ (nullptr)
    , gender_ (nullptr)
    , icon_ (nullptr)
    , hpBar_ ()
  {
    name_ = new yap::Label ();
    level_ = new yap::Label ();
    hpLabel_ = new yap::Label ();

    normalBackground_ = new yap::WidgetBackground (
      "Pictures/TeamManager/ItemBox.png", true);
    selectedBackground_ = new yap::WidgetBackground (
      "Pictures/TeamManager/ItemBoxSelected.png", true);

    gender_ = new yap::PictureBox ();
    icon_ = new yap::PictureBox ();
  }

  void PokemonInfoBox::Init ()
  {
    SetBackground (*normalBackground_);

    icon_->SetPicture (new yap::Sprite (DEFAULT_ICON_FILE));
    gender_->SetPicture (new yap::Sprite (DEFAULT_GENDER_FILE));

    // HP Bar
    hpBar_.Init ();
    hpBar_.SetHitPoint (pokemon_.GetStats ().GetHitPoint ());

    name_->SetDefaultColor (sf::Color::White);
    level_->SetDefaultColor (sf::Color::White);
    hpLabel_->SetDefaultColor (sf::Color::White);

    if (isMainPokemon_)
    {
      SetSize (yap::Vector2 (276, 173));

      yap::VerticalLayout* mainLayout = 
        new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);

      yap::HorizontalLayout* firstLine = 
        new yap::HorizontalLayout (yap::Padding (), yap::Padding (), false);

      yap::VerticalLayout* firstLineIcon = 
        new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);

      yap::VerticalLayout* firstLineInfo = 
        new yap::VerticalLayout (
        yap::Padding (0, 0, 0, 20), yap::Padding (), false);

      yap::HorizontalLayout* levelAndGender = 
        new yap::HorizontalLayout (
        yap::Padding (), yap::Padding (), true);

      yap::VerticalLayout* secondLine = 
        new yap::VerticalLayout (
        yap::Padding (0, 20, 0, 10), yap::Padding (), false);

      mainLayout->SetSize (GetSize ());

      firstLine->SetSize (yap::Vector2 (GetSize ().x, GetSize ().y / 2));

      firstLineIcon->SetSize (icon_->GetSize ());
      firstLineIcon->AddChild (*icon_);

      firstLineInfo->SetSize (yap::Vector2 (
        firstLine->GetSize ().x - firstLineIcon->GetSize ().x,
        firstLine->GetSize ().y));
      firstLineInfo->AddChild (*name_, yap::LayoutBox::Align::BOTTOM);

      levelAndGender->AddChild (*level_);
      levelAndGender->AddChild (*gender_);
      firstLineInfo->AddChild (*levelAndGender);

      firstLine->AddChild (*firstLineIcon);
      firstLine->AddChild (*firstLineInfo);

      secondLine->SetSize (yap::Vector2 (GetSize ().x, GetSize ().y / 2));
      secondLine->AddChild (hpBar_, yap::LayoutBox::Align::RIGHT);
      secondLine->AddChild (*hpLabel_, yap::LayoutBox::Align::RIGHT);

      mainLayout->AddChild (*firstLine);
      mainLayout->AddChild (*secondLine);

      /*
      mainLayout->SetBorder (*new yap::WidgetBorder ("Test/black.png"));
      firstLine->SetBorder (*new yap::WidgetBorder ("Test/yellow.png"));
      secondLine->SetBorder (*new yap::WidgetBorder ("Test/green.png"));
      firstLineInfo->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
      firstLineIcon->SetBorder (*new yap::WidgetBorder ("Test/blue.png"));
      levelAndGender->SetBorder (*new yap::WidgetBorder ("Test/orange.png"));
      */

      AddChild (*mainLayout);
    }
    else
    {
      SetSize (yap::Vector2 (425, 75));

      yap::HorizontalLayout* mainLayout = 
        new yap::HorizontalLayout (yap::Padding (), yap::Padding (), false);

      yap::HorizontalLayout* hor1 = 
        new yap::HorizontalLayout (yap::Padding (), yap::Padding (), true);

      yap::VerticalLayout* ver1 = 
        new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);
      yap::VerticalLayout* ver2 = 
        new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);
      yap::VerticalLayout* ver3 = 
        new yap::VerticalLayout (yap::Padding (), yap::Padding (), false); 

      ver1->SetSize (yap::Vector2 (64, 64));
      ver1->AddChild (*icon_);

      hor1->AddChild (*level_);
      hor1->AddChild (*gender_);

      ver2->SetSize (yap::Vector2 (150, 64));
      ver2->AddChild (*name_, yap::LayoutBox::Align::CENTER);
      ver2->AddChild (*hor1, yap::LayoutBox::Align::CENTER);

      ver3->SetSize (yap::Vector2 (200, 64));
      ver3->AddChild (hpBar_, yap::LayoutBox::Align::RIGHT);
      ver3->AddChild (*hpLabel_, yap::LayoutBox::Align::RIGHT);

      /*
      ver1->SetBorder (*new yap::WidgetBorder ("Test/black.png"));
      ver2->SetBorder (*new yap::WidgetBorder ("Test/yellow.png"));
      ver3->SetBorder (*new yap::WidgetBorder ("Test/green.png"));
      hor1->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
      */
      mainLayout->SetSize (GetSize ());
      mainLayout->AddChild (*ver1);
      mainLayout->AddChild (*ver2);
      mainLayout->AddChild (*ver3);

      AddChild (*mainLayout);
    }

    initialized_ = true;
  }

  void PokemonInfoBox::SetIsSelected (bool value)
  {
    isSelected_ = value;

    if (isSelected_)
      SetBackground (*selectedBackground_);
    else
      SetBackground (*normalBackground_);
  }

  bool PokemonInfoBox::IsFocusable () const
  {
    return false;
  }

  void PokemonInfoBox::RefreshWidget ()
  {
    if (initialized_)
    {
      // Labels
      name_->SetText (pokemon_.GetName ());

      level_->SetText ( 
        "N. " + yap::StringHelper::ToString (
        static_cast<int>(pokemon_.GetLevel ())));

      hpLabel_->SetText (yap::StringHelper::ToString (
        pokemon_.GetCurrentHP ()) + " / " + 
        yap::StringHelper::ToString (pokemon_.GetMaxHP ()));

      // HP bar
      hpBar_.RefreshWidget ();

      // Picture boxes
      gender_->SetPicture (pokemon_.GetGenderIcon ().Clone ());
      icon_->SetPicture (pokemon_.GetIcon ().Clone ());
    }
  }

} // namespace ycl
