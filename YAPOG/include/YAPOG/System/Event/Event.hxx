#ifndef YAPOG_EVENT_HXX
# define YAPOG_EVENT_HXX

namespace yap
{
  template<typename SenderType,
           typename ArgsType,
           typename ReturnType>
  inline Event<SenderType, ArgsType, ReturnType>::Event ()
    : sig_ ()
    , handlers_ ()
  {
  }

  template <typename SenderType,
            typename ArgsType,
            typename ReturnType>
  inline Event<SenderType, ArgsType, ReturnType>::~Event ()
  {
  }

  template <typename SenderType,
            typename ArgsType,
            typename ReturnType>
  inline Event<SenderType, ArgsType, ReturnType>&
  Event<SenderType, ArgsType, ReturnType>::operator+= (HandlerType handler)
  {
    sig_.connect (handler);

    return *this;
  }

  template <typename SenderType,
            typename ArgsType,
            typename ReturnType>
  inline void Event<SenderType, ArgsType, ReturnType>::AddHandler (
    const String& name,
    HandlerType handler)
  {
    handlers_.Add (
      name,
      std::shared_ptr<ConnectionType> (
        new ConnectionType (
          sig_.connect (handler))));
  }

  template <typename SenderType,
            typename ArgsType,
            typename ReturnType>
  inline void Event<SenderType, ArgsType, ReturnType>::RemoveHandler (
    const String& name)
  {
    handlers_.Remove (name);
  }

  template <typename SenderType,
            typename ArgsType,
            typename ReturnType>
  inline ReturnType
  Event<SenderType, ArgsType, ReturnType>::operator() (
    SenderType sender,
    ArgsType args)
  {
    return sig_ (sender, args);
  }
} // namespace yap

#endif // YAPOG_EVENT_HXX
