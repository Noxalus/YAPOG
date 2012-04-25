#ifndef YAPOG_XMLOBJECTIDLOADER_HPP
# define YAPOG_XMLOBJECTIDLOADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/IObjectIDLoader.hpp"
# include "YAPOG/Content/ContentManager.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/Path.hpp"

namespace yap
{
  template <typename T, typename TXmlReader>
  class YAPOG_LIB XmlObjectIDLoader : public IObjectIDLoader
  {
      DISALLOW_COPY(XmlObjectIDLoader);

    public:

      typedef T LoadedType;
      typedef TXmlReader XmlReaderType;

      XmlObjectIDLoader (const Path& rootPath, const String& rootNodeName);
      virtual ~XmlObjectIDLoader ();

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

# include "YAPOG/Game/Factory/XmlObjectIDLoader.hxx"

#endif // YAPOG_XMLOBJECTIDLOADER_HPP
