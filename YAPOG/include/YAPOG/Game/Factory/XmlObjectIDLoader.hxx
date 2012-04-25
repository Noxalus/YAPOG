#ifndef YAPOG_XMLOBJECTIDLOADER_HXX
# define YAPOG_XMLOBJECTIDLOADER_HXX

# include "YAPOG/Content/ContentManager.hpp"

namespace yap
{
  template <typename T, typename TXmlReader>
  inline XmlObjectIDLoader<T, TXmlReader>::XmlObjectIDLoader (
    const Path& rootPath,
    const String& rootNodeName)
    : rootPath_ (rootPath)
    , rootNodeName_ (rootNodeName)
    , objects_ ()
    , currentID_ ()
    , currentObject_ (nullptr)
  {
  }

  template <typename T, typename TXmlReader>
  inline XmlObjectIDLoader<T, TXmlReader>::~XmlObjectIDLoader ()
  {
    for (const auto& it : objects_)
      delete it.second;
  }

  template <typename T, typename TXmlReader>
  inline T* XmlObjectIDLoader<T, TXmlReader>::Load (const ID& id)
  {
    if (objects_.Contains (id))
      return objects_[id];

    T* object = new T (id);
    objects_.Add (id, object);

    IFStream file;
    ContentManager::Instance ().LoadFile (rootPath_, id, file);

    XmlReader xmlReader (file, rootNodeName_);
    TXmlReader objectReader (GetObject (id));
    xmlReader.Accept (objectReader);

    return object;
  }

  template <typename T, typename TXmlReader>
  inline T& XmlObjectIDLoader<T, TXmlReader>::GetObject (const ID& id)
  {
    if (currentID_ != id)
    {
      currentID_ = id;
      currentObject_ = objects_[currentID_];
    }

    return *currentObject_;
  }
} // namespace yap

#endif // YAPOG_XMLOBJECTIDLOADER_HXX
