#ifndef YAPOG_IEVENTHANDLER_HPP
# define YAPOG_IEVENTHANDLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/GuiEvent.hpp"

namespace yap
{
  /// @brief An object able to treat a GuiEvent.
  struct YAPOG_LIB IEventHandler
  {
      virtual ~IEventHandler () {}

      /// @brief Treats an event.
      /// @param guiEvent The event to treat.
      /// @return True if the handler is concerned by the events
      /// and treated it, else false.
      virtual bool OnEvent (const GuiEvent& guiEvent) = 0;
  };
} // namespace yap

#endif // YAPOG_IEVENTHANDLER_HPP
