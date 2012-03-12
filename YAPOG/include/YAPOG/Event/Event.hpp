#ifndef YAPOG_EVENT_HPP
# define YAPOG_EVENT_HPP

# include <boost/signal.hpp>

# include "YAPOG/Export.hpp"

namespace yap
{
  template <typename SenderType,
            typename ArgsType,
            typename ReturnType = void>
  class YAPOG_LIB Event
  {
      typedef boost::signal2<ReturnType, SenderType, ArgsType> Signal;
      typedef ReturnType (*Handler) (SenderType, ArgsType);

    public:

      Event ();
      ~Event ();

      Event& operator+= (const Handler handler);
      Event& operator-= (const Handler handler);

      ReturnType operator() (SenderType sender, ArgsType args);

    private:

      Signal sig_;
  };
} /// namespace yap

# include "YAPOG/Event/Event.hxx"

#endif /// !YAPOG_EVENT_HPP
