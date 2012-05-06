#ifndef YAPOG_WORLDOBJECTSTATEFACTORY_HPP
# define YAPOG_WORLDOBJECTSTATEFACTORY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  class WorldObjectStateFactory
  {
      DISALLOW_COPY(WorldObjectStateFactory);

    public:

      class WorldObjectStateInfo
      {
          DISALLOW_COPY(WorldObjectStateInfo);

        public:

          WorldObjectStateInfo (const String& name, const String& logicalName);

          const String& GetName () const;
          const String& GetLogicalName () const;
          bool IsJoinedTo (const String& state) const;

          void AddJoin (const String& join);

        private:

          String name_;
          String logicalName_;

          collection::List<String> joins_;
      };

      static WorldObjectStateFactory& Instance ();

      void AddState (const String& state, const String& logicalState);
      void AddJoin (const String& state, const String& join);

      WorldObjectStateInfo& GetState (const String& state);

    private:

      WorldObjectStateFactory ();
      ~WorldObjectStateFactory ();

      collection::Map<String, WorldObjectStateInfo*> states_;
  };
} // namespace yap

#endif // YAPOG_WORLDOBJECTSTATEFACTORY_HPP
