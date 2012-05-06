#ifndef YAPOG_DELAYEDFRAMESWITCHER_HPP
# define YAPOG_DELAYEDFRAMESWITCHER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/FrameSwitcher.hpp"
# include "YAPOG/System/Time/Time.hpp"
# include "YAPOG/System/Time/UpdateableTimer.hpp"

namespace yap
{
  class YAPOG_LIB DelayedFrameSwitcher : public FrameSwitcher
  {
      DISALLOW_ASSIGN(DelayedFrameSwitcher);

    public:

      explicit DelayedFrameSwitcher (const Time& delay);
      virtual ~DelayedFrameSwitcher ();

      /// @name ICloneable members.
      /// @{
      virtual DelayedFrameSwitcher* Clone () const;
      /// @}

    protected:

      DelayedFrameSwitcher (const DelayedFrameSwitcher& copy);

    private:

      virtual int HandleFrameIsOver (const Time& dt);

      Time delay_;
      UpdateableTimer timer_;
  };
} // namespace yap

#endif // YAPOG_DELAYEDFRAMESWITCHER_HPP
