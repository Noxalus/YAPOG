#include "YAPOG/Graphics/Gui/GuiManager.hpp"

namespace yap
{
  const bool GuiManager::DEFAULT_VISIBLE_STATE = true;

  GuiManager::GuiManager ()
    : spatialInfo_ ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
  {
  }

  GuiManager::~GuiManager ()
  {
  }

  void GuiManager::Draw (IDrawingContext& context)
  {
    if (!isVisible_)
      return;
  }

  bool GuiManager::IsVisible () const
  {
    return isVisible_;
  }

  void GuiManager::Show (bool isVisible)
  {
    isVisible_ = isVisible;
  }

  void GuiManager::ChangeColor (const sf::Color color)
  {
  }

  bool GuiManager::OnEvent (const GuiEvent& guiEvent)
  {
    return false;
  }

  void GuiManager::Update (const Time& dt)
  {
  }

  const Vector2& GuiManager::GetPosition () const
  {
    return spatialInfo_.GetPosition ();
  }

  const Vector2& GuiManager::GetSize () const
  {
    return spatialInfo_.GetSize ();
  }

  const Vector2& GuiManager::GetTopLeft () const
  {
    return spatialInfo_.GetTopLeft ();
  }

  const Vector2& GuiManager::GetBottomRight () const
  {
    return spatialInfo_.GetBottomRight ();
  }

  const Vector2& GuiManager::GetCenter () const
  {
    return spatialInfo_.GetCenter ();
  }

  const sf::FloatRect& GuiManager::GetRectangle () const
  {
    return spatialInfo_.GetRectangle ();
  }

  void GuiManager::Move (const Vector2& offset)
  {
    spatialInfo_.SetPosition (GetPosition () + offset);
  }

  void GuiManager::Scale (const Vector2& factor)
  {
    spatialInfo_.SetSize (
      Vector2(GetSize ().x * factor.x,
              GetSize ().y * factor.y));
  }
} // namespace yap
