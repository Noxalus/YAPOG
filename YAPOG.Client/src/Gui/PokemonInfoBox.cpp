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
  PokemonInfoBox::PokemonInfoBox (bool isMainPokemon, const Pokemon& pokemon)
    : icon_ (nullptr)
    , name_ (new yap::Label (pokemon.GetName ()))
    , level_ (
    new yap::Label (
    "N. " + yap::StringHelper::ToString (
    static_cast<int>(pokemon.GetLevel ()))))
    , gender_ (nullptr)
    , hpBar_ (nullptr)
    , hpBarContent_ (nullptr)
    , hpLabel_ (new yap::Label (yap::StringHelper::ToString (pokemon.GetCurrentHP ()) + " / " + yap::StringHelper::ToString (pokemon.GetMaxHP ())))
    , vlayout_ (nullptr)
    , isMainPokemon_ (isMainPokemon)
  {
    icon_ = new yap::PictureBox ();
    gender_ = new yap::PictureBox ();
    hpBarContent_ = new yap::PictureBox ();
    hpBar_ = new yap::PictureBox ();

    icon_->SetPicture (&pokemon.GetIcon ());
    gender_->SetPicture (&pokemon.GetGenderIcon ());

    // HP Bar
    hpBar_->SetPicture (
      new yap::Sprite ("Pictures/Battle/HPTeamManagerBar.png"));
    hpBarContent_->SetPicture (
      new yap::Sprite ("Pictures/Battle/HPBarContent.png"));

    yap::Vector2 hpBarSize = 
      yap::Vector2 (130 * ((float)pokemon.GetCurrentHP () / 
      (float)pokemon.GetMaxHP ()), hpBarContent_->GetSize ().y);

    hpBarContent_->SetSize (hpBarSize);
    hpBar_->AddChild (*hpBarContent_);
    hpBarContent_->Move (yap::Vector2 (45.f, 6.f));

    if (static_cast<float> (pokemon.GetCurrentHP ()) / 
      static_cast<float> (pokemon.GetMaxHP ())  <= 0.25)
      hpBarContent_->ChangeColor (sf::Color (250, 90, 60));
    else if (static_cast<float> (pokemon.GetCurrentHP ()) / 
      static_cast<float> (pokemon.GetMaxHP ())  <= 0.5)
      hpBarContent_->ChangeColor (sf::Color (250, 225, 50));
    else
      hpBarContent_->ChangeColor (sf::Color (110, 250, 170));

    if (isMainPokemon)
    {
      SetSize (yap::Vector2 (276, 173));
      SetBackground (*new yap::WidgetBackground ("Pictures/TeamManager/ItemBox.png", true));

      yap::VerticalLayout* mainLayout = 
        new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);

      yap::HorizontalLayout* firstLine = 
        new yap::HorizontalLayout (yap::Padding (), yap::Padding (), false);

      yap::VerticalLayout* firstLineIcon = 
        new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);

      yap::VerticalLayout* firstLineInfo = 
        new yap::VerticalLayout (yap::Padding (0, 0, 0, 20), yap::Padding (), false);

      yap::HorizontalLayout* levelAndGender = 
        new yap::HorizontalLayout (yap::Padding (), yap::Padding (), true);

      yap::VerticalLayout* secondLine = 
        new yap::VerticalLayout (yap::Padding (0, 20, 0, 10), yap::Padding (), false);

      mainLayout->SetSize (GetSize ());

      firstLineInfo->SetDefaultColor (sf::Color::White);
      levelAndGender->SetDefaultColor (sf::Color::White);
      secondLine->SetDefaultColor (sf::Color::White);

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
      secondLine->AddChild (*hpBar_, yap::LayoutBox::Align::RIGHT);
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

      SetBackground (*new yap::WidgetBackground (
        "Pictures/TeamManager/ItemBox.png", true));

      yap::HorizontalLayout* hor1 = 
        new yap::HorizontalLayout (yap::Padding (), yap::Padding (), true);

      yap::VerticalLayout* ver1 = 
        new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);
      yap::VerticalLayout* ver2 = 
        new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);
      yap::VerticalLayout* ver3 = 
        new yap::VerticalLayout (yap::Padding (), yap::Padding (), false); 

      hor1->SetDefaultColor (sf::Color::White);

      ver1->SetDefaultColor (sf::Color::White);
      ver2->SetDefaultColor (sf::Color::White);
      ver3->SetDefaultColor (sf::Color::White);

      ver1->SetSize (yap::Vector2 (64, 64));
      ver1->AddChild (*icon_);

      hor1->AddChild (*level_);
      hor1->AddChild (*gender_);

      ver2->SetSize (yap::Vector2 (150, 64));
      ver2->AddChild (*name_, yap::LayoutBox::Align::CENTER);
      ver2->AddChild (*hor1, yap::LayoutBox::Align::CENTER);

      ver3->SetSize (yap::Vector2 (200, 64));
      ver3->AddChild (*hpBar_, yap::LayoutBox::Align::RIGHT);
      ver3->AddChild (*hpLabel_, yap::LayoutBox::Align::RIGHT);

      /*
      ver1->SetBorder (*new yap::WidgetBorder ("Test/black.png"));
      ver2->SetBorder (*new yap::WidgetBorder ("Test/yellow.png"));
      ver3->SetBorder (*new yap::WidgetBorder ("Test/green.png"));
      hor1->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
      */

      yap::HorizontalLayout* hlayout = 
        new yap::HorizontalLayout (yap::Padding (), yap::Padding (), false);
      hlayout->SetSize (GetSize ());
      hlayout->SetDefaultColor (sf::Color::White);
      hlayout->AddChild (*ver1);
      hlayout->AddChild (*ver2);
      hlayout->AddChild (*ver3);

      AddChild (*hlayout);
    }
  }

  bool PokemonInfoBox::IsFocusable () const
  {
    return false;
  }

  void PokemonInfoBox::HandleMove (const yap::Vector2& offset)
  {

  }
  void PokemonInfoBox::HandleScale (const yap::Vector2& factor)
  {

  }
  void PokemonInfoBox::HandleDraw (yap::IDrawingContext& offset)
  {

  }
  void PokemonInfoBox::HandleShow (bool isVisible)
  {
  }
  void PokemonInfoBox::HandleChangeColor (const sf::Color& color)
  {
  }
  void PokemonInfoBox::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
