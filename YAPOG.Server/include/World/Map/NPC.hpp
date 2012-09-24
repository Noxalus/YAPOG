#ifndef YAPOG_SERVER_NPC_HPP
# define YAPOG_SERVER_NPC_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/INPC.hpp"

# include "World/Map/Character.hpp"

namespace yap
{
  struct IDialogNode;
} // namespace yap

namespace yse
{
  class NPC : public Character
            , public yap::INPC
  {
      DISALLOW_ASSIGN(NPC);

    public:

      explicit NPC (const yap::ID& id);
      virtual ~NPC ();

      void SetTalkEventArea (yap::BoundingBox* boundingBox);

      void SetDialogNode (yap::IDialogNode* dialogNode);

      /// @name ICloneable members.
      /// @{
      virtual NPC* Clone () const;
      /// @}

      /// @name IDialogActor members.
      /// @{
      virtual const yap::String& GetName () const;

      virtual const yap::ID& GetWorldID () const;

      virtual bool CanTalk (yap::IDialogActor& dialogActor) const;

      virtual void Talk (yap::IDialogActor& dialogActor);

      virtual bool TryStartDialog (yap::IDialogManager& dialogManager);
      /// @}

      /// @name INPC members.
      /// @{
      virtual void Accept (yap::IDynamicWorldObjectVisitor& visitor);
      virtual void Accept (
        yap::IDynamicWorldObjectConstVisitor& visitor) const;
      /// @}

    protected:

      NPC (const NPC& copy);

      const yap::String& GetObjectFactoryTypeName () const;

    private:

      static const yap::String OBJECT_FACTORY_TYPE_NAME;

      static const yap::String DEFAULT_NAME;

      yap::String name_;

      yap::IDialogNode* dialogNode_;

      yap::BoundingBox* talkEventArea_;
  };
} // namespace yse

#endif // YAPOG_SERVER_NPC_HPP
