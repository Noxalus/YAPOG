#ifndef YAPOG_OBJECTFACTORY_HXX
# define YAPOG_OBJECTFACTORY_HXX

namespace yap
{
  template <typename T>
  inline T* ObjectFactory::Create (const String& typeName, const ID& id)
  {
    return loaders_[typeName]->Load (id);
  }
} // namespace yap

#endif // YAPOG_OBJECTFACTORY_HXX
