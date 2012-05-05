#ifndef YAPOG_CHARACTERPHYSICSINFO_HPP
# define YAPOG_CHARACTERPHYSICSINFO_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/WorldObjectPhysicsInfo.hpp"

namespace yap
{
  class YAPOG_LIB CharacterPhysicsInfo : public WorldObjectPhysicsInfo
  {
      DISALLOW_ASSIGN(CharacterPhysicsInfo);

    public:

      CharacterPhysicsInfo ();
      virtual ~CharacterPhysicsInfo ();

      virtual CharacterPhysicsInfo* Clone () const;

    protected:

      CharacterPhysicsInfo (const CharacterPhysicsInfo& copy);
  };
} // namespace yap

#endif // YAPOG_CHARACTERPHYSICSINFO_HPP
