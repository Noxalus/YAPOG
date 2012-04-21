#ifndef YAPOG_XMLLOADER_HXX
# define YAPOG_XMLLOADER_HXX

namespace yap
{
  template <typename T>
  inline XmlLoader::XmlLoader (
    const Path& pathRoot,
    const String& rootNodeName)
    : pathRoot_ (pathRoot)
    , rootNodeName_ (rootNodeName)
    , objects_ ()
    , currentID_ ()
    , currentObject_ (nullptr)
  {
  }

  template <typename T>
  inline XmlLoader::~XmlLoader ()
  {
    for (const auto& it : objects_)
      delete it.second;
  }

  template <typename T>
  inline T* XmlLoader::Load (const ID& id)
  {
    if (objects_.Contains (id))
      return objects_[id];

    T* object = HandleLoad (id);
    objects_.Add (id, object);

    return object;
  }

  template <typename T>
  inline T& XmlLoader::GetObject (const ID& id)
  {
    if (currentID_ != id)
    {
      currentID_ = id;
      currentObject_ = objects_[currentID_];
    }

    return *currentObject_;
  }
} // namespace yap

#endif // YAPOG_XMLLOADER_HXX
