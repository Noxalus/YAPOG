#ifndef YAPOG_THREAD_HXX
# define YAPOG_THREAD_HXX

namespace yap
{
  template <typename FunctionType, typename ArgsType>
  inline Thread::Thread (FunctionType function, ArgsType args)
    : thread_ (function, args)
  {
  }
} // namespace yap

#endif // YAPOG_THREAD_HXX
