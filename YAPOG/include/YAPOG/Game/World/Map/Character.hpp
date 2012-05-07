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

    protected:

      explicit Character (const ID& id);

      Character (const Character& copy);

      void SetDirection (Direction direction);

      virtual void HandleMove (const Vector2& offset);

      virtual void HandleSetDirection (Direction direction);

    private:

      void UpdateDirection (const Vector2& offset);

      Direction direction_;
  };
} // namespace yap

#endif // YAPOG_CHARACTER_HPP
