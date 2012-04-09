#ifndef YAPOG_FRAMESWITCHER_HPP
# define YAPOG_FRAMESWITCHER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class Time;

  class YAPOG_LIB FrameSwitcher
  {
      DISALLOW_COPY(FrameSwitcher);

    public:

      virtual ~FrameSwitcher ();

      /// @brief Indicates how many frames have to be switched.
      int FrameIsOver (const Time& dt);

    protected:

      FrameSwitcher ();

    private:

      virtual int HandleFrameIsOver (const Time& dt) = 0;
  };
} // namespace yap

#endif // YAPOG_FRAMESWITCHER_HPP
