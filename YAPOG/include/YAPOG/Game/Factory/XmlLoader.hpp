#ifndef YAPOG_XMLLOADER_HPP
# define YAPOG_XMLLOADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/IGenLoader.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/Path.hpp"

namespace yap
{
  template <typename T, typename TXmlReader>
  class XmlLoader : public IGenLoader<T>
  {
      DISALLOW_COPY(XmlLoader);

    public:

      typedef T LoadedType;
      typedef TXmlReader XmlReaderType;

      XmlLoader (
        const Path& rootPath,
        const String& rootNodeName);
      virtual ~XmlLoader ();

      virtual T* Load (const ID& id);

    private:

      T& GetObject (const ID& id);

      const Path rootPath_;
      const String rootNodeName_;

      collection::Map<ID, T*> objects_;
      ID currentID_;
      T* currentObject_;
  };
} // namespace yap

# include "YAPOG/Game/Factory/XmlLoader.hxx"

#endif // YAPOG_XMLLOADER_HPP
