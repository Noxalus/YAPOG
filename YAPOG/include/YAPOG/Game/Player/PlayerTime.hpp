#ifndef YAPOG_PLAYERTIME_HPP
# define YAPOG_PLAYERTIME_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Time/Time.hpp"

namespace yap
{
  class YAPOG_LIB PlayerTime
  {
  public:
    PlayerTime ();

    void UpdateTime (const Time& dt); 

    /// Getters.
    /// {
    const Time& GetPlayTime () const;
    const Time& GetCurrentSessionTime () const;
    /// }

    /// Setters.
    /// {
    void RawSetPlayTime (const Time& value);
    /// }

  private:
    Time playTime_;
    Time currentSessionTime_;
  };
} // namespace yap

#endif // YAPOG_PLAYERTIME_HPP
