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

#include "Gui/PokemonBasicInfoWidget.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  PokemonBasicInfoWidget::PokemonBasicInfoWidget (const Pokemon& pokemon)
    : pokemon_ (pokemon)
    , nameLeft_ (nullptr)
    , nameRight_ (nullptr)
    , staticID_ (nullptr)
    , trainerName_ (nullptr)
    , uniqueID_ (nullptr)
    , item_ (nullptr)
    , level_ (nullptr)
    , nature_ (nullptr)
    , gender_ (nullptr)
    , spriteFront_ (nullptr)
    , type1_ (nullptr)
    , type2_ (nullptr)
    , mainLayout_ (nullptr)
    , firstLine_ (nullptr)
    , firstLinePartLeft_ (nullptr)
    , levelLayout_ (nullptr)
    , nameLayout_ (nullptr)
    , genderLayout_ (nullptr)
    , levelNameGenderLayout_ (nullptr)
    , spriteFrontLayout_ (nullptr)
    , firstLinePartRight_ (nullptr)
    , typesLayout_ (nullptr)
    , secondLine_ (nullptr)
  {
  }

  void PokemonBasicInfoWidget::Init ()
  {
    SetBackground (*new yap::WidgetBackground (
      "Pictures/TeamManager/PokemonBasicInfoBackground.png", true));

    nameLeft_ = new yap::Label (pokemon_.GetName ());

    nameRight_ = new yap::Label (pokemon_.GetName ());

    staticID_ = new yap::Label (
      yap::StringHelper::ToString 
      (pokemon_.GetStaticID ().GetValue ()));

    trainerName_ = new yap::Label (pokemon_.GetTrainerName ());

    uniqueID_ = new yap::Label (
      yap::StringHelper::ToString 
      (pokemon_.GetUniqueID ().GetValue ()));

    item_ = new yap::Label ("Aucun");

    level_ = new yap::Label ("N." +
      yap::StringHelper::ToString 
      (static_cast<int>(pokemon_.GetLevel ())) + " ");

    nature_ = new yap::MultiLabelWidget (
      yap::Padding (20, 0, 0, 0), yap::Padding (), false);

    gender_ = new yap::PictureBox ();
    spriteFront_ = new yap::PictureBox ();
    type1_ = new yap::PictureBox ();
    type2_ = new yap::PictureBox ();

    mainLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLine_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLinePartLeft_ = new yap::VerticalLayout (
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

    firstLinePartRight_ = new yap::VerticalLayout (
      yap::Padding (160, 0, 0, 12), yap::Padding (0, 0, 16, 0), false);

    typesLayout_ = new yap::HorizontalLayout (
      yap::Padding (0, 0, 0, 0), yap::Padding (0, 10, 0, 0), true);

    secondLine_ = new yap::VerticalLayout (
      yap::Padding (50, 0, 0, 30), yap::Padding (), false);

    mainLayout_->SetSize (GetSize ());
    firstLine_->SetSize (yap::Vector2 (800, 355));
    firstLinePartLeft_->SetSize (yap::Vector2 (392, 315));
    levelLayout_->SetSize (yap::Vector2 (88, 53));
    nameLayout_->SetSize (yap::Vector2 (240, 53));
    genderLayout_->SetSize (yap::Vector2 (40, 53));
    levelNameGenderLayout_->SetSize (yap::Vector2 (379, 53));
    spriteFrontLayout_->SetSize (yap::Vector2 (363, 233));
    firstLinePartRight_->SetSize (yap::Vector2 (408, 346));
    secondLine_->SetSize (yap::Vector2 (800, 175));
    nature_->SetSize (secondLine_->GetSize ());

    // Set the labels text size
    nameLeft_->SetTextSize (40);
    nameRight_->SetTextSize (40);
    staticID_->SetTextSize (40);
    trainerName_->SetTextSize (40);
    uniqueID_->SetTextSize (40);
    item_->SetTextSize (40);
    level_->SetTextSize (40);

    if (pokemon_.GetGender () == yap::Gender::Female)
    {
      gender_->SetPicture (
      new yap::Sprite ("Pictures/TeamManager/Female.png"));
    }
    else
    {
      gender_->SetPicture (
      new yap::Sprite ("Pictures/TeamManager/Male.png"));
    }

    spriteFront_->SetPicture (&pokemon_.GetBattleFront ());

    spriteFrontLayout_->AddChild (*spriteFront_);

    firstLinePartLeft_->AddChild (*levelNameGenderLayout_);
    firstLinePartLeft_->AddChild (*spriteFrontLayout_);

    levelLayout_->AddChild (*level_);
    nameLayout_->AddChild (*nameLeft_);
    genderLayout_->AddChild (*gender_);

      levelNameGenderLayout_->AddChild (*levelLayout_);
    levelNameGenderLayout_->AddChild (*nameLayout_);
    levelNameGenderLayout_->AddChild (*genderLayout_);

    type1_->SetPicture (&pokemon_.GetType1Icon ());
    type2_->SetPicture (&pokemon_.GetType2Icon ());

    typesLayout_->AddChild (*type1_);
    typesLayout_->AddChild (*type2_);

    firstLinePartRight_->AddChild (*staticID_, yap::LayoutBox::Align::LEFT);
    firstLinePartRight_->AddChild (*nameRight_, yap::LayoutBox::Align::LEFT);
    firstLinePartRight_->AddChild (*typesLayout_, yap::LayoutBox::Align::LEFT);
    firstLinePartRight_->AddChild (*trainerName_, yap::LayoutBox::Align::LEFT);
    firstLinePartRight_->AddChild (*uniqueID_, yap::LayoutBox::Align::LEFT);
    firstLinePartRight_->AddChild (*item_, yap::LayoutBox::Align::LEFT);

    firstLine_->AddChild (*firstLinePartLeft_, yap::LayoutBox::Align::TOP);
    firstLine_->AddChild (*firstLinePartRight_, yap::LayoutBox::Align::TOP);

    nature_->AddText (
      pokemon_.GetNature ().GetName () + " de nature.", 50);
    secondLine_->AddChild (*nature_);

    mainLayout_->AddChild (*firstLine_, yap::LayoutBox::Align::LEFT);
    mainLayout_->AddChild (*secondLine_, yap::LayoutBox::Align::LEFT);

    /*
    mainLayout_->SetBorder (*new yap::WidgetBorder ("Test/grey.png"));
    firstLine_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    firstLinePartLeft_->SetBorder (*new yap::WidgetBorder ("Test/yellow.png"));
    levelNameGenderLayout_->SetBorder (*new yap::WidgetBorder ("Test/green.png"));
    spriteFrontLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    firstLinePartRight_->SetBorder (*new yap::WidgetBorder ("Test/blue.png"));
    secondLine_->SetBorder (*new yap::WidgetBorder ("Test/orange.png"));
    typesLayout_->SetBorder (*new yap::WidgetBorder ("Test/brown.png"));

    levelLayout_->SetBorder (*new yap::WidgetBorder ("Test/green.png"));
    nameLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    genderLayout_->SetBorder (*new yap::WidgetBorder ("Test/blue.png"));
    */

    AddChild (*mainLayout_);

    mainLayout_->SetPosition (yap::Vector2 (1, 60));
  }

  bool PokemonBasicInfoWidget::IsFocusable () const
  {
    return false;
  }

  void PokemonBasicInfoWidget::HandleMove (const yap::Vector2& offset)
  {
  }

  void PokemonBasicInfoWidget::HandleScale (const yap::Vector2& factor)
  {
  }
  void PokemonBasicInfoWidget::HandleDraw (yap::IDrawingContext& context)
  {
  }
  void PokemonBasicInfoWidget::HandleShow (bool isVisible)
  {
  }
  void PokemonBasicInfoWidget::HandleChangeColor (const sf::Color& color)
  {
  }
  void PokemonBasicInfoWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
