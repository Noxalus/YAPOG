#ifndef YAPOG_THREAD_HPP
# define YAPOG_THREAD_HPP

# include <functional>

# include <SFML/System.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Time/Time.hpp"

# define MEMBER_WORKER(MEMBER)                          \
  std::bind (&MEMBER, this, std::placeholders::_1)

namespace yap
{
  typedef sf::Mutex Mutex;
  typedef sf::Lock Lock;

  class YAPOG_LIB Thread
  {
      DISALLOW_COPY(Thread);

    public:

      typedef std::function<void (void)> WorkerType;

      explicit Thread (WorkerType worker);

      template <typename FunctionType, typename ArgsType>
      Thread (FunctionType function, ArgsType args);

      void Launch ();
      void Stop ();

      void Wait ();

      static void Sleep (const Time& delay);

    private:

      sf::Thread thread_;
  };
} // namespace yap

# include "YAPOG/System/Thread/Thread.hxx"

#endif // YAPOG_THREAD_HPP
