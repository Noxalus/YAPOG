#ifndef YAPOG_DYNAMICWORLDOBJECTCOLLECTION_HPP
# define YAPOG_DYNAMICWORLDOBJECTCOLLECTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yap
{
  class DynamicWorldObject;

  class YAPOG_LIB DynamicWorldObjectCollection : public IUpdateable
  {
      DISALLOW_COPY(DynamicWorldObjectCollection);

      typedef collection::Map<ID, DynamicWorldObject*> InnerCollectionType;
      typedef InnerCollectionType::SizeType SizeType;
      typedef InnerCollectionType::ItType ItType;
      typedef InnerCollectionType::ConstItType ConstItType;

    public:

      DynamicWorldObjectCollection ();
      ~DynamicWorldObjectCollection ();

      ItType begin ();
      ConstItType begin () const;
      ItType end ();
      ConstItType end () const;

      SizeType Count () const;

      void AddObject (DynamicWorldObject* object);
      void RemoveObject (const ID& worldID);
      DynamicWorldObject& GetObject (const ID& worldID);

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    private:

      collection::Map<ID, DynamicWorldObject*> objects_;
  };
} // namespace yap

#endif // YAPOG_DYNAMICWORLDOBJECTCOLLECTION_HPP
