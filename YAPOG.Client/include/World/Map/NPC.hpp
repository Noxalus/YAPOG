#ifndef YAPOG_CLIENT_NPC_HPP
# define YAPOG_CLIENT_NPC_HPP

# include "YAPOG/Macros.hpp"
# include "World/Map/Character.hpp"

namespace ycl
{
  class NPC : public Character
  {
      DISALLOW_ASSIGN(NPC);

    public:

      NPC (const yap::ID& id);
      virtual ~NPC ();

      /// @name ICloneable members.
      /// @{
      virtual NPC* Clone () const;
      /// @}

    protected:

      NPC (const NPC& copy);

      virtual yap::String GetObjectFactoryTypeName () const;

    private:

      static const yap::String OBJECT_FACTORY_TYPE_NAME;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_NPC_HPP
