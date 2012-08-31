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
#include "YAPOG/Game/Factory/ICloneable.hpp"

#include "Gui/PokemonBasicInfoWidget.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  PokemonBasicInfoWidget::PokemonBasicInfoWidget ()
    : name_ (nullptr)
    , staticID_ (nullptr)
    , trainerName_ (nullptr)
    , uniqueID_ (nullptr)
    , item_ (nullptr)
    , nature_ (nullptr)
    , type1_ (nullptr)
    , type2_ (nullptr)
    , mainLayout_ (nullptr)
    , firstLine_ (nullptr)
    , firstLinePartRight_ (nullptr)
    , typesLayout_ (nullptr)
    , secondLine_ (nullptr)
    , pokemonFrontInfoWidget_ ()
  {
    // Labels
    name_ = new yap::Label ();
    staticID_ = new yap::Label ();
    trainerName_ = new yap::Label ();
    uniqueID_ = new yap::Label ();
    item_ = new yap::Label ("Aucun");
    nature_ = new yap::MultiLabelWidget (
      yap::Padding (20, 0, 0, 0), yap::Padding (), false);

    // PictureBoxes
    type1_ = new yap::PictureBox ();
    type2_ = new yap::PictureBox ();

    type1_->SetPicture (
      new yap::Sprite ("Pictures/Types/0.png"));
    type2_->SetPicture (
      new yap::Sprite ("Pictures/Types/0.png"));

    // Layout
    mainLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLine_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLinePartRight_ = new yap::VerticalLayout (
      yap::Padding (160, 0, 0, 12), yap::Padding (0, 0, 16, 0), false);

    typesLayout_ = new yap::HorizontalLayout (
      yap::Padding (0, 0, 0, 0), yap::Padding (0, 10, 0, 0), true);

    secondLine_ = new yap::VerticalLayout (
      yap::Padding (50, 0, 0, 30), yap::Padding (), false);
  }

  void PokemonBasicInfoWidget::Init ()
  {
    SetBackground (*new yap::WidgetBackground (
      "Pictures/TeamManager/PokemonBasicInfoBackground.png", true));

    pokemonFrontInfoWidget_.Init ();

    // Sizes
    mainLayout_->SetSize (GetSize ());
    firstLine_->SetSize (yap::Vector2 (800, 355));
    firstLinePartRight_->SetSize (yap::Vector2 (408, 346));
    secondLine_->SetSize (yap::Vector2 (800, 175));
    nature_->SetSize (secondLine_->GetSize ());

    // Set the labels text size
    name_->SetTextSize (40);
    staticID_->SetTextSize (40);
    trainerName_->SetTextSize (40);
    uniqueID_->SetTextSize (40);
    item_->SetTextSize (40);

    // Hierarchy construction
    typesLayout_->AddChild (*type1_);
    typesLayout_->AddChild (*type2_);

    firstLinePartRight_->AddChild (*staticID_, yap::LayoutBox::Align::LEFT);
    firstLinePartRight_->AddChild (*name_, yap::LayoutBox::Align::LEFT);
    firstLinePartRight_->AddChild (*typesLayout_, yap::LayoutBox::Align::LEFT);
    firstLinePartRight_->AddChild (*trainerName_, yap::LayoutBox::Align::LEFT);
    firstLinePartRight_->AddChild (*uniqueID_, yap::LayoutBox::Align::LEFT);
    firstLinePartRight_->AddChild (*item_, yap::LayoutBox::Align::LEFT);

    firstLine_->AddChild (pokemonFrontInfoWidget_, yap::LayoutBox::Align::TOP);
    firstLine_->AddChild (*firstLinePartRight_, yap::LayoutBox::Align::TOP);

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

  void PokemonBasicInfoWidget::SetPokemon (const Pokemon& pokemon)
  {
    pokemonFrontInfoWidget_.SetPokemon (pokemon);

    // Labels
    name_->SetText (pokemon.GetName ());

    staticID_->SetText (
      yap::StringHelper::ToString 
      (pokemon.GetStaticID ().GetValue ()));

    trainerName_->SetText (pokemon.GetTrainerName ());

    uniqueID_->SetText (
      yap::StringHelper::ToString 
      (pokemon.GetUniqueID ().GetValue ()));

    type1_->SetPicture (pokemon.GetType1Icon ().Clone ());
    type2_->SetPicture (pokemon.GetType2Icon ().Clone ());

    nature_->Clear ();
    nature_->AddText (
      pokemon.GetNature ().GetName () + " de nature.", 50);
  }

  /// @name IWidget members.
  /// {
  /*
  void PokemonBasicInfoWidget::SetDefaultColor (const sf::Color& color)
  {}
  void PokemonBasicInfoWidget::AddDrawable (yap::IDrawable& drawable)
  {}
  void PokemonBasicInfoWidget::AddChild (yap::IWidget& child)
  {}
  yap::IWidget& PokemonBasicInfoWidget::GetRoot () const
  { return GetRoot (); }
  yap::WidgetBorder* PokemonBasicInfoWidget::GetBorder () const
  { return GetBorder (); }
  void PokemonBasicInfoWidget::SetParent (yap::IWidget& parent)
  {}
  void PokemonBasicInfoWidget::SetPadding (const yap::Padding& padding)
  {}
  void PokemonBasicInfoWidget::SetBackground (yap::WidgetBackground& background)
  {}
  void PokemonBasicInfoWidget::SetBorder  (yap::WidgetBorder& border, yap::uint width)
  {}
  void PokemonBasicInfoWidget::Refresh ()
  {}
  */
  bool PokemonBasicInfoWidget::IsFocusable () const
  {
    return false;
  }
  /*
  void PokemonBasicInfoWidget::SetFocused (bool state)
  {}
  void PokemonBasicInfoWidget::SetEnable (bool enable)
  {}
  void PokemonBasicInfoWidget::Open ()
  {}
  void PokemonBasicInfoWidget::Close ()
  {}
  */
  /// }

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
