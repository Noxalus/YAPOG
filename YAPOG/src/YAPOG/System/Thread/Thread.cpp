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
} // namespace yap
