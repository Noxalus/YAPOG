#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"

namespace yap
{
  PictureBox::PictureBox ()
    : picture_ ()
  {
  }

  PictureBox::~PictureBox ()
  {
  }

  Vector2 PictureBox::HandleGetSize () const
  {
    return Vector2 (padding_->left + picture_.GetSize ().x + padding_->right,
      padding_->top + picture_.GetSize ().y + padding_->bottom)
      + ((border_ != nullptr) ? border_->GetSize () : Vector2 ());
  }

  bool PictureBox::IsFocusable () const
  {
    return false;
  }

  void PictureBox::HandleDraw (IDrawingContext& context)
  {
    picture_.Draw (context);
  }

  void PictureBox::HandleShow (bool isVisible)
  {
  }

  void PictureBox::HandleMove (const Vector2& offset)
  {
    picture_.Move (offset);
    //picture_.SetPosition (GetPosition() + offset);
  }

  void PictureBox::HandleScale (const Vector2& factor)
  {
    Vector2 base = picture_.GetSize ();
    Vector2 neo (base.x * factor.x, base.y * factor.y);

    picture_.SetSize (neo);
  }

  void PictureBox::HandleUpdate (const Time& dt)
  {
  }

  void PictureBox::HandleChangeColor (const sf::Color& color)
  {
  }

  const Texture& PictureBox::GetPicture () const
  {
    return picture_;
  }

  void PictureBox::SetPicture (String file)
  {
    picture_.LoadFromFile (file);
    picture_.SetPosition (Vector2 (GetPosition ().x + padding_->left,
      GetPosition ().y + padding_->top));

    OnPictureSet (*this, EventArgsTexture (picture_));
  }
} //namespace yap