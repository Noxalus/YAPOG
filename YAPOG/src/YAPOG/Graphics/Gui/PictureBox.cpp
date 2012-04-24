#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"

namespace yap
{
  PictureBox::PictureBox ()
    : picture_ ()
  {
  }

  PictureBox::~PictureBox ()
  {
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
    picture_.SetPosition (GetPosition() + offset);
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
    OnPictureSet (*this, EventArgsTexture (picture_));
  }
} //namespace yap