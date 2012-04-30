#ifndef YAPOG_CHARACTER_HPP
# define YAPOG_CHARACTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
# include "YAPOG/Game/World/Map/CharacterPhysicsInfo.hpp"

namespace yap
{
  class Character : public DynamicWorldObject
  {
      DISALLOW_ASSIGN(Character);

    public:

      virtual ~Character ();

    protected:

      explicit Character (const ID& id);

      Character (const Character& copy);

    private:

      virtual CharacterPhysicsInfo& GetPhysicsInfo ();

      CharacterPhysicsInfo physicsInfo_;
  };
} // namespace yap

#endif // YAPOG_CHARACTER_HPP
