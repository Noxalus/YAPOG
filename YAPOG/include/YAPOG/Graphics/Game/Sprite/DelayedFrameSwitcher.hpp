#ifndef YAPOG_DELAYEDFRAMESWITCHER_HPP
# define YAPOG_DELAYEDFRAMESWITCHER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/FrameSwitcher.hpp"
# include "YAPOG/System/Time/Time.hpp"
# include "YAPOG/System/Time/UpdateableTimer.hpp"

namespace yap
{
  class DelayedFrameSwitcher : public FrameSwitcher
  {
      DISALLOW_COPY(DelayedFrameSwitcher);

    public:

      explicit DelayedFrameSwitcher (const Time& delay);
      virtual ~DelayedFrameSwitcher ();

    private:

      virtual int HandleFrameIsOver (const Time& dt);

      Time delay_;
      UpdateableTimer timer_;
  };
} // namespace yap

#endif // YAPOG_DELAYEDFRAMESWITCHER_HPP
