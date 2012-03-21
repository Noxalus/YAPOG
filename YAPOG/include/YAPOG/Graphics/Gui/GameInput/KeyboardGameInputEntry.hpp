#ifndef YAPOG_KEYBOARDGAMEINPUTENTRY_HPP
# define YAPOG_KEYBOARDGAMEINPUTENTRY_HPP

# include <SFML/Window.hpp>

# include "YAPOG/Export.hpp"
# include "YAPOG/Graphics/Gui/GameInput/GameInputEntry.hpp"

namespace yap
{
  typedef sf::Keyboard::Key Key;

  class KeyboardGameInputEntry : public GameInputEntry
  {
    public:

      KeyboardGameInputEntry (Key key);
      virtual ~KeyboardGameInputEntry ();

      virtual void Update (const GuiEvent& guiEvent);

    private:

      Key key_;
  };
} /// namespace yap

#endif /// !YAPOG_KEYBOARDGAMEINPUTENTRY_HPP
