#ifndef YAPOG_GUIEVENT_HPP
# define YAPOG_GUIEVENT_HPP

# include <SFML/Window/Event.hpp>

# include "YAPOG/Macros.hpp"

namespace yap
{
  /// SFML Event.
  typedef sf::Event::EventType GuiEventType;

  class YAPOG_LIB GuiEvent : public sf::Event
  {
      DISALLOW_COPY(GuiEvent);

    public:

      GuiEvent ();
      virtual ~GuiEvent ();
  };
} // namespace yap

#endif // YAPOG_GUIEVENT_HPP
