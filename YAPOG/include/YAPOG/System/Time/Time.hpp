#ifndef YAPOG_TIME_HPP
# define YAPOG_TIME_HPP

# include <SFML/System/Time.hpp>

# include "YAPOG/Macros.hpp"

namespace yap
{
  class YAPOG_LIB Time
  {
    public:

      Time ();
      Time (float seconds);
      Time (const sf::Time& copy);

      Time operator+ (const Time& rhs);
      Time operator+ (float rhs);
      Time operator- (const Time& rhs);
      Time operator- (float rhs);

      Time& operator+= (const Time& rhs);
      Time& operator+= (float rhs);
      Time& operator-= (const Time& rhs);
      Time& operator-= (float rhs);

      float GetValue () const;

    private:

      sf::Time value_;
  };
} // namespace yap

#endif // YAPOG_TIME_HPP
