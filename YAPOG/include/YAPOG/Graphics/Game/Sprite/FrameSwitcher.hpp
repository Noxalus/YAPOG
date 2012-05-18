#ifndef YAPOG_FRAMESWITCHER_HPP
# define YAPOG_FRAMESWITCHER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/ICloneable.hpp"

namespace yap
{
  class Time;

  class YAPOG_LIB FrameSwitcher : public ICloneable
  {
      DISALLOW_ASSIGN(FrameSwitcher);

    public:

      virtual ~FrameSwitcher ();

      /// @brief Indicates how many frames have to be switched.
      int FrameIsOver (const Time& dt);

      /// @name ICloneable members.
      /// @{
      virtual FrameSwitcher* Clone () const = 0;
      /// @}

    protected:

      FrameSwitcher ();

    private:

      virtual int HandleFrameIsOver (const Time& dt) = 0;
  };
} // namespace yap

#endif // YAPOG_FRAMESWITCHER_HPP
