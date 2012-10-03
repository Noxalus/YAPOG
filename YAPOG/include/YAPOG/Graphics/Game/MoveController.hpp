#ifndef YAPOG_MOVECONTROLLER_HPP
# define YAPOG_MOVECONTROLLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/System/Time/Time.hpp"

namespace yap
{
  struct ISpatial;

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

    /// @name Getters.
    /// @{
    ISpatial& GetElement ();
    /// @}

    /// @name Setters.
    /// @{
    void SetStartPosition (const yap::Vector2& value);
    void SetEndPosition (const yap::Vector2& value);
    void SetTime (const yap::Time& value);
    /// @}

    bool Update (const yap::Time& dt);

  private:
    void Reset ();

    ISpatial& element_;
    Vector2 startPosition_;
    Vector2 endPosition_;
    Time time_;
    Time elapsedTime_;
    float progression_;
  };
} // namespace yap

#endif // YAPOG_MOVECONTROLLER_HPP
