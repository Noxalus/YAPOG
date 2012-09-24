#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"

namespace yap
{
  PictureBox::PictureBox ()
    : picture_ (nullptr)
  {
  }

  PictureBox::~PictureBox ()
  {
  }

  Vector2 PictureBox::HandleGetSize () const
  {
    return Vector2 (
      padding_.left + picture_->GetSize ().x + padding_.right,
      padding_.top + picture_->GetSize ().y + padding_.bottom)
      + ((border_ != nullptr) ? border_->GetSize () : Vector2 ());
  }

  bool PictureBox::IsFocusable () const
  {
    return false;
  }

  void PictureBox::HandleDraw (IDrawingContext& context)
  {
    picture_->Draw (context);
  }

  void PictureBox::HandleShow (bool isVisible)
  {
  }

  void PictureBox::HandleMove (const Vector2& offset)
  {
    picture_->Move (offset);
    //picture_->SetPosition (GetPosition() + offset);
  }

  void PictureBox::HandleScale (const Vector2& factor)
  {
    Vector2 base = picture_->GetSize ();
    Vector2 neo (base.x * factor.x, base.y * factor.y);

    picture_->SetSize (neo);
  }

  void PictureBox::HandleUpdate (const Time& dt)
  {
  }

  void PictureBox::HandleChangeColor (const sf::Color& color)
  {
    picture_->ChangeColor (color);
  }

  const ISprite& PictureBox::GetPicture () const
  {
    return *picture_;
  }

  void PictureBox::SetPicture (ISprite* picture)
  {
    if (picture_ != nullptr)
      delete picture_;

    picture_ = picture;

    picture_->SetPosition (Vector2 (GetPosition ().x + padding_.left,
      GetPosition ().y + padding_.top));

    BaseWidget::Refresh ();
  }
} //namespace yap