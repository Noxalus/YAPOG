#include "YAPOG/Graphics/Gui/GuiManager.hpp"

namespace yap
{
  GuiManager::GuiManager ()
    : spatialInfo_ ()
  {
  }

  GuiManager::~GuiManager ()
  {
  }

  void GuiManager::Draw (IDrawingContext& context)
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
