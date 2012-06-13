#ifndef YAPOG_SERVER_DYNAMICOBJECTFACTORY_HPP
# define YAPOG_SERVER_DYNAMICOBJECTFACTORY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yse
{
  class DynamicObjectFactory
  {
      DISALLOW_COPY(DynamicObjectFactory);

    public:

      static DynamicObjectFactory& Instance ();

      template <typename T>
      T* Create (const yap::String& typeName, const yap::ID& id) const;

    private:

      DynamicObjectFactory ();
      ~DynamicObjectFactory ();
  };
} // namespace yse

# include "World/Map/DynamicObjectFactory.hxx"

#endif // YAPOG_SERVER_DYNAMICOBJECTFACTORY_HPP
