#ifndef YAPOG_CHARACTER_HPP
# define YAPOG_CHARACTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
# include "YAPOG/Game/World/Map/CharacterPhysicsInfo.hpp"

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

    private:

      virtual void InitPhysicsInfo ();
  };
} // namespace yap

#endif // YAPOG_CHARACTER_HPP
