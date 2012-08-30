#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/MultiLabelWidget.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

#include "Gui/PokemonFrontInfoWidget.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  PokemonFrontInfoWidget::PokemonFrontInfoWidget ()
    : name_ (nullptr)
    , level_ (nullptr)
    , gender_ (nullptr)
    , spriteFront_ (nullptr)
    , mainLayout_ (nullptr)
    , levelLayout_ (nullptr)
    , nameLayout_ (nullptr)
    , genderLayout_ (nullptr)
    , levelNameGenderLayout_ (nullptr)
    , spriteFrontLayout_ (nullptr)
    , genderMaleIcon_ (nullptr)
    , genderFemaleIcon_ (nullptr)
  {
    SetSize (yap::Vector2 (392, 315));

    // Labels
    name_ = new yap::Label ();

    level_ = new yap::Label ();

    // PictureBoxes
    gender_ = new yap::PictureBox ();
    spriteFront_ = new yap::PictureBox ();

    // Sprites
    genderMaleIcon_ = new yap::Sprite ("Pictures/TeamManager/Male.png");
    genderFemaleIcon_ = new yap::Sprite ("Pictures/TeamManager/Female.png");

    gender_->SetPicture (genderFemaleIcon_);

    // Layouts
    mainLayout_ = new yap::VerticalLayout (
      yap::Padding (0, 0, 0, 7), yap::Padding (), false);

    levelLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    nameLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    genderLayout_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);

    levelNameGenderLayout_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);

    spriteFrontLayout_ = new yap::VerticalLayout (
      yap::Padding (0, 0, 0, 50), yap::Padding (), false);

    // Set layouts size
    mainLayout_->SetSize (GetSize ());
    levelLayout_->SetSize (yap::Vector2 (88, 53));
    nameLayout_->SetSize (yap::Vector2 (240, 53));
    genderLayout_->SetSize (yap::Vector2 (40, 53));
    levelNameGenderLayout_->SetSize (yap::Vector2 (379, 53));
    spriteFrontLayout_->SetSize (yap::Vector2 (363, 233));

    // Set the labels text size
    name_->SetTextSize (40);
    level_->SetTextSize (40);
  }

  void PokemonFrontInfoWidget::Init (const Pokemon& pokemon)
  {
    // Labels
    name_->SetText (pokemon.GetName ());
    level_->SetText ("N." +
      yap::StringHelper::ToString 
      (static_cast<int>(pokemon.GetLevel ())) + " ");

    // PictureBoxes
    /*
    if (pokemon.GetGender () == yap::Gender::Female)
      gender_->SetPicture (genderFemaleIcon_);
    else
      gender_->SetPicture (genderMaleIcon_);
    */

    spriteFront_->SetPicture (pokemon.GetBattleFront ().Clone ());

    // Hierarchy construction
    spriteFrontLayout_->AddChild (*spriteFront_);

    levelLayout_->AddChild (*level_);
    nameLayout_->AddChild (*name_);
    genderLayout_->AddChild (*gender_);

    levelNameGenderLayout_->AddChild (*levelLayout_);
    levelNameGenderLayout_->AddChild (*nameLayout_);
    levelNameGenderLayout_->AddChild (*genderLayout_);

    mainLayout_->AddChild (*levelNameGenderLayout_);
    mainLayout_->AddChild (*spriteFrontLayout_);

    AddChild (*mainLayout_);
  }

  bool PokemonFrontInfoWidget::IsFocusable () const
  {
    return false;
  }

  void PokemonFrontInfoWidget::HandleMove (const yap::Vector2& offset)
  {

  }
  void PokemonFrontInfoWidget::HandleScale (const yap::Vector2& factor)
  {

  }
  void PokemonFrontInfoWidget::HandleDraw (yap::IDrawingContext& offset)
  {

  }
  void PokemonFrontInfoWidget::HandleShow (bool isVisible)
  {
  }
  void PokemonFrontInfoWidget::HandleChangeColor (const sf::Color& color)
  {
  }
  void PokemonFrontInfoWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
