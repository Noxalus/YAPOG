#include "YAPOG/System/Thread/Thread.hpp"

namespace yap
{
  Thread::Thread (WorkerType worker)
    : thread_ (worker)
  {
  }

  void Thread::Launch ()
  {
    thread_.launch ();
  }

  void Thread::Stop ()
  {
    thread_.terminate ();
  }

  void Thread::Wait ()
  {
    thread_.wait ();
  }

  void Thread::Sleep (const Time& dt)
  {
    sf::sleep (sf::seconds (dt.GetValue ()));
  }
} // namespace yap
