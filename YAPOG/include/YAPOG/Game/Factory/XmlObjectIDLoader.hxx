#ifndef YAPOG_XMLOBJECTIDLOADER_HXX
# define YAPOG_XMLOBJECTIDLOADER_HXX

# include "YAPOG/Content/ContentManager.hpp"
# include "YAPOG/System/IO/Xml/XmlReader.hpp"

namespace yap
{
  template <typename T, typename TXmlReader>
  inline XmlObjectIDLoader<T, TXmlReader>::XmlObjectIDLoader (
    const Path& rootPath,
    const String& rootNodeName)
    : rootPath_ (rootPath)
    , rootNodeName_ (rootNodeName)
    , objects_ ()
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
    T** objectPtr = objects_.TryGetValue (id);

    if (objectPtr != nullptr)
      return *objectPtr;

    T* object = new T (id);
    objects_.Add (id, object);

    IFStream file;
    ContentManager::Instance ().LoadFile (rootPath_, id, file);

    XmlReader xmlReader (file, rootNodeName_);
    TXmlReader objectReader (*object, rootNodeName_);
    xmlReader.Accept (objectReader);

    return object;
  }

  template <typename T, typename TXmlReader>
  inline const T& XmlObjectIDLoader<T, TXmlReader>::GetObject (
    const ID& id) const
  {
    return *objects_[id];
  }
} // namespace yap

#endif // YAPOG_XMLOBJECTIDLOADER_HXX
