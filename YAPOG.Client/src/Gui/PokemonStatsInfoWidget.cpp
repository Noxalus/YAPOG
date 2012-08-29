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

#include "Gui/PokemonStatsInfoWidget.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  PokemonStatsInfoWidget::PokemonStatsInfoWidget (const Pokemon& pokemon)
    : pokemon_ (pokemon)
    , nameLeft_ (nullptr)
    , level_ (nullptr)
    , hp_ (nullptr)
    , attack_ (nullptr)
    , defense_ (nullptr)
    , specialAttack_ (nullptr)
    , specialDefense_ (nullptr)
    , speed_ (nullptr)
    , experiencePointLabel_ (nullptr)
    , experiencePoint_ (nullptr)
    , nextLevelPointLabel_ (nullptr)
    , nextLevelPoint_ (nullptr)
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
    , hpLayout_ (nullptr)
    , statsLayout_ (nullptr)
    , experienceLayout_ (nullptr)
    , experiencePointLayout_ (nullptr)
    , experiencePointLabelLayout_ (nullptr)
    , experiencePointNumberLayout_ (nullptr)
    , nextLevelPointLayout_ (nullptr)
    , nextLevelPointLabelLayout_ (nullptr)
    , nextLevelPointNumberLayout_ (nullptr)
    , capacityAndExperienceGlobalLayout_ (nullptr)
    , capacityAndExperienceLayout_ (nullptr)
    , capacityLayout_ (nullptr)
    , experienceBarLayout_ (nullptr)
    , experienceBar_ (pokemon)
  {
  }

  void PokemonStatsInfoWidget::Init ()
  {
    SetBackground (*new yap::WidgetBackground (
      "Pictures/TeamManager/PokemonStatsInfoBackground.png", true));

    // Labels
    nameLeft_ = new yap::Label (pokemon_.GetName ());

    level_ = new yap::Label ("N." +
      yap::StringHelper::ToString 
      (static_cast<int>(pokemon_.GetLevel ())) + " ");

    hp_ = new yap::Label (
      yap::StringHelper::ToString 
      (pokemon_.GetStats ().GetHitPoint ().GetCurrentValue ())
      + "/" +
      yap::StringHelper::ToString 
      (pokemon_.GetStats ().GetHitPoint ().GetValue ()));

    attack_ = new yap::Label (
      yap::StringHelper::ToString 
      (pokemon_.GetStats ().GetAttack ().GetValue ()));

    defense_ = new yap::Label (
      yap::StringHelper::ToString 
      (pokemon_.GetStats ().GetDefense ().GetValue ()));

    specialAttack_ = new yap::Label (
      yap::StringHelper::ToString 
      (pokemon_.GetStats ().GetSpecialAttack ().GetValue ()));

    specialDefense_ = new yap::Label (
      yap::StringHelper::ToString 
      (pokemon_.GetStats ().GetSpecialDefense ().GetValue ()));

    speed_ = new yap::Label (
      yap::StringHelper::ToString 
      (pokemon_.GetStats ().GetSpeed ().GetValue ()));

    experiencePointLabel_ = new yap::Label ("Points:");
    experiencePoint_ = new yap::Label (
      yap::StringHelper::ToString (
      static_cast<int>(pokemon_.GetTotalExperience ())));
    nextLevelPointLabel_ = new yap::Label ("N. suivant:");
    nextLevelPoint_ = new yap::Label (
      yap::StringHelper::ToString (
      static_cast<int>(pokemon_.GetExperienceToNextLevel ()))
      /*
      + "(" + 
      yap::StringHelper::ToString (
      static_cast<int>(pokemon_.GetTotalExperienceToNextLevel ()))
      + " | " +
      yap::StringHelper::ToString (pokemon_.GetExperiencePercentage ())
      + ")"
      */);

    // PictureBoxes
    gender_ = new yap::PictureBox ();
    spriteFront_ = new yap::PictureBox ();
    type1_ = new yap::PictureBox ();
    type2_ = new yap::PictureBox ();

    // Layouts
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
      yap::Padding (0, 8, 0, 20), yap::Padding (0, 0, 26, 0), false);

    hpLayout_ = new yap::VerticalLayout (
      yap::Padding (0, 5, 0, 0), yap::Padding (), false);

    statsLayout_ = new yap::VerticalLayout (
      yap::Padding (0, 5, 0, 0), yap::Padding (0, 0, 9, 0), false);

    experienceLayout_ = 
      new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);
    experiencePointLayout_ = 
      new yap::HorizontalLayout (yap::Padding (), yap::Padding (), false);
    experiencePointLabelLayout_ = 
      new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);
    experiencePointNumberLayout_ = 
      new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);
    nextLevelPointLayout_ = 
      new yap::HorizontalLayout (yap::Padding (), yap::Padding (), false);
    nextLevelPointLabelLayout_ = 
      new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);
    nextLevelPointNumberLayout_ = 
      new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);

    capacityAndExperienceGlobalLayout_ = 
      new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);
    capacityAndExperienceLayout_ = 
      new yap::HorizontalLayout (yap::Padding (), yap::Padding (), false);
    capacityLayout_ = 
      new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);
    experienceBarLayout_ = 
      new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);

    mainLayout_->SetSize (GetSize ());
    firstLine_->SetSize (yap::Vector2 (800, 328));
    firstLinePartLeft_->SetSize (yap::Vector2 (392, 315));
    levelLayout_->SetSize (yap::Vector2 (88, 53));
    nameLayout_->SetSize (yap::Vector2 (240, 53));
    genderLayout_->SetSize (yap::Vector2 (40, 53));
    levelNameGenderLayout_->SetSize (yap::Vector2 (379, 53));
    spriteFrontLayout_->SetSize (yap::Vector2 (363, 233));
    firstLinePartRight_->SetSize (yap::Vector2 (408, 328));

    hpLayout_->SetSize (yap::Vector2 (238, 41));
    statsLayout_->SetSize (yap::Vector2 (135, 236));

    experienceLayout_->SetSize (yap::Vector2 (792, 100));
    experiencePointLayout_->SetSize (yap::Vector2 (546, 48));
    experiencePointLabelLayout_->SetSize (yap::Vector2 (273, 48));
    experiencePointNumberLayout_->SetSize (yap::Vector2 (273, 48));
    nextLevelPointLayout_->SetSize (yap::Vector2 (546, 48));
    nextLevelPointLabelLayout_->SetSize (yap::Vector2 (273, 48));
    nextLevelPointNumberLayout_->SetSize (yap::Vector2 (273, 48));

    capacityAndExperienceGlobalLayout_->SetSize (yap::Vector2 (792, 46));
    capacityAndExperienceLayout_->SetSize (yap::Vector2 (546, 46));
    capacityLayout_ ->SetSize (yap::Vector2 (284, 46));
    experienceBarLayout_->SetSize (yap::Vector2 (262, 46));

    // Set the labels text size
    nameLeft_->SetTextSize (40);
    level_->SetTextSize (40);
    hp_->SetTextSize (40);
    attack_->SetTextSize (40);
    defense_->SetTextSize (40);
    specialAttack_->SetTextSize (40);
    specialDefense_->SetTextSize (40);
    speed_->SetTextSize (40);

    experiencePointLabel_->SetTextSize (40);
    experiencePoint_->SetTextSize (40);
    nextLevelPointLabel_->SetTextSize (40);
    nextLevelPoint_->SetTextSize (40);

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

    spriteFront_->SetPicture (pokemon_.GetBattleFront ().Clone ());

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

    hpLayout_->AddChild (*hp_);
    statsLayout_->AddChild (*attack_);
    statsLayout_->AddChild (*defense_);
    statsLayout_->AddChild (*specialAttack_);
    statsLayout_->AddChild (*specialDefense_);
    statsLayout_->AddChild (*speed_);

    firstLinePartRight_->AddChild (*hpLayout_, yap::LayoutBox::Align::RIGHT);
    firstLinePartRight_->AddChild (*statsLayout_, yap::LayoutBox::Align::RIGHT);

    firstLine_->AddChild (*firstLinePartLeft_, yap::LayoutBox::Align::TOP);
    firstLine_->AddChild (*firstLinePartRight_, yap::LayoutBox::Align::TOP);

    experiencePointNumberLayout_->AddChild (*experiencePoint_);
    experiencePointLabelLayout_->AddChild (*experiencePointLabel_);

    nextLevelPointNumberLayout_->AddChild (*nextLevelPoint_);
    nextLevelPointLabelLayout_->AddChild (*nextLevelPointLabel_);

    experiencePointLayout_->AddChild (
      *experiencePointLabelLayout_, yap::LayoutBox::Align::LEFT);
    experiencePointLayout_->AddChild (
      *experiencePointNumberLayout_, yap::LayoutBox::Align::RIGHT);

    nextLevelPointLayout_->AddChild (
      *nextLevelPointLabelLayout_, yap::LayoutBox::Align::LEFT);
    nextLevelPointLayout_->AddChild (
      *nextLevelPointNumberLayout_, yap::LayoutBox::Align::RIGHT);

    experienceLayout_->AddChild (
      *experiencePointLayout_, yap::LayoutBox::Align::RIGHT);
    experienceLayout_->AddChild (
      *nextLevelPointLayout_, yap::LayoutBox::Align::RIGHT);

    experienceBarLayout_->AddChild (experienceBar_, yap::LayoutBox::Align::RIGHT);

    capacityAndExperienceLayout_->AddChild (*capacityLayout_, yap::LayoutBox::Align::RIGHT);
    capacityAndExperienceLayout_->AddChild (*experienceBarLayout_, yap::LayoutBox::Align::RIGHT);

    capacityAndExperienceGlobalLayout_->AddChild (
      *capacityAndExperienceLayout_, yap::LayoutBox::Align::RIGHT);

    mainLayout_->AddChild (*firstLine_, yap::LayoutBox::Align::LEFT);
    mainLayout_->AddChild (*experienceLayout_, yap::LayoutBox::Align::LEFT);
    mainLayout_->AddChild (*capacityAndExperienceGlobalLayout_, yap::LayoutBox::Align::LEFT);

    /*
    mainLayout_->SetBorder (*new yap::WidgetBorder ("Test/grey.png"));
    firstLine_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    firstLinePartLeft_->SetBorder (*new yap::WidgetBorder ("Test/yellow.png"));
    levelNameGenderLayout_->SetBorder (*new yap::WidgetBorder ("Test/green.png"));
    spriteFrontLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    firstLinePartRight_->SetBorder (*new yap::WidgetBorder ("Test/blue.png"));
    secondLine_->SetBorder (*new yap::WidgetBorder ("Test/orange.png"));
    hpLayout_->SetBorder (*new yap::WidgetBorder ("Test/brown.png"));
    statsLayout_->SetBorder (*new yap::WidgetBorder ("Test/black.png"));

    levelLayout_->SetBorder (*new yap::WidgetBorder ("Test/green.png"));
    nameLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    genderLayout_->SetBorder (*new yap::WidgetBorder ("Test/blue.png"));

    experienceLayout_->SetBorder (*new yap::WidgetBorder ("Test/grey.png"));
    experiencePointLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    experiencePointNumberLayout_->SetBorder (*new yap::WidgetBorder ("Test/yellow.png"));
    experiencePointLabelLayout_->SetBorder (*new yap::WidgetBorder ("Test/green.png"));

    capacityAndExperienceGlobalLayout_->SetBorder (*new yap::WidgetBorder ("Test/green.png"));
    capacityAndExperienceLayout_->SetBorder (*new yap::WidgetBorder ("Test/grey.png"));
    capacityLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    experienceBarLayout_->SetBorder (*new yap::WidgetBorder ("Test/yellow.png"));
    */

    AddChild (*mainLayout_);

    mainLayout_->SetPosition (yap::Vector2 (1, 60));
  }

  bool PokemonStatsInfoWidget::IsFocusable () const
  {
    return false;
  }

  void PokemonStatsInfoWidget::HandleMove (const yap::Vector2& offset)
  {

  }
  void PokemonStatsInfoWidget::HandleScale (const yap::Vector2& factor)
  {

  }
  void PokemonStatsInfoWidget::HandleDraw (yap::IDrawingContext& offset)
  {

  }
  void PokemonStatsInfoWidget::HandleShow (bool isVisible)
  {
  }
  void PokemonStatsInfoWidget::HandleChangeColor (const sf::Color& color)
  {
  }
  void PokemonStatsInfoWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
