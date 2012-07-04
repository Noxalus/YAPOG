#ifndef YAPOG_CLIENT_GAMEPLAYSCREEN_HPP
# define YAPOG_CLIENT_GAMEPLAYSCREEN_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/CharacterMoveController.hpp"
# include "YAPOG/Graphics/ProgressiveCameraController.hpp"
# include "YAPOG/System/Time/Timer.hpp"

# include "GameScreen/BaseScreen.hpp"
# include "World/World.hpp"

namespace ycl
{
  class Player;
  class GameGuiManager;
  class GameMainMenu;
  class PokedexCompositeWidget;
  class PokedexWidget;
  class PokemonTeamWidget;
  class ChatWidget;

  class GameplayScreen : public BaseScreen
  {
      DISALLOW_COPY(GameplayScreen);

    public:

      explicit GameplayScreen (yap::ICamera& worldCamera);
      virtual ~GameplayScreen ();

    protected:

      virtual void HandleInit ();

      virtual void HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);

      virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);
      virtual void HandleActivate ();

    private:

      Map& GetCurrentMap ();
      void SetCurrentMap (Map& map);
      void SetPlayer (Player* player);

      void SetPlayerName ();

      void UpdatePlayer (const yap::Time& dt);
      void HandleOnPlayerWarped ();

      void SendApplyForce (const yap::Vector2& force);
      void SendGameInput (yap::GameInputType gameInputType, bool state);

      virtual void CreateGuiManager ();

      static const yap::ScreenType DEFAULT_NAME;

      static const yap::Vector2 DEFAULT_WORLD_CAMERA_DEZOOM_FACTOR;

      World world_;

      yap::ICamera& worldCamera_;
      yap::ProgressiveCameraController cameraController_;

      Player* player_;
      yap::CharacterMoveController moveController_;
      yap::Vector2 lastForce_;

      yap::Timer fpsDisplayTimer_;

      /// @name Widgets.
      /// @{
      GameGuiManager* gameGuiManager_;

      GameMainMenu* mainMenu_;

      PokedexWidget* pokedex_;
      PokemonTeamWidget* pokemonTeam_;

      ChatWidget* chat_;

      yap::Label* fpsLabel_;
      /// @}
  };
} // namespace ycl

#endif // YAPOG_CLIENT_GAMEPLAYSCREEN_HPP
