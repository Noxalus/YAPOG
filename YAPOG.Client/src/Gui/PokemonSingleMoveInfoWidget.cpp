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
#include "YAPOG/Game/Pokemon/PokemonMove.hpp"

#include "Gui/PokemonSingleMoveInfoWidget.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  PokemonSingleMoveInfoWidget::PokemonSingleMoveInfoWidget ()
    : name_ (nullptr)
    , pp_ (nullptr)
    , type_ (nullptr)
    , mainLayout_ ()
    , nameAndTypeLayout_ (nullptr)
    , ppLayout_ (nullptr)
  {
    // Labels
    name_ = new yap::Label ();
    pp_ = new yap::Label ();

    // PictureBox
    type_ = new yap::PictureBox ();

    // Layouts
    mainLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    nameAndTypeLayout_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (0, 10, 0, 0), false);

    ppLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);
  }

  void PokemonSingleMoveInfoWidget::Init ()
  {
    SetSize (yap::Vector2 (393, 94));

    // Set layouts size
    mainLayout_->SetSize (GetSize ());
    nameAndTypeLayout_->SetSize (yap::Vector2 (393, 52));
    ppLayout_->SetSize (yap::Vector2 (393, 42));

    // Set the labels text size
    name_->SetTextSize (40);
    pp_->SetTextSize (40);

    type_->SetPicture (new yap::Sprite ("Pictures/Types/0.png"));

    // Hierarchy construction
    nameAndTypeLayout_->AddChild (*type_);
    nameAndTypeLayout_->AddChild (*name_);

    ppLayout_->AddChild (*pp_, yap::LayoutBox::Align::RIGHT);

    mainLayout_->AddChild (*nameAndTypeLayout_);
    mainLayout_->AddChild (*ppLayout_);

    // Borders
    /*
    mainLayout_->SetBorder (*new yap::WidgetBorder ("Test/black.png"));
    nameAndTypeLayout_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    ppLayout_->SetBorder (*new yap::WidgetBorder ("Test/blue.png"));
    */

    AddChild (*mainLayout_);
  }

  void PokemonSingleMoveInfoWidget::SetPokemonMove (
    const yap::PokemonMove& move)
  {
    // Labels
    name_->SetText (move.GetName ());

    pp_->SetText ("PP " +
      yap::StringHelper::ToString 
      (static_cast<int>(move.GetCurrentPP ()))
      + "/" + 
      yap::StringHelper::ToString 
      (static_cast<int>(move.GetMaxPP ())));

    // PictureBoxes
    type_->SetPicture (new yap::Sprite (
      "Pictures/Types/" + 
      yap::StringHelper::ToString (
      move.GetType ().GetID ().GetValue ()) + ".png"));

    // Refresh
    ppLayout_->Refresh ();
  }

  bool PokemonSingleMoveInfoWidget::IsFocusable () const
  {
    return false;
  }

  void PokemonSingleMoveInfoWidget::HandleMove (const yap::Vector2& offset)
  {

  }
  void PokemonSingleMoveInfoWidget::HandleScale (const yap::Vector2& factor)
  {

  }
  void PokemonSingleMoveInfoWidget::HandleDraw (yap::IDrawingContext& offset)
  {

  }
  void PokemonSingleMoveInfoWidget::HandleShow (bool isVisible)
  {
  }
  void PokemonSingleMoveInfoWidget::HandleChangeColor (const sf::Color& color)
  {
  }
  void PokemonSingleMoveInfoWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
