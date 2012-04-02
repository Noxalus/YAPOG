#ifndef YAPOG_EVENT_HPP
# define YAPOG_EVENT_HPP

# include <boost/signal.hpp>

# include "YAPOG/Macros.hpp"

namespace yap
{
  template <typename SenderType,
            typename ArgsType,
            typename ReturnType = void>
  class YAPOG_LIB Event
  {
      DISALLOW_COPY(Event);

      typedef boost::signal2<ReturnType, SenderType, ArgsType> SignalType;
      typedef ReturnType (*HandlerType) (SenderType, ArgsType);

    public:

      Event ();
      ~Event ();

      Event& operator+= (const HandlerType handler);
      Event& operator-= (const HandlerType handler);

      ReturnType operator() (SenderType sender, ArgsType args);

    private:

      SignalType sig_;
  };
} // namespace yap

# include "YAPOG/System/Event/Event.hxx"

#endif // YAPOG_EVENT_HPP
