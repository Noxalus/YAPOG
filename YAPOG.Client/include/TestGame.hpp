#ifndef YAPOG_CLIENT_DEMOGAME_HPP
# define YAPOG_CLIENT_DEMOGAME_HPP

# include "YAPOG/Graphics/Game/Game.hpp"

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

    private:

      Session& session_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_DEMOGAME_HPP
