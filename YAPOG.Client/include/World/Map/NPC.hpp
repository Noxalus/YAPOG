#ifndef YAPOG_CLIENT_NPC_HPP
# define YAPOG_CLIENT_NPC_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/INPC.hpp"

# include "World/Map/Character.hpp"

namespace ycl
{
  class NPC : public Character
            , public yap::INPC
  {
      DISALLOW_ASSIGN(NPC);

    public:

      NPC (const yap::ID& id);
      virtual ~NPC ();

      /// @name ICloneable members.
      /// @{
      virtual NPC* Clone () const;
      /// @}

      /// @name IDialogActor members.
      /// @{
      virtual const yap::String& GetName () const;

      virtual void Talk (yap::IDialogActor& dialogActor);
      /// @}

      /// @name INPC members.
      /// @{
      virtual void Accept (yap::IDynamicWorldObjectVisitor& visitor);
      virtual void Accept (
        yap::IDynamicWorldObjectConstVisitor& visitor) const;
      /// @}

    protected:

      NPC (const NPC& copy);

      virtual const yap::String& GetObjectFactoryTypeName () const;

    private:

      static const yap::String OBJECT_FACTORY_TYPE_NAME;

      static const yap::String DEFAULT_NAME;

      yap::String name_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_NPC_HPP
