#ifndef YAPOG_MOVECONTROLLER_HPP
# define YAPOG_MOVECONTROLLER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct ISpatial;
  class Vector2;
  class Time;

  /// @brief A class to move a spatial element from a point A to a point B
  class YAPOG_LIB MoveController
  {
    DISALLOW_COPY(MoveController);

  public:

    MoveController (
      ISpatial& element, 
      const Vector2& startPosition, 
      const Vector2& endPosition,
      const Time& time
      );

    ~MoveController ();

    bool Update (const yap::Time& dt);

  private:
    ISpatial& element_;
    Vector2 startPosition_;
    Vector2 endPosition_;
    Time time_;
    Time elapsedTime_;
    float progression_;
  };
} // namespace yap

#endif // YAPOG_MOVECONTROLLER_HPP
