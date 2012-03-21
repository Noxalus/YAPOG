#ifndef YAPOG_GUIEVENT_HPP
# define YAPOG_GUIEVENT_HPP

# include <SFML/Window.hpp>

# include "YAPOG/Export.hpp"

namespace yap
{
  typedef sf::Event GuiEventType;

  class GuiEvent : public sf::Event
  {
  };
} /// namespace yap

#endif /// !YAPOG_GUIEVENT_HPP
