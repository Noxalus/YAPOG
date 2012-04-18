#include "YAPOG/Graphics/Gui/GuiManager.hpp"

namespace yap
{
  GuiManager::GuiManager ()
    : BaseWidget ()
  {
  }

  GuiManager::~GuiManager ()
  {
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

  bool GuiManager::HandleOnEvent (const GuiEvent& guiEvent)
  {
    return false;
  }

  bool GuiManager::HandleOnPriorityEvent (const GuiEvent& guiEvent)
  {
    return false;
  }

  void GuiManager::HandleUpdate (const Time& dt)
  {
  }
} // namespace yap
