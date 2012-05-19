#ifndef YAPOG_XMLOBJECTLOADER_HPP
# define YAPOG_XMLOBJECTLOADER_HPP

# define DLLEXPORT

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  template <typename T, typename TXmlReader>
  class XmlObjectLoader : public IObjectLoader
  {
      DISALLOW_COPY(XmlObjectLoader);

    public:

      typedef T LoadedType;
      typedef TXmlReader XmlReaderType;

      XmlObjectLoader ();
      virtual ~XmlObjectLoader ();

      virtual T* Load (IReader& reader, const String& rootNodeName);
  };
} // namespace yap

# include "YAPOG/Game/Factory/XmlObjectLoader.hxx"

#endif // YAPOG_XMLOBJECTLOADER_HPP
