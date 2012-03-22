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
    switch (guiEvent.Type)
    {
      case GuiEventType::MouseButtonPressed:

        if (button_ != guiEvent.MouseButton.Button)
          break;

        Activate (true);

        break;

      case GuiEventType::MouseButtonReleased:

        if (button_ != guiEvent.MouseButton.Button)
          break;

        Activate (false);

        break;

      default:
        break;
    }
  }
} // namespace yap
