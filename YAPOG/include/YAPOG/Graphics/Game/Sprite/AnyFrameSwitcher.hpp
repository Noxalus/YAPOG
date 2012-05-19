#ifndef YAPOG_ANYFRAMESWITCHER_HPP
# define YAPOG_ANYFRAMESWITCHER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/FrameSwitcher.hpp"

namespace yap
{
  /// @brief Switches to the next frame at each game loop cycle.
  class YAPOG_LIB AnyFrameSwitcher : public FrameSwitcher
  {
      DISALLOW_ASSIGN(AnyFrameSwitcher);

    public:

      AnyFrameSwitcher ();
      explicit AnyFrameSwitcher (int switchCount);
      virtual ~AnyFrameSwitcher ();

      /// @name ICloneable members.
      /// @{
      virtual AnyFrameSwitcher* Clone () const;
      /// @}

    protected:

      AnyFrameSwitcher (const AnyFrameSwitcher& copy);

    private:

      virtual int HandleFrameIsOver (const Time& dt);

      static const int DEFAULT_SWITCH_COUNT;

      int switchCount_;
  };
} // namespace yap

#endif // YAPOG_ANYFRAMESWITCHER_HPP
