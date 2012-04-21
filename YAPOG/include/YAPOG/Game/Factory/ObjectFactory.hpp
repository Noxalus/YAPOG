#ifndef YAPOG_OBJECTFACTORY_HPP
# define YAPOG_OBJECTFACTORY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  struct ILoader;

  class ID;

  class ObjectFactory
  {
      DISALLOW_COPY(ObjectFactory);

    public:

      static ObjectFactory& Instance ();

      template <typename T>
      T* Create (const String& typeName, const ID& id);

      void RegisterLoader (const String& typeName, ILoader* loader);

    private:

      ObjectFactory ();
      ~ObjectFactory ();

      collection::Map<String, ILoader*> loaders_;
  };
} // namespace yap

# include "YAPOG/Game/Factory/ObjectFactory.hxx"

#endif // YAPOG_OBJECTFACTORY_HPP
