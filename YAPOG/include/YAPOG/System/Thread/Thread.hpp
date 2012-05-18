#ifndef YAPOG_THREAD_HPP
# define YAPOG_THREAD_HPP

# include <functional>

# include <SFML/System/Thread.hpp>

# include "YAPOG/Macros.hpp"

namespace yap
{
  class YAPOG_LIB Thread
  {
      DISALLOW_COPY(Thread);

    public:

      typedef std::function<void (void)> WorkerType;

      Thread (WorkerType worker);

      void Launch ();
      void Stop ();

      void Wait ();

    private:

      sf::Thread thread_;
  };
} // namespace yap

#endif // YAPOG_THREAD_HPP
