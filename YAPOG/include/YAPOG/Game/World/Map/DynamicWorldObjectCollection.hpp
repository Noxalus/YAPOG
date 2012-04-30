#ifndef YAPOG_DYNAMICWORLDOBJECTCOLLECTION_HPP
# define YAPOG_DYNAMICWORLDOBJECTCOLLECTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yap
{
  class DynamicWorldObject;

  class DynamicWorldObjectCollection : public IUpdateable
  {
      DISALLOW_COPY(DynamicWorldObjectCollection);

      typedef collection::Map<ID, DynamicWorldObject*>::ItType ItType;
      typedef collection::Map<
        ID,
        DynamicWorldObject*>::ConstItType ConstItType;

    public:

      DynamicWorldObjectCollection ();
      ~DynamicWorldObjectCollection ();

      ItType begin ();
      ConstItType begin () const;
      ItType end ();
      ConstItType end () const;

      void AddObject (DynamicWorldObject* object);
      DynamicWorldObject& GetObject (const ID& id);

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    private:

      collection::Map<ID, DynamicWorldObject*> objects_;
  };
} // namespace yap

#endif // YAPOG_DYNAMICWORLDOBJECTCOLLECTION_HPP
