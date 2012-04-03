#ifndef YAPOG_KEYBOARDGAMEINPUTENTRY_HPP
# define YAPOG_KEYBOARDGAMEINPUTENTRY_HPP

# include <SFML/Window/Keyboard.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/GameInput/GameInputEntry.hpp"

namespace yap
{
  typedef sf::Keyboard::Key Key;

  class YAPOG_LIB KeyboardGameInputEntry : public GameInputEntry
  {
      DISALLOW_COPY(KeyboardGameInputEntry);

    public:

      explicit KeyboardGameInputEntry (Key key);
      virtual ~KeyboardGameInputEntry ();

      virtual void Update (const GuiEvent& guiEvent);

    private:

      Key key_;
  };
} // namespace yap

#endif // YAPOG_KEYBOARDGAMEINPUTENTRY_HPP
