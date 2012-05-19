#ifndef YAPOG_XMLOBJECTLOADER_HXX
# define YAPOG_XMLOBJECTLOADER_HXX

namespace yap
{
  template <typename T, typename TXmlReader>
  inline XmlObjectLoader<T, TXmlReader>::XmlObjectLoader ()
  {
  }

  template <typename T, typename TXmlReader>
  inline XmlObjectLoader<T, TXmlReader>::~XmlObjectLoader ()
  {
  }

  template <typename T, typename TXmlReader>
  inline T* XmlObjectLoader<T, TXmlReader>::Load (
    IReader& reader,
    const String& rootNodeName)
  {
    T* object = new T ();

    TXmlReader objectReader (*object, rootNodeName);
    reader.Accept (objectReader);

    return object;
  }
} // namespace yap

#endif // YAPOG_XMLOBJECTLOADER_HXX
