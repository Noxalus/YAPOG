#ifndef YAPOG_WORLDOBJECTMOVECONTROLLER_HPP
# define YAPOG_WORLDOBJECTMOVECONTROLLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class DynamicWorldObject;

  class YAPOG_LIB WorldObjectMoveController
  {
      DISALLOW_COPY(WorldObjectMoveController);

    public:

      virtual ~WorldObjectMoveController ();

      const Vector2& GetForce () const;

      void SetValue (const Vector2& value);

    protected:

      WorldObjectMoveController ();

      Vector2 force_;
      Vector2 value_;

    private:

      static const Vector2 DEFAULT_VALUE;
  };
} // namespace yap

#endif // YAPOG_WORLDOBJECTMOVECONTROLLER_HPP
