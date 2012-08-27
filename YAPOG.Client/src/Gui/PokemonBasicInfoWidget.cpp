#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/MultiLabelWidget.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"

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
    , levelNameGenderLayout_ (nullptr)
    , spriteFrontLayout_ (nullptr)
    , firstLinePartRight_ (nullptr)
    , typesLayout (nullptr)
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

    trainerName_ = new yap::Label ("Trainer");

    uniqueID_ = new yap::Label (
      yap::StringHelper::ToString 
      (pokemon_.GetUniqueID ().GetValue ()));

    item_ = new yap::Label ("Aucun");

    level_ = new yap::Label ("N." +
      yap::StringHelper::ToString 
      (pokemon_.GetLevel ()));

    nature_ = new yap::MultiLabelWidget (yap::Padding (), yap::Padding (), false);

    gender_ = new yap::PictureBox ();
    spriteFront_ = new yap::PictureBox ();
    type1_ = new yap::PictureBox ();
    type2_ = new yap::PictureBox ();

    mainLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLine_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLinePartLeft_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    levelNameGenderLayout_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);

    spriteFrontLayout_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLinePartRight_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    typesLayout = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), true);

    secondLine_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    mainLayout_->SetSize (GetSize ());
    firstLine_->SetSize (yap::Vector2 (640, 283));
    firstLinePartLeft_->SetSize (yap::Vector2 (303, 240));
    levelNameGenderLayout_->SetSize (yap::Vector2 (296, 42));
    spriteFrontLayout_->SetSize (yap::Vector2 (297, 192));
    firstLinePartRight_->SetSize (yap::Vector2 (326, 282));
    secondLine_->SetSize (yap::Vector2 (614, 135));
    
    //gender_->SetPicture (&pokemon_.GetGenderIcon ());
    spriteFront_->SetPicture (&pokemon_.GetBattleFront ());

    spriteFrontLayout_->AddChild (*spriteFront_);

    firstLinePartLeft_->AddChild (*levelNameGenderLayout_);
    firstLinePartLeft_->AddChild (*spriteFrontLayout_);

    firstLinePartRight_->AddChild (*typesLayout);

    levelNameGenderLayout_->AddChild (*level_);
    levelNameGenderLayout_->AddChild (*nameLeft_);
    //levelNameGenderLayout_->AddChild (*gender_);

    mainLayout_->AddChild (*firstLinePartLeft_, yap::LayoutBox::Align::LEFT);
    mainLayout_->AddChild (*firstLinePartRight_, yap::LayoutBox::Align::LEFT);

    mainLayout_->SetBorder (*new yap::WidgetBorder ("Test/grey.png"));
    firstLine_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    firstLinePartLeft_->SetBorder (*new yap::WidgetBorder ("Test/yellow.png"));
    levelNameGenderLayout_->SetBorder (*new yap::WidgetBorder ("Test/green.png"));
    spriteFrontLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    firstLinePartRight_->SetBorder (*new yap::WidgetBorder ("Test/blue.png"));
    secondLine_->SetBorder (*new yap::WidgetBorder ("Test/orange.png"));


    AddChild (*mainLayout_);
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
