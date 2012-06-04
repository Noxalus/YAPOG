#ifndef YAPOG_SERVER_NPC_HPP
# define YAPOG_SERVER_NPC_HPP

# include "YAPOG/Macros.hpp"
# include "World/Map/Character.hpp"

namespace yse
{
  class NPC : public Character
  {
      DISALLOW_ASSIGN(NPC);

    public:

      explicit NPC (const yap::ID& id);
      virtual ~NPC ();

      /// @name ICloneable members.
      /// @{
      virtual NPC* Clone () const;
      /// @}

    protected:

      NPC (const NPC& copy);

      const yap::String& GetObjectFactoryTypeName () const;

    private:

      static const yap::String OBJECT_FACTORY_TYPE_NAME;
  };
} // namespace yse

#endif // YAPOG_SERVER_NPC_HPP
