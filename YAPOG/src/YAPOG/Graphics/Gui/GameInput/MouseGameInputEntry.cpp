#include "YAPOG/Graphics/Gui/GameInput/MouseGameInputEntry.hpp"

namespace yap
{
  MouseGameInputEntry::MouseGameInputEntry (MouseButton button)
    : GameInputEntry ()
    , button_ (button)
  {
  }

  MouseGameInputEntry::~MouseGameInputEntry ()
  {
  }

  void MouseGameInputEntry::Update (const GuiEvent& guiEvent)
  {
    switch (guiEvent.type)
    {
      case GuiEventType::MouseButtonPressed:

        if (button_ != guiEvent.mouseButton.button)
          break;

        Activate (true);

        break;

      case GuiEventType::MouseButtonReleased:

        if (button_ != guiEvent.mouseButton.button)
          break;

        Activate (false);

        break;

      default:
        break;
    }
  }

  bool MouseGameInputEntry::GuiEventIsCompatible (
    const GuiEvent& guiEvent) const
  {
    return
      (guiEvent.type == GuiEventType::MouseButtonPressed ||
       guiEvent.type == GuiEventType::MouseButtonReleased) &&
      guiEvent.mouseButton.button == button_;
  }
} // namespace yap
