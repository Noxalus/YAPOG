#ifndef YAPOG_ANYFRAMESWITCHER_HPP
# define YAPOG_ANYFRAMESWITCHER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/FrameSwitcher.hpp"

namespace yap
{
  /// @brief Switches to the next frame at each game loop cycle.
  class AnyFrameSwitcher : public FrameSwitcher
  {
    public:

      AnyFrameSwitcher ();
      explicit AnyFrameSwitcher (int switchCount);
      virtual ~AnyFrameSwitcher ();

    private:

      virtual int FrameIsOver (const Time& dt);

      static const int DEFAULT_SWITCH_COUNT;

      int switchCount_;
  };
} // namespace yap

#endif // YAPOG_ANYFRAMESWITCHER_HPP
