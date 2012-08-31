#ifndef YAPOG_CLIENT_GAMEGUIMANAGER_HPP
# define YAPOG_CLIENT_GAMEGUIMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/GuiManager.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/System/String.hpp"

namespace ycl
{
  class GameGuiManager : public yap::GuiManager
  {
      DISALLOW_COPY(GameGuiManager);

    public:

      GameGuiManager ();

      virtual ~GameGuiManager ();

      void AddGameWidget (const yap::String& name, yap::IWidget* gameWidget);

      void SetCurrentWidget (const yap::String& name);
      bool UnsetCurrentWidget ();

    protected:

      virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);
      //virtual bool HandleOnPriorityEvent (const yap::GuiEvent& guiEvent);

    private:

      static const bool DEFAULT_ADDED_WIDGET_STATE;

      yap::String currentWidgetName_;
      yap::IWidget* currentWidget_;
      yap::collection::Map<yap::String, yap::IWidget*> gameWidgets_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_GAMEGUIMANAGER_HPP
