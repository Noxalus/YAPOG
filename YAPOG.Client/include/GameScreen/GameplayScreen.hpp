#ifndef YAPOG_CLIENT_GAMEPLAYSCREEN_HPP
# define YAPOG_CLIENT_GAMEPLAYSCREEN_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/CharacterMoveController.hpp"
# include "YAPOG/Graphics/ProgressiveCameraController.hpp"
# include "YAPOG/System/Time/Timer.hpp"

# include "GameScreen/BaseScreen.hpp"
# include "World/World.hpp"

namespace yap
{
  struct IWorldDrawingPolicy;

  class GameWorldGuiManager;
} // namespace yap

namespace ycl
{
  class Player;
  class GameGuiManager;
  class GameMainMenu;
  class PokedexCompositeWidget;
  class PokedexWidget;
  class PokemonTeamWidget;
  class ChatWidget;
  class MapRootWidget;
  class TrainerCardWidget;

  class GameplayScreen : public BaseScreen
  {
      DISALLOW_COPY(GameplayScreen);

    public:

      explicit GameplayScreen (yap::IDrawingContext& context);
      virtual ~GameplayScreen ();

    protected:

      virtual void HandleInit ();

      virtual void HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);

      virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);
      virtual void HandleActivate ();
      virtual void HandleDeactivate ();

    private:

      Map& GetCurrentMap ();
      void SetCurrentMap (Map& map);
      void SetPlayer (Player* player);

      void SetPlayerName ();

      void UpdatePlayer (const yap::Time& dt);
      void HandleOnPlayerWarped ();

      void ResetMoveController ();

      void SendApplyForce (const yap::Vector2& force);
      void SendGameInput (yap::GameInputType gameInputType, bool state);

      void CreateWorldDrawingPolicy ();

      virtual void CreateGuiManager ();

      static const yap::ScreenType DEFAULT_NAME;

      static const yap::Vector2 DEFAULT_WORLD_CAMERA_DEZOOM_FACTOR;

      World world_;
      const yap::IWorldDrawingPolicy* worldDrawingPolicy_;

      yap::ProgressiveCameraController cameraController_;

      Player* player_;
      yap::CharacterMoveController moveController_;
      yap::Vector2 lastForce_;

      yap::Timer fpsDisplayTimer_;

      /// @name Widgets.
      /// @{
      GameGuiManager* gameGuiManager_;

      yap::GameWorldGuiManager* gameWorldGuiManager_;
      MapRootWidget* mapRootWidget_;

      GameMainMenu* mainMenu_;

      PokedexWidget* pokedexWidget_;
      PokemonTeamWidget* pokemonTeamWidget_;

      TrainerCardWidget* trainerCardWidget_;

      ChatWidget* chat_;

      yap::Label* fpsLabel_;
      /// @}
  };
} // namespace ycl

#endif // YAPOG_CLIENT_GAMEPLAYSCREEN_HPP
