#ifndef YAPOG_SERVER_TELEPORTER_HPP
# define YAPOG_SERVER_TELEPORTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Teleporter.hpp"

namespace yse
{
  struct IDynamicWorldObjectVisitor;
  struct IDynamicWorldObjectConstVisitor;

  class Teleporter : public yap::Teleporter
  {
      DISALLOW_ASSIGN(Teleporter);

    public:

      explicit Teleporter (const yap::ID& id);
      virtual ~Teleporter ();

      void Init (
        const yap::ID& mapWorldID,
        const yap::Vector2& mapPoint,
        const yap::FloatRect& area);

      /// @name ICloneable members.
      /// @{
      virtual Teleporter* Clone () const;
      /// @}

    protected:

      Teleporter (const Teleporter& copy);

      virtual const yap::String& GetObjectFactoryTypeName () const;

    private:

      static const yap::String OBJECT_FACTORY_TYPE_NAME;
  };
} // namespace yse

#endif // YAPOG_SERVER_TELEPORTER_HPP
