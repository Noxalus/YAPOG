#ifndef YAPOG_EVENT_HPP
# define YAPOG_EVENT_HPP

# include <boost/signal.hpp>

# include "YAPOG/Export.hpp"

namespace yap
{
  /// @class Event
  /// @brief Provides a way to handle asynchronous event notification.
  template <typename SenderType,
            typename ArgsType,
            typename ReturnType = void>
  class YAPOG_LIB Event
  {
      typedef boost::signal2<ReturnType, SenderType, ArgsType> Signal;
      typedef ReturnType (*Handler) (SenderType, ArgsType);

    public:

      /// @brief Constructs the event by default.
      Event ();
      /// @brief Destructor of the event.
      ~Event ();

      /// @brief Makes the handler subscribe to this event.
      /// @param handler Handler to make subscribe to this event.
      Event& operator+= (const Handler handler);
      /// @brief Stops the subscription of the handler to this event.
      /// @param handler Handler to unmake subscribe to this event.
      Event& operator-= (const Handler handler);
      /// @brief Notifies every handler that subscribed to this event.
      /// @param sender Source of this event.
      /// @param args Arguments of this event.
      ReturnType operator() (SenderType sender, ArgsType args);

    private:

      Signal sig_;
  };
} /// namespace yap

# include "YAPOG/Event/Event.hxx"

#endif /// !YAPOG_EVENT_HPP
