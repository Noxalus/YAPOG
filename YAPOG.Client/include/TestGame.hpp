#ifndef YAPOG_CLIENT_DEMOGAME_HPP
# define YAPOG_CLIENT_DEMOGAME_HPP

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

  /// @brief A game for testing.
  class TestGame : public yap::Game
  {
    public:

      TestGame (const yap::String& name);
      virtual ~TestGame ();

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

#endif // YAPOG_CLIENT_DEMOGAME_HPP
