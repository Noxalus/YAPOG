#ifndef YAPOG_EVENT_HXX
# define YAPOG_EVENT_HXX

namespace yap
{
  template<typename SenderType,
           typename ArgsType,
           typename ReturnType>
  Event<SenderType, ArgsType, ReturnType>::Event ()
    : sig_ ()
  {
  }

  template <typename SenderType,
            typename ArgsType,
            typename ReturnType>
  Event<SenderType, ArgsType, ReturnType>::~Event ()
  {
  }

  template <typename SenderType,
            typename ArgsType,
            typename ReturnType>
  Event<SenderType, ArgsType, ReturnType>&
  Event<SenderType, ArgsType, ReturnType>::operator+= (const Handler handler)
  {
    sig_.connect (handler);

    return *this;
  }

  template <typename SenderType,
            typename ArgsType,
            typename ReturnType>
  Event<SenderType, ArgsType, ReturnType>&
  Event<SenderType, ArgsType, ReturnType>::operator-= (const Handler handler)
  {
    sig_.disconnect (handler);

    return *this;
  }

  template <typename SenderType,
            typename ArgsType,
            typename ReturnType>
  ReturnType
  Event<SenderType, ArgsType, ReturnType>::operator() (SenderType sender,
                                                       ArgsType args)
  {
    return sig_ (sender, args);
  }
} // namespace yap

#endif // YAPOG_EVENT_HXX
