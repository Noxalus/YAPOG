#ifndef YAPOG_OPENBATTLESPAWNERAREA_HPP
# define YAPOG_OPENBATTLESPAWNERAREA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/BattleSpawnerArea.hpp"

namespace yap
{
  class OpenBattleSpawnerArea : public BattleSpawnerArea
  {
      DISALLOW_ASSIGN(OpenBattleSpawnerArea);

    public:

      explicit OpenBattleSpawnerArea (const ID& id);

      virtual ~OpenBattleSpawnerArea ();

      virtual void Accept (IDynamicWorldObjectVisitor& visitor);
      virtual void Accept (IDynamicWorldObjectConstVisitor& visitor) const;

      /// @name ICloneable members.
      /// @{
      virtual OpenBattleSpawnerArea* Clone () const;
      /// @}

    protected:

      OpenBattleSpawnerArea (const OpenBattleSpawnerArea& copy);

      virtual void HandleSetArea (const FloatRect& area);

      virtual const String& GetObjectFactoryTypeName () const;

    private:

      static const String OBJECT_FACTORY_TYPE_NAME;
  };
} // namespace yap

#endif // YAPOG_OPENBATTLESPAWNERAREA_HPP
