#include "YAPOG/Graphics/Gui/GuiManager.hpp"

namespace yap
{
  GuiManager::GuiManager ()
    : BaseWidget ()
  {
  }
  bool GuiManager::IsFocusable () const
  {
    return false;
  }

  GuiManager::~GuiManager ()
  {
  }

  bool GuiManager::HandleOnPriorityEvent (const GuiEvent& guiEvent)
  {
    if (!isEnable)
      return false;

    for (IWidget* child : childen_)
    {
      if (child->IsFocusable ())
      {
        child->SetFocused (true);
        return false;
      }
    }
    return false;
  }

  void GuiManager::HandleMove (const Vector2& offset)
  {
  }

  void GuiManager::HandleScale (const Vector2& factor)
  {
  }

  void GuiManager::HandleDraw (IDrawingContext& context)
  {
  }

  void GuiManager::HandleShow (bool isVisible)
  {
  }

  void GuiManager::HandleChangeColor (const sf::Color& color)
  {
  }

  void GuiManager::HandleUpdate (const Time& dt)
  {
  }
} // namespace yap
