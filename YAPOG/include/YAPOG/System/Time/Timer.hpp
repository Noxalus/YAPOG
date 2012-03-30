#ifndef YAPOG_TIMER_HPP
# define YAPOG_TIMER_HPP

# include <SFML/System/Clock.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Time/Time.hpp"

namespace yap
{
  class YAPOG_LIB Timer
  {
    public:

      Timer ();
      Timer (const Time& init);

      void Reset ();
      void Reset (const Time& init);

      Time GetCurrentTime () const;
      int DelayIsComplete (const Time& delay, bool reset);

    private:

      sf::Clock clock_;
      Time init_;
  };
} // namespace yap

#endif // YAPOG_TIMER_HPP
