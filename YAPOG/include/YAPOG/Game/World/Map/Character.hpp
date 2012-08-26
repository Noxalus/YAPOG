#ifndef YAPOG_CHARACTER_HPP
# define YAPOG_CHARACTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
# include "YAPOG/Game/World/Map/Direction.hpp"

namespace yap
{
  class YAPOG_LIB Character : public DynamicWorldObject
  {
      DISALLOW_ASSIGN(Character);

    public:

      virtual ~Character ();

      virtual void Accept (IDynamicWorldObjectVisitor& visitor);
      virtual void Accept (IDynamicWorldObjectConstVisitor& visitor) const;

      const Direction& GetDirection () const;

      void RawSetDirection (Direction direction);

    protected:

      explicit Character (const ID& id);

      Character (const Character& copy);

      void SetDirection (Direction direction);

      virtual void HandleSetDirection (Direction direction);

      virtual void HandleOnVelocityChanged (
        const Vector2& oldVelocity,
        const Vector2& currentVelocity);

    private:

      void UpdateDirection (const Vector2& offset);

      static const Direction DEFAULT_DIRECTION;

      Direction direction_;
  };
} // namespace yap

#endif // YAPOG_CHARACTER_HPP
