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
  PokemonStatsInfoWidget::PokemonStatsInfoWidget ()
    : hp_ (nullptr)
    , attack_ (nullptr)
    , defense_ (nullptr)
    , specialAttack_ (nullptr)
    , specialDefense_ (nullptr)
    , speed_ (nullptr)
    , experiencePointLabel_ (nullptr)
    , experiencePoint_ (nullptr)
    , nextLevelPointLabel_ (nullptr)
    , nextLevelPoint_ (nullptr)
    , type1_ (nullptr)
    , type2_ (nullptr)
    , mainLayout_ (nullptr)
    , firstLine_ (nullptr)
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
    , pokemonFrontInfoWidget_ ()
    , experienceBarWidget_ ()
  {
    // Labels
    hp_ = new yap::Label ();
    attack_ = new yap::Label ();
    defense_ = new yap::Label ();
    specialAttack_ = new yap::Label ();
    specialDefense_ = new yap::Label ();
    speed_ = new yap::Label ();

    experiencePointLabel_ = new yap::Label ("Points:");
    experiencePoint_ = new yap::Label ();
    nextLevelPointLabel_ = new yap::Label ("N. suivant:");
    nextLevelPoint_ = new yap::Label ();

    // PictureBoxes
    type1_ = new yap::PictureBox ();
    type2_ = new yap::PictureBox ();

    // Layouts
    mainLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLine_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLinePartRight_ = new yap::VerticalLayout (
      yap::Padding (0, 8, 0, 20), yap::Padding (0, 0, 26, 0), false);

    hpLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    statsLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (0, 0, 9, 0), false);

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
  }

  void PokemonStatsInfoWidget::Init ()
  {
    // Init widgets
    pokemonFrontInfoWidget_.Init ();
    experienceBarWidget_.Init ();

    SetBackground (*new yap::WidgetBackground (
      "Pictures/TeamManager/PokemonStatsInfoBackground.png", true));

    type1_->SetPicture (
      new yap::Sprite ("Pictures/Types/0.png"));

    type2_->SetPicture (
      new yap::Sprite ("Pictures/Types/0.png"));

    // Sizes
    mainLayout_->SetSize (GetSize ());
    firstLine_->SetSize (yap::Vector2 (800, 328));
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

    // Hierarchy construction
    hpLayout_->AddChild (*hp_);

    statsLayout_->AddChild (*attack_);
    statsLayout_->AddChild (*defense_);
    statsLayout_->AddChild (*specialAttack_);
    statsLayout_->AddChild (*specialDefense_);
    statsLayout_->AddChild (*speed_);

    firstLinePartRight_->AddChild (*hpLayout_, yap::LayoutBox::Align::RIGHT);
    firstLinePartRight_->AddChild (*statsLayout_, yap::LayoutBox::Align::RIGHT);

    firstLine_->AddChild (pokemonFrontInfoWidget_, yap::LayoutBox::Align::TOP);
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

    experienceBarLayout_->AddChild (experienceBarWidget_, yap::LayoutBox::Align::RIGHT);

    capacityAndExperienceLayout_->AddChild (*capacityLayout_, yap::LayoutBox::Align::RIGHT);
    capacityAndExperienceLayout_->AddChild (*experienceBarLayout_, yap::LayoutBox::Align::RIGHT);

    capacityAndExperienceGlobalLayout_->AddChild (
      *capacityAndExperienceLayout_, yap::LayoutBox::Align::RIGHT);

    mainLayout_->AddChild (*firstLine_, yap::LayoutBox::Align::LEFT);
    mainLayout_->AddChild (*experienceLayout_, yap::LayoutBox::Align::LEFT);
    mainLayout_->AddChild (*capacityAndExperienceGlobalLayout_, yap::LayoutBox::Align::LEFT);

    // Borders
    /*
    mainLayout_->SetBorder (*new yap::WidgetBorder ("Test/grey.png"));
    firstLine_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    firstLinePartRight_->SetBorder (*new yap::WidgetBorder ("Test/blue.png"));
    hpLayout_->SetBorder (*new yap::WidgetBorder ("Test/brown.png"));
    statsLayout_->SetBorder (*new yap::WidgetBorder ("Test/black.png"));

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

  void PokemonStatsInfoWidget::SetPokemon (const Pokemon& pokemon)
  {
      pokemonFrontInfoWidget_.SetPokemon (pokemon);
      experienceBarWidget_.SetPokemon (pokemon);

      // Labels
      hp_->SetText (
        yap::StringHelper::ToString 
        (pokemon.GetStats ().GetHitPoint ().GetCurrentValue ())
        + "/" +
        yap::StringHelper::ToString 
        (pokemon.GetStats ().GetHitPoint ().GetValue ()));

      attack_->SetText (
        yap::StringHelper::ToString 
        (pokemon.GetStats ().GetAttack ().GetValue ()));

      defense_->SetText (
        yap::StringHelper::ToString 
        (pokemon.GetStats ().GetDefense ().GetValue ()));

      specialAttack_->SetText (
        yap::StringHelper::ToString 
        (pokemon.GetStats ().GetSpecialAttack ().GetValue ()));

      specialDefense_->SetText (
        yap::StringHelper::ToString 
        (pokemon.GetStats ().GetSpecialDefense ().GetValue ()));

      speed_->SetText (
        yap::StringHelper::ToString 
        (pokemon.GetStats ().GetSpeed ().GetValue ()));

      experiencePoint_->SetText (
        yap::StringHelper::ToString (
        static_cast<int>(pokemon.GetTotalExperience ())));

      nextLevelPoint_->SetText (
        yap::StringHelper::ToString (
        static_cast<int>(pokemon.GetExperienceToNextLevel ())));

      type1_->SetPicture (pokemon.GetType1Icon ().Clone ());
      type2_->SetPicture (pokemon.GetType2Icon ().Clone ());

      // Refresh layouts to center labels
      hpLayout_->Refresh ();
      statsLayout_->Refresh ();
      experiencePointNumberLayout_->Refresh ();
      nextLevelPointNumberLayout_->Refresh ();
  }

  /// @name IWidget members.
  /// {
  /*
  void PokemonStatsInfoWidget::SetDefaultColor (const sf::Color& color)
  {}
  void PokemonStatsInfoWidget::AddDrawable (yap::IDrawable& drawable)
  {}
  void PokemonStatsInfoWidget::AddChild (yap::IWidget& child)
  {}
  yap::IWidget& PokemonStatsInfoWidget::GetRoot () const
  { return GetRoot (); }
  yap::WidgetBorder* PokemonStatsInfoWidget::GetBorder () const
  { return GetBorder (); }
  void PokemonStatsInfoWidget::SetParent (yap::IWidget& parent)
  {}
  void PokemonStatsInfoWidget::SetPadding (const yap::Padding& padding)
  {}
  void PokemonStatsInfoWidget::SetBackground (yap::WidgetBackground& background)
  {}
  void PokemonStatsInfoWidget::SetBorder  (yap::WidgetBorder& border, yap::uint width)
  {}
  void PokemonStatsInfoWidget::Refresh ()
  {}
  */
  bool PokemonStatsInfoWidget::IsFocusable () const
  {
    return false;
  }
  /*
  void PokemonStatsInfoWidget::SetFocused (bool state)
  {}
  void PokemonStatsInfoWidget::SetEnable (bool enable)
  {}
  void PokemonStatsInfoWidget::Open ()
  {}
  void PokemonStatsInfoWidget::Close ()
  {}
  */
  /// }

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
