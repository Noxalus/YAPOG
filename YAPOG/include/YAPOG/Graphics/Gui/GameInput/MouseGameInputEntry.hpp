#ifndef YAPOG_MOUSEGAMEINPUTENTRY_HPP
# define YAPOG_MOUSEGAMEINPUTENTRY_HPP

# include <SFML/Window/Mouse.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/GameInput/GameInputEntry.hpp"

namespace yap
{
  typedef sf::Mouse::Button MouseButton;

  class YAPOG_LIB MouseGameInputEntry : public GameInputEntry
  {
    public:

      MouseGameInputEntry (MouseButton button);
      virtual ~MouseGameInputEntry ();

      virtual void Update (const GuiEvent& guiEvent);

    private:

      MouseButton button_;
  };
} // namespace yap

#endif // YAPOG_MOUSEGAMEINPUTENTRY_HPP
