#ifndef YAPOG_OBJECTFACTORY_HXX
# define YAPOG_OBJECTFACTORY_HXX

# include "YAPOG/Game/Factory/ILoader.hpp"
# include "YAPOG/Game/Factory/ILoadable.hpp"

namespace yap
{
  template <typename T>
  inline T* ObjectFactory::Create (const String& typeName, const ID& id)
  {
    return static_cast<T*> (loaders_[typeName]->Load (id)->Clone ());
  }
} // namespace yap

#endif // YAPOG_OBJECTFACTORY_HXX
