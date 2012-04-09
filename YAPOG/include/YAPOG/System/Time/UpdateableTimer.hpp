#ifndef YAPOG_UPDATEABLETIMER_HPP
# define YAPOG_UPDATEABLETIMER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Time/Time.hpp"

namespace yap
{
  class YAPOG_LIB UpdateableTimer
  {
      DISALLOW_COPY(UpdateableTimer);

    public:

      UpdateableTimer ();
      UpdateableTimer (const Time& initTime);

      void Update (const Time& dt);

      void Reset ();
      void Reset (const Time& init);

      const Time& GetCurrentTime () const;
      int DelayIsComplete (const Time& delay, bool reset);

    private:

      Time currentTime_;
  };
} // namespace yap

#endif // YAPOG_UPDATEABLETIMER_HPP
