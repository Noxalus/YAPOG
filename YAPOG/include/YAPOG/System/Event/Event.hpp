#ifndef YAPOG_EVENT_HPP
# define YAPOG_EVENT_HPP

# include <functional>

# include <boost/signal.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/System/String.hpp"

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
      typedef typename SignalType::slot_type HandlerType;

    public:

      Event ();
      ~Event ();

      Event& operator+= (const HandlerType handler);

      void AddHandler (const String& name, const HandlerType handler);
      void RemoveHandler (const String& name);

      ReturnType operator() (SenderType sender, ArgsType args);

    private:

      typedef boost::signals::connection ConnectionType;

      SignalType sig_;

      collection::Map<String, ConnectionType> handlers_;
  };
} // namespace yap

# include "YAPOG/System/Event/Event.hxx"

#endif // YAPOG_EVENT_HPP
