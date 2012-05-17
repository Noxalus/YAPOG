#ifndef YAPOG_EVENT_HPP
# define YAPOG_EVENT_HPP

# include <functional>

# include <boost/signal.hpp>

# include "YAPOG/Macros.hpp"

namespace yap
{
  class YAPOG_LIB EmptyEventArgs { };

  template <typename T>
  class ConstChangeEventArgs
  {
    public: ConstChangeEventArgs (const T& old, const T& current)
      : Old (old), Current (current) { }
      const T& Old, Current;
  };

  template <typename T>
  class ChangeEventArgs
  {
    public: ChangeEventArgs (T& old, T& current)
      : Old (old), Current (current) { }
      T& Old, Current;
  };

  template <typename SenderType,
            typename ArgsType = const EmptyEventArgs&,
            typename ReturnType = void>
  class Event
  {
      DISALLOW_COPY(Event);

      typedef boost::signal2<ReturnType, SenderType, ArgsType> SignalType;
      typedef std::function<ReturnType (SenderType, ArgsType)> HandlerType;

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
