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

      Vector2 WorldPointToGuiPoint (const Vector3& worldPoint) const;

      const ICamera& GetWorldCamera () const;

    protected:

      virtual const GameWorldGuiManager& GetGameWorldRoot () const;

    private:

      const ICamera& guiCamera_;
      const ICamera& worldCamera_;

      const IWorldDrawingPolicy* worldDrawingPolicy_;
  };
} // namespace yap

#endif // YAPOG_GAMEWORLDGUIMANAGER_HPP
