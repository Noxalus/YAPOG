#ifndef YAPOG_DEMOGAME_HPP
# define YAPOG_DEMOGAME_HPP

# include "YAPOG/Graphics/Game/Game.hpp"

namespace ycl
{
/// @brief A game for testing.
  class TestGame : public yap::Game
  {
    public:

      TestGame (const yap::String& name);
      virtual ~TestGame ();

      virtual void HandleInit ();
      virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);
  };
} // namespace ycl

#endif // YAPOG_DEMOGAME_HPP
