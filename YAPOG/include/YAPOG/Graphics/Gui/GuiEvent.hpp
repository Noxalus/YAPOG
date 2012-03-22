#ifndef YAPOG_GUIEVENT_HPP
# define YAPOG_GUIEVENT_HPP

# include <SFML/Window/Event.hpp>

# include "YAPOG/Macros.hpp"

namespace yap
{
  typedef sf::Event GuiEventType;

  class YAPOG_LIB GuiEvent : public sf::Event
  {
  };
} // namespace yap

#endif // YAPOG_GUIEVENT_HPP
