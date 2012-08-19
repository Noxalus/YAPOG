#ifndef YAPOG_GAMEWORLDGUIMANAGER_HPP
# define YAPOG_GAMEWORLDGUIMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Game/World/GameWorldWidget.hpp"

namespace yap
{
  struct ICamera;
  struct IWorldDrawingPolicy;

  class GameWorldGuiManager : public GameWorldWidget
  {
      DISALLOW_COPY(GameWorldGuiManager);

    public:

      GameWorldGuiManager (
        const ICamera& guiCamera,
        const ICamera& worldCamera,
        const IWorldDrawingPolicy& worldDrawingPolicy);

      virtual ~GameWorldGuiManager ();

      void SetWorldDrawingPolicy (
        const IWorldDrawingPolicy& worldDrawingPolicy);

      void AddGameWorldWidget (GameWorldWidget* gameWorldWidget);

      Vector2 WorldPointToGuiPoint (const Vector3& worldPoint);

      virtual bool IsFocusable () const;

    private:

      const ICamera& guiCamera_;
      const ICamera& worldCamera_;

      const IWorldDrawingPolicy* worldDrawingPolicy_;

      collection::List<GameWorldWidget*> gameWorldWidgets_;
  };
} // namespace yap

#endif // YAPOG_GAMEWORLDGUIMANAGER_HPP
