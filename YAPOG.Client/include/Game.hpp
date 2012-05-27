#ifndef YAPOG_CLIENT_GAME_HPP
# define YAPOG_CLIENT_GAME_HPP

# include "YAPOG/Graphics/Game/Game.hpp"
# include "YAPOG/System/Path.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class ContentManager;
  class ObjectFactory;
  class WorldObjectStateFactory;
  class GameInputManager;
  class Logger;
} // namespace yap

namespace ycl
{
  class Session;

  class Game : public yap::Game
  {
    public:

      Game (const yap::String& name);
      virtual ~Game ();

      virtual void HandleInit ();
      virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);

      virtual void HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);

      virtual void HandleDispose ();

      static const yap::Vector2 SCREEN_SIZE;

    private:

      void InitRandom ();
      void InitContentManager (const yap::Path& contentRootPath);
      void InitObjectFactory ();
      void InitWorldObjectStateFactory ();
      void InitGameInputManager ();
      void InitDrawingContext (const yap::Vector2& resolution);
      void InitScreenManager ();

      void InitLoggerManager ();

      Session& session_;

      yap::ContentManager& contentManager_;

      yap::ObjectFactory& objectFactory_;
      yap::WorldObjectStateFactory& worldObjectStateFactory_;

      yap::GameInputManager& gameInputManager_;

      yap::Logger& logger_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_GAME_HPP
